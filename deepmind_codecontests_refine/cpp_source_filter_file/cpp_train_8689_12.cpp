#include <bits/stdc++.h>
using namespace std;
const int N = 23;
const int inf = 20000000;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, nrm, nrf, dist[N][N][N][N], mx[N * N], my[N * N], mt[N * N],
    fx[N * N], fy[N * N], ft[N * N];
char a[N][N];
bool ver[N][N];
void calcDist(int px, int py) {
  memset(ver, 0, sizeof(ver));
  queue<pair<int, int> > q;
  q.push(pair<int, int>(px, py));
  ver[px][py] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) dist[px][py][i][j] = inf;
  dist[px][py][px][py] = 0;
  while (!q.empty()) {
    int elx = q.front().first, ely = q.front().second;
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int nx = elx + dx[k], ny = ely + dy[k];
      if (!ver[nx][ny] && a[nx][ny] == '.') {
        ver[nx][ny] = 1;
        q.push(pair<int, int>(nx, ny));
        dist[px][py][nx][ny] = dist[px][py][elx][ely] + 1;
      }
    }
  }
}
const int NM = 2500;
int S = 0, D = NM - 1;
vector<int> v[NM], vini[NM];
int cap[NM][NM], flux[NM][NM], lastflux[NM][NM], lastcap[NM][NM];
struct mu {
  int x, y;
  long long cost;
};
vector<mu> edg;
void calc() {
  int i, j, k, nrn = 0;
  for (i = 1; i <= nrm; ++i) {
    v[S].push_back(i);
    v[i].push_back(S);
    cap[S][i] = 1;
  }
  for (i = 1; i <= nrf; ++i) {
    v[i + nrm].push_back(D);
    v[D].push_back(i + nrm);
    cap[i + nrm][D] = 1;
  }
  mu te;
  edg.push_back(te);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (a[i][j] == '.') {
        ++nrn;
        v[2 * nrm + nrn].push_back(NM - (2 * nrm + nrn));
        v[NM - (2 * nrm + nrn)].push_back(2 * nrm + nrn);
        cap[2 * nrm + nrn][NM - (2 * nrm + nrn)] = 1;
        for (k = 1; k <= nrm; ++k)
          if (dist[mx[k]][my[k]][i][j] != inf) {
            te.x = k;
            te.y = 2 * nrm + nrn;
            te.cost = 1LL * mt[k] * dist[mx[k]][my[k]][i][j];
            edg.push_back(te);
          }
        for (k = 1; k <= nrf; ++k)
          if (dist[i][j][fx[k]][fy[k]] != inf) {
            te.x = NM - (2 * nrm + nrn);
            te.y = nrm + k;
            te.cost = 1LL * ft[k] * dist[i][j][fx[k]][fy[k]];
            edg.push_back(te);
          }
      }
}
int pa[NM];
bool cmp(mu a, mu b) { return a.cost < b.cost; }
bool bf() {
  int i;
  queue<int> q;
  for (i = 0; i < NM; ++i) pa[i] = -1;
  pa[S] = 0;
  q.push(S);
  while (!q.empty()) {
    int el = q.front();
    q.pop();
    for (vector<int>::iterator it = v[el].begin(); it != v[el].end(); ++it)
      if (pa[*it] == -1 && cap[el][*it] - flux[el][*it] > 0) {
        pa[*it] = el;
        q.push(*it);
      }
  }
  return (pa[D] != -1);
}
int rez;
int fluxx() {
  int i, j, smin;
  while (bf()) {
    for (j = S; j < D; ++j)
      if (pa[j] != -1 && cap[j][D] - flux[j][D]) {
        smin = cap[j][D] - flux[j][D];
        for (i = j; i != S; i = pa[i])
          smin = min(smin, cap[pa[i]][i] - flux[pa[i]][i]);
        flux[j][D] += smin;
        flux[D][j] -= smin;
        rez += smin;
        for (i = j; i != S; i = pa[i]) {
          flux[pa[i]][i] += smin;
          flux[i][pa[i]] -= smin;
        }
      }
  }
  return rez;
}
const int SQR = 333;
void calcflux() {
  int i, j = 1, k;
  sort(edg.begin() + 1, edg.end(), cmp);
  for (i = 0; i < NM; ++i) {
    for (j = 0; j < NM; ++j) lastcap[i][j] = cap[i][j];
    for (k = 0; k < v[i].size(); ++k) vini[i].push_back(v[i][k]);
  }
  j = 1;
  int vv = 0;
  for (i = SQR; j < edg.size(); i += SQR) {
    while (j < edg.size() && i >= j) {
      v[edg[j].x].push_back(edg[j].y);
      v[edg[j].y].push_back(edg[j].x);
      cap[edg[j].x][edg[j].y] = 1;
      ++j;
    }
    if (fluxx() == nrm) {
      vv = 1;
      break;
    }
  }
  if (!vv) {
    cout << -1;
    return;
  }
  for (int ii = 0; ii < NM; ++ii)
    for (int jj = 0; jj < NM; ++jj) {
      cap[ii][jj] = lastcap[ii][jj];
      flux[ii][jj] = lastflux[ii][jj];
    }
  for (int ii = 0; ii < NM; ++ii) v[ii] = vini[ii];
  rez = 0;
  i -= SQR;
  for (j = 1; j <= i; ++j) {
    v[edg[j].x].push_back(edg[j].y);
    v[edg[j].y].push_back(edg[j].x);
    cap[edg[j].x][edg[j].y] = 1;
  }
  for (++i; i < edg.size(); ++i) {
    while (j < edg.size() && i >= j) {
      v[edg[j].x].push_back(edg[j].y);
      v[edg[j].y].push_back(edg[j].x);
      cap[edg[j].x][edg[j].y] = 1;
      ++j;
    }
    if (fluxx() == nrm) {
      cout << edg[j - 1].cost;
      return;
    }
  }
  cout << -1;
}
int main() {
  int i, j;
  cin >> n >> m >> nrm >> nrf;
  if (nrm != nrf + 1 && nrm != nrf - 1) {
    cout << -1;
    return 0;
  }
  for (i = 1; i <= n; ++i) cin >> (a[i] + 1);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (a[i][j] == '.') calcDist(i, j);
  int ttx, tty, ttt;
  cin >> ttx >> tty >> ttt;
  for (i = 1; i <= nrm; ++i) cin >> mx[i] >> my[i] >> mt[i];
  for (i = 1; i <= nrf; ++i) cin >> fx[i] >> fy[i] >> ft[i];
  if (nrm == nrf + 1) {
    fx[++nrf] = ttx;
    fy[nrf] = tty;
    ft[nrf] = ttt;
  } else {
    mx[++nrm] = ttx;
    my[nrm] = tty;
    mt[nrm] = ttt;
  }
  calc();
  calcflux();
  return 0;
}
