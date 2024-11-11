#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long s[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  s[0] = 0;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
  long long ans1 = 0;
  for (int t = 1; t < n; t++) {
    ans1 = ans1 + a[n - t - 1] * t;
  }
  int q, k;
  cin >> q;
  for (int qq = 0; qq < q; qq++) {
    scanf("%d", &k);
    if (k == 1)
      printf("%I64d", ans1);
    else {
      long long p = k;
      long long ans = 0;
      int t = n - 1;
      int mn = 1;
      while (t - p >= 0) {
        ans = ans + (s[t] - s[t - p]) * mn;
        t = t - p;
        p = p * k;
        mn++;
      }
      if (t > 0) ans = ans + mn * (s[t] - s[0]);
      printf("%I64d", ans);
    }
    if (qq < q - 1) printf(" ");
  }
  printf("\n");
  return 0;
}
