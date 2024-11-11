#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T& a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T& a, Args&... args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007;
constexpr long long M9 = 1000000009;
constexpr long long MFFT = 998244353;
constexpr double PI = 3.14159265358979323846;
template <class T>
void outv(const T& a, char d = ' ', bool nl = false) {
  for (auto& x : a) cout << x << d;
  if (nl) cout << '\n';
}
static mt19937_64 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
auto __fast_io__ = (ios_base::sync_with_stdio(false), cin.tie(nullptr));
int32_t main() {
  int n;
  __read(n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    string s;
    __read(s);
    x[i] = count((s).begin(), (s).end(), 'B');
    y[i] = count((s).begin(), (s).end(), 'N');
  }
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = {x[i], y[i]};
  }
  sort((x).begin(), (x).end());
  int mx_x = *max_element((x).begin(), (x).end());
  int mn_x = *min_element((x).begin(), (x).end());
  int mx_y = *max_element((y).begin(), (y).end());
  int mn_y = *min_element((y).begin(), (y).end());
  multiset<int> left, right;
  for (int i = 0; i < n; ++i) {
    right.emplace(a[i].first - a[i].second);
  }
  auto calc = [&](int i, int j) {
    int res = abs(mx_x - i);
    res = max(res, abs(mn_x - i));
    res = max(res, abs(mx_y - j));
    res = max(res, abs(mn_y - j));
    if (!left.empty()) {
      res = max(res, *left.rbegin() + i - j);
    }
    if (!right.empty()) {
      res = max(res, *right.rbegin() + j - i);
    }
    return res;
  };
  int ans = INT_MAX;
  int ans_x = -1, ans_y = -1;
  int ptr = 0;
  for (int i = mn_x; i <= mx_x; ++i) {
    int l = max(mn_y, (i == 0 ? 1 : 0)), r = mx_y;
    while (r - l >= 3) {
      int z = (r - l) / 3;
      int mid1 = l + z;
      int mid2 = r - z;
      if (calc(i, mid1) > calc(i, mid2)) {
        l = mid1;
      } else {
        r = mid2;
      }
    }
    for (int j = l; j <= r; ++j) {
      int res = calc(i, j);
      if (res < ans) {
        ans = res;
        ans_x = i;
        ans_y = j;
      }
    }
    while (ptr < a.size() && a[ptr].first == i) {
      right.erase(right.find({a[ptr].first - a[ptr].second}));
      left.emplace(a[ptr].second - a[ptr].first);
      ptr++;
    }
  }
  cout << ans << '\n';
  cout << string(ans_x, 'B') << string(ans_y, 'N');
  return 0;
}
