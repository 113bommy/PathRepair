#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, inf = 1e9, maxm = 1e7 + 10, mod = 1e9 + 7;
int n, x, mx, anss;
int ans[maxm], mi[maxn], cnt[maxm];
inline void read(int &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(x), cnt[x]++, mx = max(mx, x);
  mi[0] = 1;
  for (int i = 1; i <= n; i++) mi[i] = (1ll * mi[i - 1] << 1) % mod;
  for (int i = mx; i >= 2; i--) {
    int sum = cnt[i];
    for (int j = i << 1; j <= mx; j += i)
      sum += cnt[j],
          ans[i] = (ans[i] - ans[j] + mod >= mod ? (ans[i] - ans[j] + mod) - mod
                                                 : (ans[i] - ans[j] + mod));
    ans[i] += 1ll * (mi[sum] - 1) * (n - sum);
    ans[i] = (ans[i] >= mod ? (ans[i]) - mod : (ans[i]));
    anss = (anss + ans[i] >= mod ? (anss + ans[i]) - mod : (anss + ans[i]));
  }
  printf("%d\n", anss);
}
