#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &b) {
  for (auto &k : b) os << k << ' ';
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &b) {
  for (auto &k : b) is >> k;
  return is;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 101;
long long last[N];
long long a[N * N];
pair<long long, long long> ans[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  memset(last, -1, sizeof(last));
  long long can = (n + (k - 2)) / (k - 1);
  for (long long i = 0; i < n; ++i) ans[i] = {-1, -1};
  for (long long i = 0; i < n * k; ++i) {
    long long x;
    cin >> x;
    --x;
    if (last[x] == -1) {
      last[x] = i;
    } else if (ans[x].first == -1) {
      long long mx = 0;
      for (long long j = last[x]; j <= i; ++j) {
        maxe(mx, a[j]);
      }
      if (mx < can) {
        for (long long j = last[x]; j <= i; ++j) {
          ++a[j];
        }
        ans[x] = {last[x], i};
      }
      last[x] = i;
    }
  }
  for (long long i = 0; i < n; ++i) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}
