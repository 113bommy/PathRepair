#include <bits/stdc++.h>
int A, B, q, L, t, m;
long long f(int i) { return A + (i - 1LL) * B; }
long long sum(int n) { return 1LL * A * n + (n - 1LL) * n / 2; }
int main() {
  scanf("%d%d%d", &A, &B, &q);
  while (q--) {
    scanf("%d%d%d", &L, &t, &m);
    int l = L - 1, r = (int)1e6 + 5;
    while (r - l > 1) {
      int mid = l + r >> 1;
      if (f(mid) <= t && sum(mid) - sum(L - 1) <= 1LL * t * m)
        l = mid;
      else
        r = mid;
    }
    if (l == L - 1)
      puts("-1");
    else
      printf("%d\n", l);
  }
}
