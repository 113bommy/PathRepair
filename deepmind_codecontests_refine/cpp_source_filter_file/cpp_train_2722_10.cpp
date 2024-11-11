#include <bits/stdc++.h>
using namespace std;
int n;
bool a[51][51];
bool d[51];
char x;
int main() {
  int kq = 1;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> x;
      if (x == '.')
        a[i][j] = false;
      else
        a[i][j] = true;
    }
  for (int i = 1; i <= n - 2; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] == false) {
        if (a[i + 1][j - 1] || a[i + 1][j] || a[i + 1][j + 1] || a[i + 2][j]) {
          cout << "NO";
          return 0;
        } else {
          a[i][j] = true;
          a[i + 1][j - 1] = true;
          a[i + 1][j] = true;
          a[i + 1][j + 1] = true;
          a[i + 2][j] = true;
        }
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] == false) {
        cout << "NO";
        return 0;
      }
  if (kq = 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
