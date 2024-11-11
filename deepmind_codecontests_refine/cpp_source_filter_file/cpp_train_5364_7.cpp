#include <bits/stdc++.h>
const int inf = (int)1e9;
using namespace std;
int n, m;
string s[100011];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  long double x = 0;
  long double ans = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == "halfplus") {
      x += 0.5;
    }
    ans += x * m;
    x *= 2;
  }
  cout << ans;
  return 0;
}
