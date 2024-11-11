#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
const int nmax = 5000;
string s;
int n, m, k, ans[nmax];
int main() {
  cin >> n >> m >> k;
  getline(cin, s);
  getline(cin, s);
  for (int i = 1; i < n; i++) {
    getline(cin, s);
    for (int j = 0; j < m; j++) {
      if (s[j] == 'R') {
        if (i + j < m) ans[i + j]++;
      } else if (s[j] == 'L') {
        if (j - i >= 0) ans[j - i]++;
      } else if (s[j] == 'U') {
        if (i % 2 == 0) ans[j]++;
      }
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
}
