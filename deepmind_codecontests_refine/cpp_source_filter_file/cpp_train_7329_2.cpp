#include <bits/stdc++.h>
using namespace std;
long long t;
const long long M = 1e9 + 7;
const long long inf = 100000;
long long max(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long min(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
long long fspow(long long x, long long y) {
  long long ans;
  if (y == 0) return 1;
  ans = fspow(x, y / 2);
  if (y % 2 == 0) return ((ans * ans) % M);
  return (x * ((ans * ans) % M)) % M;
}
long long gcd(long long x, long long y) {
  if (x < y) swap(x, y);
  if (y == 0) return x;
  return gcd(x % y, y);
}
long long p2(long long x) {
  long long ans = 0;
  while (x > 1) {
    ans++;
    x /= 2;
  }
  return ans;
}
bool isPrime(long long x) {
  for (long long i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long ar[n];
    for (long long i = 0; i < n; i++) cin >> ar[i];
    string s;
    cin >> s;
    long long pre[n];
    pre[0] = 0;
    long long lbs = -1;
    for (long long i = 0; i < n; i++)
      if (s[i] == '1') lbs = i;
    if (lbs == -1) {
      cout << 0 << "\n";
      break;
    }
    for (long long i = 1; i < n; i++) pre[i] = pre[i - 1] + ar[i - 1];
    long long suff[n];
    suff[lbs] = ar[lbs];
    for (long long i = lbs - 1; i >= 0; i--)
      suff[i] = suff[i + 1] + (s[i] - '0') * ar[i];
    long long ans = -inf;
    for (long long i = 0; i <= lbs; i++) {
      if (s[i] == 0) continue;
      ans = max(ans, pre[i] + suff[i] - ar[i]);
    }
    cout << max(ans, suff[0]) << "\n";
  }
}
