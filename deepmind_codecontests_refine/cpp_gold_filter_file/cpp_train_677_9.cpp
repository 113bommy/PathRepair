#include <bits/stdc++.h>
using namespace std;
vector<int> G[3001], TG[3001];
pair<int, int> M[3001][3], dist[3001], N[3001][3];
queue<int> Q;
int De[3001][3001];
bool us[3001];
int main() {
  int n, ok, m, i, j, x, y, ii, d, maxi = 0, Am, Bm, Cm, Dm, A, D;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    G[x].push_back(y);
    TG[y].push_back(x);
  }
  for (ii = 1; ii <= n; ii++) {
    Q.push(ii);
    us[ii] = 1;
    dist[ii].first = 0;
    while (!Q.empty()) {
      x = Q.front();
      Q.pop();
      for (i = 0; i < G[x].size(); i++)
        if (!us[G[x][i]]) {
          dist[G[x][i]].first = dist[x].first + 1;
          us[G[x][i]] = 1;
          Q.push(G[x][i]);
        }
    }
    for (j = 1; j <= n; j++) {
      dist[j].second = j;
      if (dist[j].first == 0 && j != ii) dist[j].first = -1;
      De[ii][j] = dist[j].first;
    }
    sort(dist + 1, dist + n + 1);
    M[ii][0].first = dist[n].first;
    M[ii][0].second = dist[n].second;
    M[ii][1].first = dist[n - 1].first;
    M[ii][1].second = dist[n - 1].second;
    M[ii][2].first = dist[n - 2].first;
    M[ii][2].second = dist[n - 2].second;
    memset(us, 0, n + 1);
    for (j = 1; j <= n; j++) dist[j].first = 0;
  }
  for (ii = 1; ii <= n; ii++) {
    Q.push(ii);
    us[ii] = 1;
    while (!Q.empty()) {
      x = Q.front();
      Q.pop();
      for (i = 0; i < TG[x].size(); i++)
        if (!us[TG[x][i]]) {
          dist[TG[x][i]].first = dist[x].first + 1;
          us[TG[x][i]] = 1;
          Q.push(TG[x][i]);
        }
    }
    for (j = 1; j <= n; j++) {
      dist[j].second = j;
      if (dist[j].first == 0 && j != ii) dist[j].first = -1;
    }
    sort(dist + 1, dist + n + 1);
    N[ii][0].first = dist[n].first;
    N[ii][0].second = dist[n].second;
    N[ii][1].first = dist[n - 1].first;
    N[ii][1].second = dist[n - 1].second;
    N[ii][2].first = dist[n - 2].first;
    N[ii][2].second = dist[n - 2].second;
    memset(us, 0, n + 1);
    for (j = 1; j <= n; j++) dist[j].first = 0;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (De[i][j] != -1 && i != j) {
        ok = 1;
        d = De[i][j];
        for (x = 0; x <= 2; x++)
          if (M[j][x].second != i && M[j][x].second != j) {
            if (M[j][x].first == -1)
              ok = 0;
            else {
              d += M[j][x].first;
              D = M[j][x].second;
              break;
            }
          }
        if (x != 3) {
          for (x = 0; x <= 2; x++)
            if (N[i][x].second != i && N[i][x].second != D &&
                N[i][x].second != j) {
              if (N[i][x].first == -1)
                ok = 0;
              else {
                d += N[i][x].first;
                A = N[i][x].second;
                break;
              }
            }
          if (x != 3 && ok && d > maxi) {
            Am = A;
            Bm = i;
            Cm = j;
            Dm = D;
            maxi = d;
          }
        }
      }
  cout << Am << " " << Bm << " " << Cm << " " << Dm;
  return 0;
}
