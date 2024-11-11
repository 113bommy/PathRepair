#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e9;
const long long inf = (long long)1e18;
const long double eps = (long double)1e-6;
const long long mod = (long long)1e9 + 7;
const long long MAXN = 1000;
const long long MAXLOG = 19;
const long long maxlen = (long long)1e5;
const long long asci = (long long)256;
const long long block = 707;
long long precalc[block][block];
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (T &cnt : arr) {
    in >> cnt;
  }
  return in;
};
void solve() {
  int q;
  cin >> q;
  vector<long long> a(500000);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    t--;
    if (!t) {
      for (int i = 1; i < block; ++i) {
        precalc[i][x % i] += y;
      }
      a[x - 1] += y;
    } else {
      if (x < block)
        cout << precalc[x][y] << "\n";
      else {
        long long ans = 0;
        for (int i = y; i <= 500000; i += x) {
          if (i >= 1) ans += a[i - 1];
        }
        cout << ans << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
