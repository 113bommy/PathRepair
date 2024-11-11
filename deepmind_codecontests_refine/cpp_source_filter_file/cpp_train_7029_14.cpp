#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int inf = 1e9;
const int N = 4e5;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int MOD = 1e9 + 7;
string s[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  int ans = 6;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int cnt = 0;
      for (int k = 0; k < 6; ++k) cnt += s[i][k] == s[j][k];
      cnt = (6 - cnt) / 2 - 1;
      if (cnt < 0) cnt = 0;
      ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}
