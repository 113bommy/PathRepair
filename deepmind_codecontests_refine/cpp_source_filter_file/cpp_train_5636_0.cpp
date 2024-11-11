#include <bits/stdc++.h>
using namespace std;
long long n, ans1, ans2, ans;
int a[10];
int main() {
  scanf("%lld", &n);
  for (register int i = 1; i <= n; i++) {
    a[i % 9]++;
    ans1 += n / i;
  }
  for (register int i = 0; i < 9; i++) {
    for (register int j = 0; j < 9; j++) {
      ans2 += a[i] * a[j] * a[(i * j) % 9];
    }
  }
  ans = ans2 - ans1;
  printf("%lld", ans);
  return 0;
}
