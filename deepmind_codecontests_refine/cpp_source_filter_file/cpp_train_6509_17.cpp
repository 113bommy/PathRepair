#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct outputer;
struct outputable {};
const double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1 &a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 200000;
const int K = 50;
struct Input {
  int n, k;
  int a[N];
  bool read() {
    if (!(cin >> n >> k)) {
      return 0;
    }
    for (int i = int(0); i < int(n); ++i) {
      scanf("%d", &a[i]);
    }
    return 1;
  }
  void init(const Input &input) { *this = input; }
};
struct Data : Input {
  double ans;
  void write() { cout << ans << endl; }
};
struct Solution : Data {
  double s[N + 1];
  double t[N + 1];
  double sinv[N + 1];
  double calc(int l, int r) {
    return (t[r] - t[l]) - s[l] * (sinv[r] - sinv[l]);
  }
  void make(double *from, double *to, int lfrom, int rfrom, int lto, int rto) {
    ;
    ;
    if (lto == rto) {
      return;
    }
    int mto = (lto + rto) / 2;
    ;
    int mfrom = -1;
    for (int i = int(lfrom); i < int(min(rfrom, mto)); ++i) {
      if (umn(to[mto], from[i] + calc(i, mto))) {
        mfrom = i;
      }
    }
    make(from, to, lfrom, mfrom + 1, lto, mto);
    make(from, to, mfrom, rfrom, mto + 1, rto);
  }
  double d[K + 1][N + 1];
  void solve() {
    s[0] = 0;
    t[0] = 0;
    sinv[0] = 0;
    for (int i = int(0); i < int(n); ++i) {
      s[i + 1] = s[i] + a[i];
      t[i + 1] = t[i] + s[i + 1] * 1.l / a[i];
      sinv[i + 1] = sinv[i] + 1.l / a[i];
    }
    for (int i = int(0); i < int(k + 1); ++i) {
      for (int j = int(0); j < int(n + 1); ++j) {
        d[i][j] = 1e20l;
      }
    }
    d[0][0] = 0;
    for (int i = int(0); i < int(k); ++i) {
      ;
      make(d[i], d[i + 1], 0, n + 1, 0, n + 1);
    }
    for (int i = int(0); i < int(k + 1); ++i) {
      ;
    }
    ans = d[k][n];
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
