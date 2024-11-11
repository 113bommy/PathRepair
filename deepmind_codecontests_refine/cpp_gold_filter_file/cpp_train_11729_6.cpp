#include <bits/stdc++.h>
using namespace std;
string s[3];
long long a[3][55], b[3];
int main() {
  long long i, j, k, p, q, m, n;
  cin >> n;
  for (i = 0; i < 3; i++) {
    cin >> s[i];
    for (j = 0; s[i][j]; j++) {
      if (s[i][j] >= 'A' && s[i][j] <= 'Z')
        a[i][s[i][j] - 'A']++;
      else
        a[i][s[i][j] - 'a' + 26]++;
    }
  }
  if (s[0].size() == 1) {
    cout << "Draw" << endl;
    return 0;
  }
  for (i = 0; i < 3; i++) {
    for (k = 0; k < 52; k++) {
      p = a[i][k];
      if (p == s[i].size() && n == 1) {
        b[i] = max(b[i], p - 1);
        continue;
      }
      q = p + n;
      if (q > s[i].size()) q = s[i].size();
      b[i] = max(b[i], q);
    }
  }
  if (b[0] > b[1] && b[0] > b[2])
    cout << "Kuro" << endl;
  else if (b[1] > b[2] && b[1] > b[0])
    cout << "Shiro" << endl;
  else if (b[2] > b[0] && b[2] > b[1])
    cout << "Katie" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
