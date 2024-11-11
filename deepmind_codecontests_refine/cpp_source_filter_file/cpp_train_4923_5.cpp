#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  for (auto v : V) os << v << " ";
  return cout << "";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  for (auto s : S) os << s << " ";
  return cout << "";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << P.first << " " << P.second;
}
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, c0, c1, h, x = 0, y = 0;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        x++;
      else
        y++;
    }
    if (c0 >= c1 + h) {
      cout << x * h + n * c1 << "\n";
    } else if (c1 > c0) {
      cout << y * h + n * c0 << "\n";
    } else {
      cout << x * c0 + y * c1 << "\n";
    }
  }
}
