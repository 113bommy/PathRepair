#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[101];
  int a[1000] = {}, b[1000] = {};
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == 'E') a[j]++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[j][i] == 'E') b[j]++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i] == n && b[j] == n) {
        cout << -1 << endl;
        return 0;
      }
  bool flag = false;
  for (int i = 0; i < n; i++)
    if (a[i] == n) flag = true;
  if (flag)
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] != 'E') {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
  else
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[j][i] != 'E') {
          cout << j + 1 << " " << i + 1 << endl;
          break;
        }
      }
    }
  return 0;
}
