#include <bits/stdc++.h>
const int N = 1e5 + 10;
int t[N], l[N];
int n, L, a;
int main() {
  scanf("%d%d%d", &n, &L, &a);
  t[0] = l[0] = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &t[i], &l[i]);
    ans += (t[i] - t[i - 1] - l[i - 1]) / a;
  }
  ans += (L - t[n] - l[n]) / a;
  printf("%d\n", ans);
}
