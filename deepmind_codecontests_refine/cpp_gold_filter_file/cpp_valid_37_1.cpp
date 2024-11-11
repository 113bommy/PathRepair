#include <bits/stdc++.h>
using namespace std;
const int N = 200020, MOD = 998244353;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int T, n, u, v, f[N];
bool flag;
vector<int> e[N];
int dfs(int k, int fa, int gr) {
  int cnt = 0;
  for (int i = 0; i < e[k].size(); i++) {
    int to = e[k][i];
    if (to == fa) continue;
    cnt = cnt + dfs(to, k, gr);
  }
  if (cnt % gr == 0) return 1;
  if ((cnt + 1) % gr == 0) return 0;
  flag = 0;
  return 0;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; i++) e[i].clear();
    memset(f, 0, sizeof(f)), f[1] = 1;
    for (int i = 1; i <= n - 1; i++) {
      f[1] = f[1] * 2 % MOD;
      u = read(), v = read();
      e[u].push_back(v), e[v].push_back(u);
    }
    for (int i = 2; i <= n - 1; i++)
      if ((n - 1) % i == 0) {
        flag = 1;
        if (dfs(1, 0, i) == 1 && flag) f[i] = 1;
      }
    for (int i = n - 1; i >= 1; i--)
      for (int j = 2; i * j <= n - 1; j++) f[i] = f[i] - f[i * j];
    f[1] = (f[1] + MOD) % MOD;
    for (int i = 1; i <= n; i++) printf("%d ", f[i]);
    printf("\n");
  }
  return 0;
}
