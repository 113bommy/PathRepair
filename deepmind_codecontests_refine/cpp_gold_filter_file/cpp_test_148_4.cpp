#include <bits/stdc++.h>
using namespace std;
void my_dbg() { cout << endl; }
template <typename Arg, typename... Args>
void my_dbg(Arg A, Args... B) {
  cout << ' ' << A;
  my_dbg(B...);
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (1000000007 - ((1000000007 / i) * inv(1000000007 % i)) % 1000000007) %
         1000000007;
}
long long modmul(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a * b) % 1000000007) + 1000000007) % 1000000007;
}
long long modadd(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a + b) % 1000000007) + 1000000007) % 1000000007;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long power(long long a, long long b) {
  a %= 1000000007;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res;
}
const long long maxN = 1e6 + 5;
vector<bool> is_prime(maxN + 1, true);
void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i * i <= maxN; i++) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= maxN; j += i) is_prime[j] = false;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a, b, c, d;
    cin >> a;
    vector<long long> v1(a);
    for (long long i = 0; i < a; i++) cin >> v1[i];
    cin >> b;
    vector<long long> v2(b);
    for (long long i = 0; i < b; i++) cin >> v2[i];
    cin >> c;
    vector<long long> v3(c);
    for (long long i = 0; i < c; i++) cin >> v3[i];
    cin >> d;
    vector<long long> v4(d);
    for (long long i = 0; i < d; i++) cin >> v4[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    long long ans = max({(v1[a - 1] - v1[0]) * m, (v2[b - 1] - v2[0]) * m,
                         (v3[c - 1] - v3[0]) * n, (v4[d - 1] - v4[0]) * n});
    cout << ans << endl;
  }
  return 0;
}
