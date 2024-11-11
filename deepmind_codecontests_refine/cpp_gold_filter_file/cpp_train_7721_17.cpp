#include <bits/stdc++.h>
using namespace std;
int n, m, f[1009], a[1009];
long long ans = 0;
string s[1009];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  for (char i = 'A'; i <= 'E'; ++i) {
    for (int x = 0; x < m; ++x) {
      int cnt = 0;
      for (int y = 1; y <= n; ++y) {
        if (i == s[y][x]) ++cnt;
      }
      f[x] = max(f[x], cnt);
    }
  }
  for (int i = 0; i < m; ++i) ans += f[i] * a[i];
  cout << ans;
  return 0;
}
