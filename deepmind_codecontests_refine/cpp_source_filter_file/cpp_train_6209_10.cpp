#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const long long int INF = 1e18;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int cas = 1;
void solve() {
  string a, b;
  while (cin >> a >> b) {
    string ans = "";
    ans += a[0];
    for (int i = 1; i < a.size(); i++) {
      if (a[i] < a[i - 1])
        ans += a[i];
      else
        break;
    }
    ans += b[0];
    cout << ans << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
