#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[] = {'z', 'a', 'e', 'i', 'o', 'u'};
int a[1010][1010];
int main() {
  cin >> n;
  for (int i = 5; i <= n; ++i) {
    if (n % i) continue;
    int x = i, y = n / i;
    if (x < 5 || y < 5) continue;
    a[1][1] = 1;
    a[1][2] = 2;
    a[1][3] = 3;
    a[1][4] = 4;
    a[1][5] = 5;
    a[2][1] = 2;
    a[2][2] = 3;
    a[2][3] = 4;
    a[2][4] = 5;
    a[2][5] = 1;
    a[3][1] = 3;
    a[3][2] = 4;
    a[3][3] = 5;
    a[3][4] = 1;
    a[3][5] = 2;
    a[4][1] = 4;
    a[4][2] = 5;
    a[4][3] = 1;
    a[4][4] = 2;
    a[4][5] = 3;
    a[5][1] = 5;
    a[5][2] = 1;
    a[5][3] = 2;
    a[5][4] = 3;
    a[5][5] = 4;
    for (int i = 6; i <= x; ++i)
      for (int j = 1; j <= 5; ++j) a[j][i] = j;
    for (int i = 6; i <= y; ++i)
      for (int j = 1; j <= 5; ++j) a[i][j] = j;
    for (int i = 1; i <= x; ++i)
      for (int j = 1; j <= y; ++j) cout << s[a[i][j]];
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
