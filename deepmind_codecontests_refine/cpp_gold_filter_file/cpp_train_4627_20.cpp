#include <bits/stdc++.h>
using namespace std;
long long dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1},
          ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
long long gcd(long long a, long long b) {
  if (!a) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
const long long template_array_size = 1e6 + 2047;
const long long N = 1e5 + 6;
const long long mod = 1e9 + 7;
long long mul(long long a, long long b) { return (a % mod) * (b % mod) % mod; }
long long add(long long a, long long b) { return (a + b) % mod; }
long long sub(long long a, long long b) {
  return (a % mod - b % mod + mod) % mod;
}
long long divide(long long a, long long b) {
  return a * (long long)pow(b, mod - 2) % mod;
}
void test_case() {
  long long n, b;
  cin >> n >> b;
  long long arr[n];
  for (long long i = 0; i < (long long)(n); i++) {
    cin >> arr[i];
  }
  long long ans = b;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = i + 1; j < n; j++) {
      long long rem = b % arr[i] + (b / arr[i]) * (arr[j]);
      ans = max(ans, rem);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(20);
  long long t = 1;
  while (t--) {
    test_case();
  }
}
