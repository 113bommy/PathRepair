#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
long long n, i;
int a[200000];
int sum[200000];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  sum[0] = 0;
  for (i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    ans += (i - 1) * a[i] - sum[i - 1];
    ans += sum[n] - sum[i] - (n - i) * a[i];
    ans += a[i];
  }
  long long t = gcd(ans, n);
  ans /= t;
  n /= t;
  cout << ans << " " << n << endl;
}
