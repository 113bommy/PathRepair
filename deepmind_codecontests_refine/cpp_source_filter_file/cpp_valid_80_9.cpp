#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
const double pie = 2 * acos(0.0);
void solve() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (i >= n / 2) {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
        return;
      } else {
        cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
        return;
      }
    }
  }
  cout << 1 << " " << n / 2 << " " << 1 << " " << n / 2 * 2 << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
