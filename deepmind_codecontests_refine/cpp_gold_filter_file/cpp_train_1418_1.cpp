#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void upd1(T& a, T b) {
  a > b ? a = b : 0;
}
template <class T>
inline void upd2(T& a, T b) {
  a < b ? a = b : 0;
}
struct ano {
  operator long long() {
    long long x = 0, y = 0, c = getchar();
    while (c < 48) y = c == 45, c = getchar();
    while (c > 47) x = x * 10 + c - 48, c = getchar();
    return y ? -x : x;
  }
} buf;
const int p = 1e9 + 7;
const int N = 1e5 + 5;
long long f[N][11][4], g[11][4];
vector<int> e[N];
int n, m, k, x;
void dfs(int u, int w) {
  f[u][1][0] = 1;
  f[u][0][1] = k - 1;
  f[u][0][2] = k - 1;
  f[u][0][3] = m - k;
  for (int v : e[u])
    if (v != w) {
      dfs(v, u);
      memset(g, 0, sizeof g);
      for (int i = x; ~i; --i)
        for (int j = x - i; ~j; --j) {
          (g[i + j][0] += f[u][i][0] * f[v][j][2]) %= p;
          (g[i + j][1] += f[u][i][1] * (f[v][j][0] + f[v][j][1])) %= p;
          (g[i + j][2] += f[u][i][2] * (f[v][j][0] + f[v][j][1])) %= p;
          (g[i + j][3] += f[u][i][3] * f[v][j][1]) %= p;
        }
      memcpy(f[u], g, sizeof g);
    }
  for (int i = x; ~i; --i) (f[u][i][1] += f[u][i][3]) %= p;
}
int main() {
  n = buf, m = buf;
  for (int i = 2; i <= n; ++i) {
    int u = buf, v = buf;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  k = buf, x = buf;
  dfs(1, 0);
  long long s = 0;
  for (int i = 0; i <= x; ++i) s += f[1][i][0] + f[1][i][1];
  cout << s % p << endl;
}
