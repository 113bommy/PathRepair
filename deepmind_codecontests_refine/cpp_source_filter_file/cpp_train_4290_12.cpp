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
constexpr long long M7 = 1000000007ll;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
template <class T>
void outv(T& a) {
  for (auto& x : a) cout << x << ' ';
}
mt19937 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
template <class T>
void random_shuffle(T s, T e) {
  shuffle(s, e, rnd);
};
static auto __super_speed__ = (ios_base::sync_with_stdio(0), cin.tie(0));
int32_t main() {
  long long t;
  __read(t);
  while (t--) {
    long long n, s;
    __read(n, s);
    vector<pair<long long, long long> > a(n);
    for (signed i = 0; i < (n); i++) cin >> a[i].first >> a[i].second;
    sort((a).begin(), (a).end());
    long long l = 0, r = 1000000000;
    while (l < r) {
      long long mid = (l + r + 1) / 2;
      long long cnt = 0;
      vector<pair<long long, long long> > b;
      for (long long i = 0; i < n; ++i) {
        if (a[i].second < mid)
          cnt += a[i].first;
        else
          b.push_back(a[i]);
      }
      long long d = b.size() - (n + 1) / 2;
      if (d < 0) {
        r = mid - 1;
        continue;
      }
      for (long long i = 0; i < d; ++i) cnt += b[i].first;
      for (long long i = d; i < b.size(); ++i) cnt += max(mid, a[i].first);
      if (cnt <= s)
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << '\n';
  }
  return 0;
}
