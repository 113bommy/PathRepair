#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long nod(long long n) {
  string s = to_string(n);
  return (long long)s.length();
}
long long sod(long long n) {
  long long ans = 0;
  while (n) ans += (n % 10), n /= 10;
  return ans;
}
long long modexpo(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  while (y) {
    if (y & 1) res *= x, res %= p;
    x *= x, x %= p;
    y >>= 1;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    map<long long, long long> m, m1;
    long long n;
    cin >> n;
    long long ans = 0;
    long long a[n + 2];
    long long sm = 0;
    m[0] = 1;
    long long cr = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i], sm += a[i];
      if (m[sm] and cr < m[sm]) cr = m[sm], ans++;
      m[sm] = i + 1;
    }
    cout << ans << "\n";
  }
}
