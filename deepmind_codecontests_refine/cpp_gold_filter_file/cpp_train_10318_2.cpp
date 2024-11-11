#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long double eps = 1e-7;
int mark[120];
int mark2[120];
int s[120];
char ans[120];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    mark[s[i]]++;
  }
  int o = 0, m = 0;
  for (int i = 1; i <= 100; i++) {
    if (mark[i] == 1) o++;
    if (mark[i] > 2) m++;
  }
  for (int i = 0; i <= 110; i++) ans[i] = 'k';
  if (o % 2 == 1 && m == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if (o % 2 == 1 && m > 0) {
    int flg = 0;
    for (int i = 1; i <= n; i++)
      if (mark[s[i]] == 1) {
        if (flg == 0)
          ans[i] = 'A';
        else
          ans[i] = 'B';
        flg = 1 - flg;
      }
    for (int i = 1; i <= n; i++)
      if (mark[s[i]] > 2) {
        if (flg == 0) {
          ans[i] = 'A';
          for (int j = i + 1; j <= n; j++)
            if (s[j] == s[i]) ans[j] = 'B';
        } else {
          ans[i] = 'B';
          for (int j = i + 1; j <= n; j++)
            if (s[j] == s[i]) ans[j] = 'A';
        }
        break;
      }
    for (int i = 1; i <= n; i++)
      if (ans[i] == 'k') ans[i] = 'A';
  }
  if (o % 2 == 0) {
    int flg = 0;
    for (int i = 1; i <= n; i++)
      if (mark[s[i]] == 1) {
        if (flg == 0)
          ans[i] = 'A';
        else
          ans[i] = 'B';
        flg = 1 - flg;
      }
    for (int i = 1; i <= n; i++)
      if (ans[i] == 'k') ans[i] = 'A';
  }
  for (int i = 1; i <= n; i++) cout << ans[i];
  cout << endl;
  return 0;
}
