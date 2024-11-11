#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int mx = -1e9;
  string ans;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int p, m, a, b, c, d, e;
    cin >> p >> m >> a >> b >> c >> d >> e;
    int t = a + b + c + d + e + (p * 100) - (m * 50);
    if (t >= mx) {
      mx = t;
      ans = s;
    }
  }
  cout << ans;
}
