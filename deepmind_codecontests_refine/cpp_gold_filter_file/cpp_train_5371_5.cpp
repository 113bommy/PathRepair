#include <bits/stdc++.h>
using namespace std;
long long n, x, y, z, m, p, q, r;
long long ara[300000];
long long gcd(long long n, long long m) {
  if (m == 0) return n;
  return gcd(m, n % m);
}
int main() {
  cin >> n;
  long long gc = 0;
  for (long long i = 1; i <= n; i++)
    scanf("%I64d", &ara[i]), gc = gcd(gc, ara[i]);
  if (gc > 1) {
    cout << "YES" << endl << 0 << endl;
    return 0;
  }
  long long ans = 0;
  for (long long i = 1; i < n; i++) {
    if (ara[i] % 2 == 0) continue;
    if (ara[i + 1] % 2 == 1) {
      ans += 1;
      ara[i] = ara[i + 1] = 2;
    } else {
      ans += 2;
      ara[i] = ara[i + 1] = 2;
    }
  }
  if (ara[n] % 2 == 1) {
    ans += 2;
  }
  cout << "YES" << endl << ans << endl;
  return 0;
}
