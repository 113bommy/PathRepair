#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int q, n, a[N], f[N], g[N];
map<int, int> h[N];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? x : -x;
}
int main() {
  q = read();
  while (q--) {
    n = read(), h[0].clear();
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = read(), f[i] = g[i] = 0, h[i].clear();
      if (h[i - 1][a[i]])
        g[i] = h[i - 1][a[i]] - 1, swap(h[i], h[g[i] - 1]),
        h[i][a[g[i] - 1]] = g[i];
      if (g[i]) f[i] = f[g[i] - 1] + 1;
      h[i][a[i]] = i + 1, ans += f[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
