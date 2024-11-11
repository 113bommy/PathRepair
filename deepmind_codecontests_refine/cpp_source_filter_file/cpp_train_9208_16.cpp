#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<int> v[MAXN];
int n, f[MAXN][2];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
template <typename T1, typename T2>
inline void Add(T1 &x, T2 y) {
  x += y, x >= MOD && (x -= MOD);
}
void solve() {
  for (int x = n; x; x--) {
    f[x][0] = 0, f[x][1] = 1;
    if (!v[x].size()) continue;
    for (auto y : v[x]) {
      int a = (1ll * f[x][0] * f[y][0] + 1ll * f[x][1] * f[y][1]) % MOD;
      int b = (1ll * f[x][0] * f[y][1] + 1ll * f[x][1] * f[y][0]) % MOD;
      Add(f[x][0], a), Add(f[x][1], b);
    }
    Add(f[x][0], f[x][0]), Add(f[x][1], f[x][1]);
    int p[3] = {1, 1, 0};
    int tmp;
    for (auto y : v[x]) {
      tmp = p[2];
      p[0] = (1ll * p[0] * f[y][0] + p[0]) % MOD;
      p[2] = (1ll * p[1] * f[y][1] + p[2]) % MOD;
      p[1] = (1ll * tmp * f[y][2] + p[1]) % MOD;
    }
    Add(f[x][0], MOD - p[2]), Add(f[x][1], MOD - p[0]);
  }
  printf("%d\n", (f[1][0] + f[1][1]) % MOD);
}
int main() {
  n = read();
  for (int i = 2; i <= n; i++) v[read()].push_back(i);
  return solve(), 0;
}
