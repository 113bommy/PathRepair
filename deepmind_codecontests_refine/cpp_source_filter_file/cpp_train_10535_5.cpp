#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  T data = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    data = (data << 3) + (data << 1) + ch - '0';
    ch = getchar();
  }
  x = f * data;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 9;
const long long mod = 1e9 + 7;
int n, m, q;
int tot[maxn];
vector<int> g[maxn];
long long calc(int x) {
  long long ret = tot[x] - g[x].size();
  ret *= g[x].size();
  return ret;
}
signed main() {
  read(n, m);
  for (int i = 1, u, v; i <= n; ++i) {
    read(u, v);
    if (u > v) swap(u, v);
    g[u].push_back(v);
    tot[u]++, tot[v]++;
  }
  read(q);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += calc(i);
  cout << ans << '\n';
  for (int i = 1, u; i <= q; ++i) {
    read(u);
    ans -= calc(u);
    for (auto to : g[u]) {
      ans -= calc(to);
      g[to].push_back(u);
      ans += calc(to);
    }
    g[u].clear();
    cout << ans << '\n';
  }
  return 0;
}
