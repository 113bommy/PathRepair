#include <bits/stdc++.h>
using namespace std;
const long long MaxN = 1e5 + 5;
const long long INF = 2e18;
const long long MOD = 1e9 + 7;
const double eps = 1e-5;
const double pi = acos(-1);
template <class T>
istream &operator>>(istream &s, vector<T> &a) {
  for (T &x : a) s >> x;
  return s;
}
template <class T>
ostream &operator<<(ostream &s, vector<T> a) {
  for (T &x : a) s << x << ' ';
  return s;
}
void solve() {
  int n;
  long long h;
  cin >> n >> h;
  vector<long long> a(n);
  cin >> a;
  long long l = 1;
  long long r = INF;
  a.push_back(INF);
  while (l < r) {
    long long m = l + (r - l) / 2;
    long long check = 0;
    for (int i = 0; i < n; ++i) {
      check += min(m, a[i + 1] - a[i]);
    }
    if (check < h)
      l = m + 1;
    else
      r = m;
  }
  cout << l << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
