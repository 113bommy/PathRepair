#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1000 + 10, maxe = 500 * 1000 + 10,
          INF = 1 * 1000 * 1000 * 1000 + 10;
const long long OO = 10000000000000;
int TOTAL, ptr[maxn], dis[maxn], q[maxn], r, c, x, y, M[maxn], F[maxn], cnt, n,
    m, mls, fms, ecnt, cap[2 * maxe], frm[2 * maxe], to[2 * maxe],
    prv[2 * maxe], head[maxn], numm, numf, ted;
char ch;
pair<int, int> d[maxn][maxn];
long long s, f, mid;
bool mark[maxn], park[maxn], flg;
vector<int> vec[maxn], good;
struct hmn {
  int id;
  long long sp;
  hmn() { id = sp = -1; }
};
vector<hmn> ml, fm;
hmn tmp, boss;
inline void adde(int xx, int yy, int xy, int yx = 0) {
  frm[ecnt] = xx, to[ecnt] = yy, cap[ecnt] = xy, prv[ecnt] = head[xx];
  head[xx] = ecnt++;
  frm[ecnt] = yy, to[ecnt] = xx, cap[ecnt] = yx, prv[ecnt] = head[yy];
  head[yy] = ecnt++;
}
inline int ABS(int xx) {
  if (xx < 0) return -xx;
  return xx;
}
inline void floyd() {
  for (int k = 0; k < n * m; k++) {
    for (int i = 0; i < n * m; i++) {
      d[k][i].second = i;
      for (int j = 0; j < n * m; j++)
        d[i][j].first = min(d[i][j].first, d[i][k].first + d[k][j].first);
    }
  }
  for (int i = 0; i < n * m; i++) sort(d[i], d[i] + n * m);
}
inline void dfsr(int v) {
  ted++;
  mark[v] = 1;
  numm += M[v];
  numf += F[v];
  if (v == r * m + c) flg = 1;
  for (int i = 0; i < ((int(vec[v].size()))); i++) {
    if (!mark[vec[v][i]]) dfsr(vec[v][i]);
  }
}
inline bool bfs(int src, int snk) {
  memset(dis, 63, sizeof dis);
  int a = 0, b = 0, p;
  dis[src] = 0;
  q[b++] = src;
  while (a < b) {
    p = q[a++];
    for (int i = head[p]; i != -1; i = prv[i]) {
      if (cap[i] && dis[to[i]] > dis[p] + 1) {
        dis[to[i]] = dis[p] + 1;
        q[b++] = to[i];
      }
    }
  }
  return dis[snk] < INF;
}
int dfs(int xx, int snk, int ff = INF) {
  if (xx == snk) return ff;
  int ans = 0, a;
  for (; ptr[xx] != -1; ptr[xx] = prv[ptr[xx]]) {
    if (dis[xx] + 1 == dis[to[ptr[xx]]]) {
      a = dfs(to[ptr[xx]], snk, min(ff, cap[ptr[xx]]));
      cap[ptr[xx]] -= a;
      cap[ptr[xx] ^ 1] += a;
      ff -= a;
      ans += a;
      if (ff == 0) break;
    }
  }
  return ans;
}
inline int flow(int src, int snk) {
  int ff = 0;
  while (bfs(src, snk)) {
    memcpy(ptr, head, sizeof head);
    ff += dfs(src, snk);
  }
  return ff;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> mls >> fms;
  memset(d, 63, sizeof d);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++, cnt++) {
      cin >> ch;
      if (ch == '#') park[cnt] = 1;
      d[cnt][cnt].first = 0;
      if (!park[cnt]) good.push_back(cnt);
      if (i > 0 && !park[cnt] && !park[cnt - m]) {
        vec[cnt].push_back(cnt - m);
        vec[cnt - m].push_back(cnt);
        d[cnt][cnt - m].first = d[cnt - m][cnt].first = 1;
      }
      if (j > 0 && !park[cnt] && !park[cnt - 1]) {
        vec[cnt].push_back(cnt - 1);
        vec[cnt - 1].push_back(cnt);
        d[cnt][cnt - 1].first = d[cnt - 1][cnt].first = 1;
      }
    }
  }
  floyd();
  cin >> r >> c >> boss.sp;
  r--;
  c--;
  boss.id = r * m + c;
  for (int i = 0; i < mls; i++) {
    cin >> x >> y >> tmp.sp;
    x--;
    y--;
    tmp.id = x * m + y;
    ml.push_back(tmp);
    M[tmp.id]++;
  }
  for (int i = 0; i < fms; i++) {
    cin >> x >> y >> tmp.sp;
    x--;
    y--;
    tmp.id = x * m + y;
    fm.push_back(tmp);
    F[tmp.id]++;
  }
  for (int i = 0; i < n * m; i++) {
    if (!park[i] && !mark[i]) {
      numm = numf = ted = 0;
      flg = 0;
      dfsr(i);
      if (!flg) {
        if (numm != numf || numm > ted) {
          cout << -1;
          return 0;
        }
      } else {
        if (ABS(numm - numf) != 1 || max(numm, numf) > ted) {
          cout << -1;
          return 0;
        }
        if (numm > numf)
          fm.push_back(boss);
        else
          ml.push_back(boss);
      }
    }
  }
  s = -1;
  f = OO;
  TOTAL = (mls + fms + 1) / 2;
  while (f - s > 1) {
    memset(head, -1, sizeof head);
    ecnt = 0;
    mid = (s + f) / 2;
    for (int i = 0; i < ((int(good.size()))); i++)
      adde(2 * good[i], 2 * good[i] + 1, 1);
    for (int i = 0; i < ((int(ml.size()))); i++) {
      adde(2 * n * m + ((int(ml.size()))) + ((int(fm.size()))), 2 * n * m + i,
           1);
      for (int j = 0; j < n * m && ml[i].sp * d[ml[i].id][j].first <= mid; j++)
        adde(2 * n * m + i, 2 * d[ml[i].id][j].second, 1);
    }
    for (int i = 0; i < ((int(fm.size()))); i++) {
      adde(2 * n * m + ((int(ml.size()))) + i,
           2 * n * m + ((int(ml.size()))) + ((int(fm.size()))) + 1, 1);
      for (int j = 0; j < n * m && fm[i].sp * d[fm[i].id][j].first <= mid; j++)
        adde(2 * d[fm[i].id][j].second + 1, 2 * n * m + ((int(ml.size()))) + i,
             1);
    }
    if (flow(2 * n * m + ((int(ml.size()))) + ((int(fm.size()))),
             2 * n * m + ((int(ml.size()))) + ((int(fm.size()))) + 1) == TOTAL)
      f = mid;
    else
      s = mid;
  }
  cout << f;
  return 0;
}
