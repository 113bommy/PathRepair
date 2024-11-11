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
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& x : v) in >> x;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> v) {
  for (int i = 0; i < v.size(); i++)
    out << v[i] << (i + 1 == v.size() ? '\n' : ' ');
  out.flush();
  return out;
}
int n, m;
ll cnt[1010], sqcnt[1010];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= min(n, m); i++) {
    cnt[i] = (n - i) / m + 1;
    if (i * i % m)
      sqcnt[i * i % m] += cnt[i];
    else
      sqcnt[m] += cnt[i];
  }
  ll res = 0;
  for (int i = 1; i <= m; i++) {
    res += cnt[i] * sqcnt[-i * i % m + m];
  }
  cout << res << endl;
  return 0;
}
