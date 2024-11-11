#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a[1111] = {}, b[11111] = {}, ans = 0, s[1001][1001] = {};
  string ss;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> ss;
    for (int j = 0; j < m; j++) {
      if (ss[j] == '*') {
        s[i][j] = 1;
        a[i]++;
        b[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 1) ans += (a[i] - 1) * (b[j] - 1);
    }
  }
  cout << ans;
  return 0;
}
