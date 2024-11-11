#include <bits/stdc++.h>
template <class type>
inline const void read(type &in) {
  in = 0;
  char ch(getchar());
  while (ch < 48 || ch > 57) ch = getchar();
  while (ch > 47 && ch < 58)
    in = (in << 3) + (in << 1) + (ch & 15), ch = getchar();
}
const int N(5e5 + 5);
int n, a[N], s1[N], top1, s2[N], top2;
long long ans, sum;
inline const void insert(const int k) {
  for (; top1 && a[k] >= a[s1[top1]]; top1--)
    sum -= 1ll * (s1[top1] - s1[top1 - 1]) * a[s1[top1]];
  for (; top2 && a[k] <= a[s2[top2]]; top2--)
    sum += 1ll * (s2[top2] - s2[top2 - 1]) * a[s2[top2]];
  if (k > 1)
    sum += 1ll * (k - 1 - s1[top1]) * a[k],
        sum -= 1ll * (k - 1 - s2[top2]) * a[k];
  s1[++top1] = k;
  s2[++top2] = k;
  ans += sum;
}
int main() {
  read(n);
  for (int i(1); i <= n; i++) read(a[i]);
  for (int i(1); i <= n; i++) insert(i);
  printf("%lld\n", ans);
  return 0;
}
