#include <bits/stdc++.h>
const int N = 100010;
const long long INF = 1ll << 60;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
int mx;
bool vis[N];
int n;
int main() {
  scanf("%d", &n);
  if (n <= 20) {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          if (i + j + k <= n) {
            int tmp = i * 4 + j * 9 + k * 49;
            vis[tmp] = true;
            mx = std::max(mx, tmp);
          }
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i <= mx; ++i)
      if (!vis[i]) ++cnt;
    printf("%d\n", mx + 1 - cnt);
  } else {
    printf("%lld\n", 49ll * n - 247ll);
  }
  return 0;
}
