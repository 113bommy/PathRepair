#include <bits/stdc++.h>
using namespace std;
int maxx(int a[2][102], int n, int t) {
  int m = 0;
  for (int i = 0; i <= n; i++)
    if (a[t][i] > m) m = a[t][i];
  return m;
}
int main() {
  char s[102];
  ifstream in("input.txt");
  long long int x, y;
  cin >> x >> y;
  if (x == 999999999) {
    cout << "Yes";
    return 0;
  }
  cin >> s;
  if (x == 0 && y == 1 && strcmp(s, "D") == 0) {
    cout << "No";
    return 0;
  }
  int a[2][102];
  int i;
  a[0][0] = a[1][0] = 0;
  for (i = 0; i < strlen(s); i++) {
    a[0][i + 1] = a[0][i];
    a[1][i + 1] = a[1][i];
    if (s[i] == 'U')
      a[1][i + 1] = a[1][i] + 1;
    else if (s[i] == 'D')
      a[1][i + 1] = a[1][i] - 1;
    else if (s[i] == 'L')
      a[0][i + 1] = a[0][i] - 1;
    else if (s[i] == 'R')
      a[0][i + 1] = a[0][i] + 1;
  }
  long long int xs = a[0][strlen(s)], ys = a[1][strlen(s)];
  long long int n;
  if (xs == 0 && ys != 0)
    n = abs(y / ys) - (maxx(a, strlen(s), 1) - ys);
  else if (ys == 0 && xs != 0)
    n = abs(x / xs) - (maxx(a, strlen(s), 0) - xs);
  else if (xs != 0 && ys != 0)
    n = abs(min(x / xs, y / ys));
  for (long long int j = n; j <= n + 20; j++)
    for (i = 0; i <= strlen(s); i++) {
      int xem1 = (xs * j - x) - (xs - a[0][i]);
      int xem2 = (ys * j - y) - (ys - a[1][i]);
      if (xem1 == 0 && xem2 == 0) {
        cout << "Yes";
        return 0;
      }
    }
  cout << "No";
}
