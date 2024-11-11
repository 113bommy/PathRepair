#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct outputer;
struct outputable {};
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
const int N = 200000;
const int X = 1000000000;
struct Input {
  int n, m;
  int a[N];
  int l[N], r[N];
  bool read() {
    if (!(cin >> n >> m)) {
      return 0;
    }
    for (int i = int(0); i < int(n); ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = int(0); i < int(m); ++i) {
      scanf("%d%d", &l[i], &r[i]);
    }
    return 1;
  }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  int64_t ans;
  void write() { cout << ans << endl; }
};
namespace Main {
struct Solution : Data {
  int min_r[3 * N + 1];
  int pos_a[N], pos_l[N], pos_r[N];
  int64_t d[N][2];
  void solve() {
    sort(a, a + n);
    ;
    ;
    ;
    vector<pair<int, pair<int, int>>> v;
    for (int i = int(0); i < int(m); ++i) {
      v.emplace_back(make_pair(l[i], make_pair(0, i)));
      v.emplace_back(make_pair(r[i], make_pair(1, i)));
    }
    for (int i = int(0); i < int(n); ++i) {
      v.emplace_back(make_pair(a[i], make_pair(2, i)));
    }
    sort((v).begin(), (v).end());
    ;
    for (int i = int(0); i < int(((int)(v).size())); ++i) {
      if (v[i].second.first == 2) {
        pos_a[v[i].second.second] = i;
      }
    };
    min_r[((int)(v).size())] = m;
    for (int i = int(((int)(v).size())) - 1; i >= int(0); --i) {
      min_r[i] = min_r[i + 1];
      if (v[i].second.first == 0 &&
          (min_r[i] == m || r[min_r[i]] > r[v[i].second.second])) {
        min_r[i] = v[i].second.second;
      }
    };
    for (int i = int(0); i < int(n); ++i) {
      d[i][0] = d[i][1] = 10ll * X;
    }
    int max_l_ = l[0];
    int min_r_ = r[0];
    for (int i = int(0); i < int(m); ++i) {
      umx(max_l_, l[i]);
      umn(min_r_, r[i]);
    }
    int64_t val_l = max(a[0] - min_r_, 0);
    int64_t val_r = max(max_l_ - a[n - 1], 0);
    ;
    d[0][0] = 2 * val_l;
    d[0][1] = val_l;
    for (int i = int(1); i < int(n); ++i) {
      for (int j = pos_a[i - 1]; j < pos_a[i]; ++j) {
        int k = min_r[j];
        int64_t val1 = v[j].first - a[i - 1];
        int64_t val2 = 0;
        if (k != m) {
          umx(val2, a[i] - r[k]);
        }
        int64_t t = min(d[i - 1][0] + val1, d[i - 1][1] + 2 * val1);
        umn(d[i][0], t + 2 * val2);
        umn(d[i][1], t + val2);
      }
    }
    for (int i = int(0); i < int(n); ++i) {
      ;
    }
    ans = min(d[n - 1][0] + val_r, d[n - 1][1] + 2 * val_r);
  }
  void clear() {}
};
}  // namespace Main
Main::Solution sol;
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  int t;
  cin >> t;
  for (int i = int(0); i < int(t); ++i) {
    sol.read();
    sol.solve();
    sol.write();
    sol.clear();
  }
  return 0;
}
