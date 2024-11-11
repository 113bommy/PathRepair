#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
  out << "[" << p.first << ", " << p.second << "]"
      << "\n";
  return out;
}
const double EPS = 1e-10;
const int inf = 1e9 + 9;
const long long mod = 1e9 + 7;
const int maxN = 1e5 + 7;
const long long ONE = 1;
const long long evenBits = 0xaaaaaaaaaaaaaaaa;
const long long oddBits = 0x5555555555555555;
int n, a[maxN];
long long ans;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  a[0] = a[n + 1] = 0;
  for (int i = (1); i <= (n); ++i) {
    if (a[i - 1] < a[i]) {
      ans += (a[i] - a[i - 1]) * (n - a[i] + 1);
    } else if (a[i - 1] > a[i]) {
      ans += a[i] * (a[i - 1] - a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
