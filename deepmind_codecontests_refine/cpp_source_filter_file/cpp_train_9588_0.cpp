#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
inline long long powr(long long a, long long b) {
  long long t = 1;
  while (b) {
    if (b & 1) t *= a;
    a *= a;
    b >>= 1;
  }
  return t;
}
const int N = 105;
int mu[N], pr[N];
void pre() {
  for (int i = 0; i < (101); ++i) {
    pr[i] = 1;
    mu[i] = 1;
  }
  pr[1] = 0;
  for (int i = 2; i < (101); ++i) {
    if (pr[i]) {
      mu[i] = -mu[i];
      for (int j = 2; j * i < 110; j++) {
        pr[i * j] = 0;
        if (j % i == 0)
          mu[i * j] = 0;
        else
          mu[i * j] = -mu[i * j];
      }
    }
  }
}
const long long infi = 1e18;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  pre();
  int tt;
  for (cin >> tt; tt--;) {
    long long n;
    cin >> n;
    long long ans = n - 1;
    for (int i = 2; i < 60; ++i) {
      if (mu[i]) {
        long long tmp = floor(pow(n, 1.0L / i));
        if (pow(tmp + 1, i) < infi and powr(tmp + 1, i) <= n) tmp++;
        ans += (mu[i] * (tmp - 1));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
