#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long int fast_exp(long long int base, long long int ex) {
  long long int res = 1;
  while (ex > 0) {
    if (ex % 2 == 1) res = (res * base) % mod;
    base = (base * base) % mod;
    ex /= 2;
  }
  return res % mod;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  long long int re = gcd(b, a % b);
  return re;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  long long gc = ar[0];
  for (int i = 1; i < n; i++) gc = gcd(gc, ar[i]);
  if (gc > 1) {
    cout << "YES\n0\n";
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (ar[i] % 2 == 0) continue;
    if (i < n - 1 && ar[i + 1] % 2) {
      ar[i] = 2;
      ar[i + 1] = 2;
      ans++;
      continue;
    } else {
      ans += 2;
      ar[i] = 2;
      ar[i + 1] = 2;
    }
  }
  cout << "YES\n";
  cout << ans << "\n";
  return 0;
}
