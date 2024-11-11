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
struct Input {
  int n;
  int64_t k;
  vector<int> a;
  bool read() {
    if (scanf("%d%" SCNd64, &n, &k) != 2) return 0;
    a.resize(n + 1);
    for (int i = int(0); i < int(n + 1); ++i) {
      scanf("%d", &a[i]);
    }
    return 1;
  }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  int ans;
  void write() { printf("%d\n", ans); }
};
struct Solution : Data {
  vector<int64_t> plus, minus;
  void solve() {
    plus.assign(n + 10, int64_t(0));
    minus.assign(n + 10, int64_t(0));
    for (int i = int(0); i < int(n + 1); ++i) {
      if (!a[i]) continue;
      if (a[i] > 0) {
        plus[i] += a[i];
      } else {
        minus[i] -= a[i];
      }
    }
    int m = ((int)(plus).size());
    for (int i = int(0); i < int(m - 1); ++i) {
      plus[i + 1] += plus[i] / 2;
      plus[i] %= 2;
      minus[i + 1] += minus[i] / 2;
      minus[i] %= 2;
    }
    int id = 0;
    for (int i = int(m) - 1; i >= int(0); --i) {
      if (plus[i] > minus[i]) {
        id = 1;
        break;
      } else if (plus[i] < minus[i]) {
        id = -1;
        break;
      }
    };
    ;
    if (id == -1) {
      for (int i = int(0); i < int(n + 1); ++i) {
        a[i] *= -1;
      }
      plus.swap(minus);
      id = 1;
    }
    int l_index = -1, r_index = 0;
    for (int i = int(0); i < int(m - 1); ++i) {
      int diff = plus[i] - minus[i];
      while (diff < 0) {
        plus[i + 1]--;
        diff += 2;
      }
      plus[i] = diff;
      if (plus[i]) {
        if (l_index == -1) {
          l_index = i;
        }
        r_index = i;
      }
    };
    ;
    int64_t val = 0ll;
    ans = 0;
    for (int i = int(r_index + 1) - 1; i >= int(l_index); --i) {
      val = (val * 2 + plus[i]);
      if (val > 5 * k) {
        return;
      }
    };
    while (l_index >= 0 && val < 5 * k) {
      if (l_index == n && a[l_index] != val && abs(a[l_index] - val) <= k) {
        ans++;
      }
      if (l_index < n && abs(a[l_index] - val) <= k) {
        ans++;
      }
      val *= 2;
      --l_index;
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
