#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int n;
long long ksm(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans *= x;
    x *= x;
    y >>= 1;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    scanf("%lld", a + i);
  }
  sort(a, a + n);
  long long ma = a[n - 1];
  int i;
  if (n - 1 >= 31) {
    i = 2;
  } else {
    for (i = 1;; i++) {
      if (ksm(i, n - 1) >= ma) break;
    }
  }
  long long ans1 = 0;
  long long now = 1;
  for (int j = 0; j < n; j++) {
    ans1 += abs(now - a[j]);
    now *= i;
  }
  long long ans2 = 0;
  now = 1;
  for (int j = 0; j < n; j++) {
    ans2 += abs(now - a[j]);
    now *= i - 1;
  }
  printf("%lld\n", min(ans1, ans2));
  return 0;
}
