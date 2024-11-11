#include <bits/stdc++.h>
using namespace std;
const long long N = 200005, INF = 2000000000000000000;
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
vector<long long> prime;
bool is_composite[N];
void sieve(long long n) {
  memset(is_composite, false, sizeof(is_composite));
  for (long long i = 2; i < n; ++i) {
    if (!is_composite[i]) prime.push_back(i);
    for (long long j = 0; j < prime.size() && i * prime[j] < n; ++j) {
      is_composite[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
void print(bool n) {
  if (n) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
long long a, b, c, d;
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> d;
    if (b * c < a) {
      cout << -1 << "\n";
      continue;
    }
    long long ans = 0;
    auto val = [&](long long m) {
      if ((m - 1) * d <= c) return m * (m - 1) * d / 2;
      long long z = c / d + 1;
      return (z + 1) * z * d / 2 + (m - z - 1) * c;
    };
    auto f = [&](long long m) {
      long long z = val(m);
      long long x = m * a - z * b;
      ans = max(x, ans);
      return x;
    };
    long long l = 0;
    long long r = 1e6;
    while (r > l + 2) {
      long long m1 = l + (r - l) / 3;
      long long m2 = r - (r - l) / 3;
      long long f1 = f(m1);
      long long f2 = f(m2);
      if (f1 >= f2) {
        r = m2;
      } else {
        l = m1;
      }
    }
    for (long long i = l; i <= r; i++) {
      ans = max(ans, f(i));
    }
    cout << ans << "\n";
  }
}
