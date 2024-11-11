#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& stream, const vector<T> v) {
  stream << "[ ";
  for (int i = 0; i < (int)v.size(); i++) stream << v[i] << " ";
  stream << "]";
  return stream;
}
long long fpow(long long x, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1) {
    if (p & 1) r = r * x % m;
    x = x * x % m;
  }
  return r;
}
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
const long long mod = 1000000007;
long long x, y;
map<long long, long long> sum;
vector<long long> d;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y;
  if (y % x != 0) {
    cout << 0 << "\n";
    return 0;
  }
  long long i;
  for (i = 1; i * i <= y; i++)
    if (y % i == 0) {
      d.push_back(i);
      if (i != y / i) d.push_back(y / i);
    }
  sort((d).begin(), (d).end());
  reverse((d).begin(), (d).end());
  long long ans = 0;
  for (long long div : d) {
    long long ny = y / div;
    long long val = (fpow(2, ny - 1, mod) - sum[div] + mod) % mod;
    for (i = 1; i * i <= div; i++)
      if (div % i == 0) {
        sum[i] = (sum[i] + val) % mod;
        if (i != div / i) sum[div / i] = (sum[div / i] + val) % mod;
      }
    if (div == x) {
      ans = val;
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}
