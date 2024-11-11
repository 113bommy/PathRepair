#include <bits/stdc++.h>
using namespace std;
char s1[200010], s2[200010];
int c[271][271];
long long n, i, j, k, ans;
int main() {
  cin >> n;
  cin >> s1;
  cin >> s2;
  ans = 0;
  memset(c, 0, sizeof(c));
  for (i = 0; i <= n - 1; i++)
    if (s1[i] != s2[i]) {
      ans++;
      c[s1[i] - 'a' + 1][s2[i] - 'a' + 1] = i + 1;
    }
  for (i = 1; i <= 26; i++)
    for (j = i + 1; j <= 26; j++)
      if (c[i][j] * c[j][i] != 0) {
        cout << ans - 2 << endl;
        cout << c[i][j] << ' ' << c[j][i] << endl;
        return 0;
      }
  for (i = 1; i <= 26; i++)
    for (j = i + 1; j <= 26; j++) {
      if (c[i][j] != 0) {
        for (k = 1; k <= 26; k++)
          if (c[k][i] != 0) {
            cout << ans - 1 << endl;
            cout << c[k][i] << ' ' << c[i][j] << endl;
            return 0;
          }
      }
    }
  cout << ans << endl;
  ;
  cout << "-1 -1" << endl;
  return 0;
}
