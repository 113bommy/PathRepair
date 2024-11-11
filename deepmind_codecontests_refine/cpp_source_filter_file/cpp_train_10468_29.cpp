#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e10;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  char c = s[0];
  long long int a = s[1] - '0';
  long long int ans = 0;
  for (long long int i = -1; i <= 1; i++) {
    for (long long int j = -1; j <= 1; j++) {
      if (i == j && i == 1) continue;
      if ((char)(c + i) <= 'h' && (char)(c + i) >= 'a') {
        if (a + j >= 1 && a + j <= 8) ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
