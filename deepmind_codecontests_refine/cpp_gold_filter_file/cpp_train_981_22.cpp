#include <bits/stdc++.h>
using namespace std;
int ans[2010];
int main() {
  int n, m, k;
  string s;
  char x;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) ans[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      x = s[j];
      if (x == 'U') {
        if (i % 2 == 0) ans[j]++;
      } else if (x == 'R') {
        if (j + i < m) ans[j + i]++;
      } else if (x == 'L') {
        if (j - i >= 0) ans[j - i]++;
      }
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
