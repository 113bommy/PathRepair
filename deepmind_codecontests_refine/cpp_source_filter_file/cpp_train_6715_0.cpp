#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int64_t mod = 1000000007;
const int N = 1000000;
struct Input {
  int n, k;
  int64_t l;
  int a[N];
  bool read() {
    if (!(cin >> n >> l >> k)) {
      return 0;
    }
    for (int i = int(0); i < int(n); ++i) {
      scanf("%d", &a[i]);
    }
    return 1;
  }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  int64_t ans;
  void write() { cout << ans << endl; }
  virtual void solve() {}
  virtual void clear() { *this = Data(); }
};
struct Solution : Data {
  int64_t pw(int64_t a, int64_t n) {
    int64_t ans = 1;
    while (n) {
      if (n & 1) {
        (ans *= a) %= mod;
      }
      (a *= a) %= mod;
      n >>= 1;
    }
    return ans;
  }
  int64_t d[2][N];
  void solve() {
    int64_t q = l / n;
    int r = l % n;
    vector<pair<int, int> > v;
    for (int i = int(0); i < int(n); ++i) {
      v.push_back(make_pair(a[i], i));
    }
    sort((v).begin(), (v).end());
    memset(d, 0, sizeof d);
    for (int i = int(0); i < int(n); ++i) {
      d[1][i] = 1;
    }
    for (int x = int(1); x < int(k + 1); ++x) {
      int64_t cq = max<int64_t>(0, q - x + 1) % mod;
      int64_t cq1 = max<int64_t>(0, q - x + 2) % mod;
      int x0 = x & 1;
      int x1 = x0 ^ 1;
      for (int i = int(0); i < int(n); ++i) {
        ;
        (ans += d[x0][i] * ((i < r) ? cq1 : cq)) %= mod;
      }
      int64_t s = 0;
      for (int l = 0; l < n;) {
        int r = l;
        while (r < n && v[r].first == v[l].first) {
          s += d[x0][v[r].second];
          ++r;
        }
        for (int i = int(l); i < int(r); ++i) {
          d[x1][v[i].second] = s;
        }
        l = r;
      }
    }
  }
  void clear() { *this = Solution(); }
};
Solution sol;
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  sol.read();
  sol.solve();
  sol.write();
  return 0;
}
