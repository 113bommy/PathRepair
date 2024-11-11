#include <bits/stdc++.h>
const int N = 1e5 + 7;
int n, m = 1, a[N], val[N], l[N], r[N];
long long s[N], num[N], ans;
int main() {
  scanf("%d", &n);
  int aa;
  scanf("%d", &aa);
  val[1] = aa;
  num[1] = 1;
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &aa);
    if (aa == val[m])
      num[m]++;
    else {
      val[++m] = aa;
      num[m] = 1;
    }
  }
  for (int i = 1; i <= m; ++i) s[i] = s[i - 1] + num[i];
  l[1] = 1;
  for (int i = 2; i <= m; ++i)
    for (l[i] = i; l[i] > 1 && (val[l[i] - 1] | val[i]) == val[i];
         l[i] = l[l[i] - 1])
      ;
  r[m] = m;
  for (int i = m - 1; i >= 1; --i)
    for (r[i] = i; r[i] < m && val[i] != val[r[i] + 1] &&
                   (val[r[i] + 1] | val[i]) == val[i];
         r[i] = r[r[i] + 1])
      ;
  for (int i = 1; i <= m; ++i)
    ans += (s[i - 1] - s[l[i] - 1]) * (s[r[i]] - s[i - 1]) +
           (s[r[i]] - s[i]) * num[i] + 1ll * num[i] * (num[i] + 1) / 2;
  printf("%I64d", 1ll * n * (n + 1) / 2 - ans);
}
