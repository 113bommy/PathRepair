#include <bits/stdc++.h>
const int maxn = 500005;
int n, c, ans;
int a[maxn], cnt[maxn], minn[maxn];
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
int main() {
  scanf("%d%c", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    minn[a[i]] = min(minn[a[i]], cnt[a[i]] - cnt[c]);
    cnt[a[i]]++, ans = max(ans, (cnt[a[i]] - cnt[c]) - minn[a[i]]);
  }
  printf("%d\n", cnt[c] + ans);
  return 0;
}
