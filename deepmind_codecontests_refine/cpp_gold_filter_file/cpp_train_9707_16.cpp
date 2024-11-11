#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
const long long INF = 1e18;
int mod = 998244353;
template <typename T1, typename T2>
inline bool chmin(T1& a, T2 b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool chmax(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
template <typename T, typename U>
T pow_(T a, U b) {
  return b ? pow_(a * a, b / 2) * (b % 2 ? a : 1) : 1;
}
long long modpow(long long a, long long b, long long _mod) {
  return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << p.first << " " << p.second;
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (int i = 0; i < ((int)vec.size()); ++i) {
    if (i) os << " ";
    os << vec[i];
  }
  return os;
}
template <typename T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (int j = 0; j < ((int)v.size()); ++j) is >> v[j];
  return is;
}
template <class T, class T2>
inline void add(T& a, T2 b) {
  a += b;
  if (a >= mod) a -= mod;
}
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int T;
  T = 1;
  while (T--) solve();
}
void solve() {
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;
  long long ma = *max_element(a.begin(), a.end());
  int ans = 0;
  vector<int> b(n);
  auto Get = [&](long long limit) {
    long long sum = 0;
    for (int i = 0; i < (n); ++i) {
      auto binary_search = [&](int ok, int ng) {
        auto check = [&](int x) {
          if (a[i] - 3LL * x * (x + 1) - 1 >= limit) return 1;
          return 0;
        };
        int d = 1;
        while ((ng - ok >= 0 ? ng - ok : -(ng - ok)) > d) {
          int mid = (ng + ok) / 2;
          (check(mid) ? ok : ng) = mid;
        }
        return ok;
      };
      b[i] = binary_search(0, a[i] + 1);
      sum += b[i];
    }
    return sum;
  };
  auto binary_search = [&](long long ok, long long ng) {
    auto check = [&](long long x) {
      long long s = Get(x);
      if (s >= k) return 1;
      return 0;
    };
    int d = 1;
    while ((ng - ok >= 0 ? ng - ok : -(ng - ok)) > d) {
      long long mid = (ng + ok) / 2;
      (check(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  long long L = binary_search(-4e18, 4e18);
  long long s = Get(L);
  for (int i = 0; i < (s - k); ++i) {
    long long mi = INF;
    int id = -1;
    for (int j = 0; j < (n); ++j)
      if (chmin(mi, a[j] - 3LL * b[j] * b[j] + 3 * b[j] - 1)) id = j;
    b[id]--;
  }
  cout << b << '\n';
}
