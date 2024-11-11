#include <bits/stdc++.h>
using namespace std;
string s[101][2];
int n, m;
int main() {
  cin >> n;
  m = 0;
  for (int i = 1; i <= n; i++) {
    bool mark = true;
    m++;
    cin >> s[i][0] >> s[i][1];
    for (int j = 1; j < m; j++)
      if ((s[m][0] == s[j][0]) && (s[m][1] == s[j][1])) {
        mark = false;
        break;
      }
    if (!mark) {
      m--;
    }
  }
  cout << m << endl;
  return 0;
}
