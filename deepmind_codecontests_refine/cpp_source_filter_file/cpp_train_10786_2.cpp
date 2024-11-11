#include <bits/stdc++.h>
const int maxn = 1e5 + 10, mod = 1e9 + 7;
int head[maxn], cnt, deg[maxn];
struct Edge {
  int to, nxt;
} e[maxn << 1];
void addedge(int a, int b) {
  e[++cnt] = (Edge){b, head[a]};
  head[a] = cnt;
  e[++cnt] = (Edge){a, head[b]};
  head[b] = cnt;
  ++deg[a], ++deg[b];
}
int n, ans, f[maxn][2], num;
inline int pw(int b, int p) {
  int r = 1;
  for (; p; p >>= 1, (b = static_cast<long long>(b) * (b) % mod))
    if (p) (r = static_cast<long long>(r) * (b) % mod);
  return r;
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  std::cin >> n;
  for (int i = 1, a, b; i < n; ++i) std::cin >> a >> b, addedge(a, b);
  for (int i = 1; i <= n; ++i) num += deg[i] == 1;
  int t = pw(2, n - num);
  int ans = (2ll * num + n - num) * t % mod;
  std::cout << ans << '\n';
  return 0;
}
