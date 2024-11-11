#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int main() {
  int n, m;
  cin >> n >> m;
  char s[n + 5][m + 5];
  for (int i = 0; i < n; i++) cin >> s[i];
  long long int ans = 1;
  for (int j = 0; j < m; j++) {
    map<char, int> m;
    for (int i = 0; i < n; i++) {
      m[s[i][j]] = 1;
    }
    ans = ((ans % mod) * (m.size() % mod)) % mod;
  }
  cout << ans << endl;
  return 0;
}
