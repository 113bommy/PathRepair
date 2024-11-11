#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  long long n, w, m;
  cin >> n >> w >> m;
  long long tot = n * w;
  vector<vector<pair<double, double>>> ans(m);
  long long beg = 0;
  long long y = 0;
  double each = (double)tot / m;
  double pre = each;
  double post = w;
  long long i;
  for (i = 0; i < m;) {
    if (false) cerr << y << " ";
    if ((y == 3) || beg >= n + 1) {
      if (false) cerr << beg << " " << y << endl;
      cout << "NO" << endl;
      return;
    }
    if (post < pre) {
      pre -= post;
      ans[i].push_back({beg + 1, post});
      beg++;
      post = w;
      y = 1;
    } else {
      post -= pre;
      ans[i].push_back({beg + 1, pre});
      pre = each;
      i++;
      y++;
    }
    if (post <= 1e-5) {
      post = w;
      beg++;
      y = 1;
    }
    if (pre == 0) {
      pre = each;
      i++;
    }
  }
  cout << "YES" << endl;
  for (long long i = 0; i < m; i++) {
    for (auto k : ans[i]) {
      cout << k.first << " " << k.second << " ";
    }
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL),
      cout << setprecision(14);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
