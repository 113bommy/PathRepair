#include <bits/stdc++.h>
using namespace std;
long long a[400005], b[400005];
long long n, ans;
void solve(long long n) {
  int up = sqrt(n);
  for (int i = 1; i <= up; i++) a[i] = i - 1, b[i] = n / i - 1;
  for (int p = 2; p <= up; p++) {
    if (a[p] == a[p - 1]) continue;
    int t = min(n / p / p, 1ll * up);
    for (int i = 1; i <= t; i++)
      b[i] -= (p * i <= up ? b[p * i] : a[n / (p * i)]) - a[p - 1];
    for (int i = up; i >= 1ll * p * p; i--) a[i] -= (a[i / p] - a[p - 1]);
  }
  for (int i = 2; i <= up; i++) {
    if (a[i] == a[i - 1]) continue;
    ans += b[i] - a[i];
  }
  return;
}
int main() {
  scanf("%I64d", &n);
  long long st = cbrt(n);
  solve(n);
  ans += a[st];
  printf("%I64d\n", ans);
  return 0;
}
