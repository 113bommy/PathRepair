#include <bits/stdc++.h>
using namespace std;
int dbg = 0;
const int N = 21;
const int lg = 20;
const long long mod = 0xfffff;
bool bound(int x, int y, int z, int w) {
  return 0 <= x && x < z && 0 <= y && y < w;
}
int v[N][N];
long long g[N][N];
bool mk[N][N];
map<long long, long long> u[N][N];
void solve() {
  int n, m;
  long long k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      v[i][j] = i + j + 1;
    }
  if (n == 1 && m == 1) {
    if (g[0][0] == k)
      cout << "1\n";
    else
      cout << "0\n";
    return;
  }
  int sm = n + m - 1;
  int to = sm >> 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (v[i][j] > to) v[i][j] = -v[i][j] - sm;
  vector<int> s;
  s.push_back(0);
  s.push_back(n - 1);
  vector<int> e;
  e.push_back(0);
  e.push_back(m - 1);
  for (int i = 0; i < N; i++) fill(mk[i], mk[i] + N, 0);
  for (int it = 0; it < 2; it++) {
    int sgn = it ? -1 : 1;
    int sx = s[it], sy = e[it];
    u[sx][sy][g[sx][sy]] = 1;
    mk[sx][sy] = 1;
    int ptr = 0;
    vector<int> q;
    q.push_back(sx);
    q.push_back(sy);
    while (ptr < ((int)(q).size())) {
      int x = q[ptr++];
      int y = q[ptr++];
      for (int i = 0, j = 1; i < 2; i++, j ^= 1) {
        int nx = x + i * sgn, ny = y + j * sgn;
        if (!bound(nx, ny, n, m)) continue;
        int cv = v[x][y], nv = v[nx][ny];
        if (cv < nv && cv * nv > 0) {
          for (auto& z : u[x][y]) {
            long long w = z.first ^ g[nx][ny];
            if (u[nx][ny].find(w) == u[nx][ny].end()) u[nx][ny][w] = 0;
            u[nx][ny][w] += u[x][y][z.first];
          }
          if (!mk[nx][ny]) {
            mk[nx][ny] = 1;
            q.push_back(nx);
            q.push_back(ny);
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (v[i][j] == to) {
        for (int x = 0, y = 1; x < 2; x++, y ^= 1) {
          int nx = i + x, ny = j + y;
          if (!bound(nx, ny, n, m)) continue;
          for (auto& z : u[i][j]) {
            long long w = z.first ^ k;
            if (u[nx][ny].find(w) != u[nx][ny].end())
              ans += z.second * u[nx][ny][w];
          }
        }
      }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
