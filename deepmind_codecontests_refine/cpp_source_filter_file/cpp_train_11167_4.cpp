#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS = 1e-8;
const int INF = 0x3F3F3F3F;
const ll LINF = 4611686018427387903;
const int MOD = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> able(k);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') able[i % k] |= 2;
      if (s[i] == '0') able[i % k] |= 1;
    }
    bool ok = true;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (able[i] == 3) {
        ok = false;
      }
      if (able[i] == 2)
        a++, b++;
      else if (able[i] == 0)
        a++;
    }
    if (k / 2 > a || k / 2 < b) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
