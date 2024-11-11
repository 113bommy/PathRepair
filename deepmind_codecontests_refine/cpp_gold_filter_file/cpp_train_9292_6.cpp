#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& out, const vector<long long>& b) {
  for (auto k : b) out << k << " ";
  return out;
}
istream& operator>>(istream& in, pair<long long, long long>& b) {
  in >> b.first >> b.second;
  return in;
}
ostream& operator<<(ostream& out, const pair<long long, long long>& b) {
  out << "{" << b.first << ", " << b.second << "}";
  return out;
}
template <typename T1, typename T2>
inline bool chkmin(T1& x, const T2& y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool chkmax(T1& x, const T2& y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
const long long INF = 1e13 + 10;
const long double PI = acos(-1);
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve() {
  long long n, d, m;
  cin >> n >> d >> m;
  vector<long long> mn, mx;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x <= m)
      mn.push_back(x);
    else
      mx.push_back(x);
  }
  sort((mn).begin(), (mn).end());
  if (mx.size() == 0) {
    long long ans = 0;
    for (auto k : mn) ans += k;
    cout << ans << "\n";
    return;
  }
  sort((mx).begin(), (mx).end());
  long long ans = 0, sum = 0;
  for (long long i = (long long)mx.size() - 1; i >= 0; i--) {
    sum += mx[i];
    if (((long long)mx.size() - i - 1) * (d + 1) + 1 <= n) {
      ans = sum;
    }
  }
  long long sz = mn.size();
  sum = 0;
  vector<long long> pref(mx.size() + 1);
  pref[0] = 0;
  for (long long i = 1; i <= mx.size(); i++) {
    pref[i] = pref[i - 1] + mx[i - 1];
  }
  for (long long i = sz - 1; i >= 0; i--) {
    sum += mn[i];
    long long have = i;
    long long l = 1, r = mx.size() + 1, mid;
    while (r - l > 1) {
      mid = (l + r) / 2;
      if ((mid - 1) * (d + 1) + 1 <= have + mx.size()) {
        l = mid;
      } else {
        r = mid;
      }
    }
    chkmax(ans, sum + pref[mx.size()] - pref[(long long)mx.size() - l]);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  while (q--) {
    solve();
  }
}
