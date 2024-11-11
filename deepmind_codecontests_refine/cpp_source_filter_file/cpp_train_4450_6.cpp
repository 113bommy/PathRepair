#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
constexpr auto MOD = 1000000007LL;
constexpr auto LINF = (1LL << 60);
constexpr auto INF = 2147483647LL;
constexpr auto PI = 3.1415926535897932384626433;
constexpr auto EPS = 1E-9;
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2> p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
auto printVector = []<typename T>(ostream& out, vector<T> v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
};
ll area(ll w, ll h) {
  if (w <= h) {
    return w * (w + 1) / 2;
  }
  ll ret = h * (h - 1) / 2;
  w -= (h - 1);
  ret += w * h;
  if (w % 2 == 0) {
    ret += (w - 1) / 2;
    w--;
  }
  ret += (w - 1) * w / 2 / 2;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  ll n, h;
  cin >> n >> h;
  ll l = 0, r = 2e9;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (area(mid, h) >= n) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
  return 0;
}
