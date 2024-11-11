#include <bits/stdc++.h>
using namespace std;
bool ooo = 1;
struct Dbg {
  template <typename T>
  Dbg& operator,(const T& v) {
    cout << v << ", ";
    return *this;
  }
} Dbg;
using ll = long long;
struct _ {
  _() { ios_base::sync_with_stdio(0), cin.tie(0), ooo = 0; }
} _;
const int N = 250, mod = 1e9 + 7;
int n, m;
string a, b;
ll tmp = 1, res = 0, ans = 0;
int main() {
  cin >> n >> m >> a >> b;
  for (int i = 0; i < m; i++) {
    if (i < n && a[n - i - 1] == '1') {
      res = (res + tmp) % mod;
    }
    if (b[m - i - 1] == '1') {
      ans = (ans + res) % mod;
    }
    tmp <<= 1;
    if (tmp > mod) tmp -= mod;
  }
  cout << ans;
}
