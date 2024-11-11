#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 2e5 + 10;
int n, a[N], b[N];
vector<int> e[N];
const long long inf = 1e15;
long long f[N][2];
inline void dfs(int u, int fa) {
  int cnt = 0;
  long long S = 0;
  vector<long long> s;
  for (auto v : e[u])
    if (v != fa) {
      dfs(v, u), cnt++, S += f[v][0], s.push_back(f[v][1] - f[v][0]);
    }
  sort((s).begin(), (s).end());
  for (register int i = (1); i < (((int)(s).size())); i++) s[i] += s[i - 1];
  f[u][0] = f[u][1] = inf;
  for (register int i = (0); i <= (((int)(s).size())); i++) {
    if (fa) {
      if (b[u] <= b[fa])
        f[u][0] = min(f[u][0], 1ll * max(i + 1, cnt - i) * a[u] + S +
                                   (i == 0 ? 0 : s[i - 1]));
      if (b[u] >= b[fa])
        f[u][1] = min(f[u][1], 1ll * max(i, cnt - i + 1) * a[u] + S +
                                   (i == 0 ? 0 : s[i - 1]));
    } else {
      f[u][0] = min(f[u][0],
                    1ll * max(i, cnt - i) * a[u] + S + (i == 0 ? 0 : s[i - 1]));
    }
  }
}
int main() {
  n = read();
  for (register int i = (1); i <= (n); i++) a[i] = read();
  for (register int i = (1); i <= (n); i++) b[i] = read();
  for (register int i = (1); i < (n); i++) {
    int x = read(), y = read();
    e[x].push_back(y), e[y].push_back(x);
  }
  dfs(1, 0), printf("%lld\n", f[1][0]);
}
