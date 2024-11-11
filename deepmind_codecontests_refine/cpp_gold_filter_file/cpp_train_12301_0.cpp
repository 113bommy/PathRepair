#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long int mod = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long int ans = 0;
  long long int n = (long long int)s.length();
  long long int left = 0, right = 0;
  long long int ds[n + 1];
  memset(ds, 0, sizeof(ds));
  for (long long int p = 0; p < n; ++p) {
    for (long long int k = 1; k <= 4; k++) {
      if ((p + k) >= n || (p + 2 * k) >= n) continue;
      if (s[p] == s[p + k] && s[p + k] == s[p + 2 * k]) {
        ds[p] = n - (p + 2 * k);
        break;
      }
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    ds[i] = max(ds[i], ds[i + 1]);
  }
  for (int i = 0; i < n; ++i) {
    ans += ds[i];
  }
  cout << ans << '\n';
  return 0;
}
