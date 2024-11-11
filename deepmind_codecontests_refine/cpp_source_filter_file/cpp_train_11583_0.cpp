#include <bits/stdc++.h>
using namespace std;
long long ceill(long long a, long long b) { return a / b + bool(a % b); }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    y >>= 1;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void primeFactors(long long n, vector<long long> &vec) {
  while (n % 2 == 0) vec.push_back(2), n /= 2;
  for (long long i = 3; i <= sqrt(n); i += 2)
    while (n % i == 0) vec.push_back(i), n /= i;
  if (n > 2) vec.push_back(n);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  bool flag = 1;
  string str;
  cin >> str;
  for (long long i = 0; i < n; i++) flag &= (str[i] == '0');
  if (flag) {
    cout << max(1LL, (n + k) / (k + 1)) << '\n';
    return;
  }
  long long cnt = 0;
  vector<long long> vec;
  for (long long i = 0; i < n; i++) {
    if (str[i] == '0')
      cnt++;
    else
      vec.push_back(cnt), cnt = 0;
  }
  vec.push_back(cnt);
  long long ans = 0;
  bool flag1 = 0, flag2 = 0;
  if (str[0] == '0') flag1 = 1;
  if (str[n - 1] == '0') flag2 = 1;
  for (long long i = 0; i < vec.size(); i++) {
    long long ele = vec[i];
    if ((flag1 && i == 0) || (flag2 && i == (vec.size() - 1))) {
      long long tmp = ele - k;
      if (tmp >= k) {
        ans += (tmp + k) / (k + 1);
      }
    } else {
      long long tmp = ele - 2 * k;
      if (tmp >= k) {
        ans += (tmp + k) / (k + 1);
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  for (long long TTT = 1; TTT <= tc; TTT++) {
    solve();
  }
}
