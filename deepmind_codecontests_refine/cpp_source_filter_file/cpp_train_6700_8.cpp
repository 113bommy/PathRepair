#include <bits/stdc++.h>
using namespace std;
int a[102][10002];
int res[102][10002];
int min(int a, int b) {
  if (a <= b)
    return a;
  else
    return b;
}
int main() {
  int n, m, temp, res1, res2, l;
  bool flag = true;
  cin >> n >> m;
  char ch = ' ';
  for (int i = 1; i <= n; i++) {
    temp = 0;
    for (int j = 1; j <= m; j++) {
      cin >> ch;
      a[i][j] = int(ch) - 48;
      if (a[i][j] == 1) temp++;
    }
    flag = flag && (temp > 0);
  }
  if (!flag)
    cout << -1 << endl;
  else {
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= m + 1; j++)
        if (a[i][j] == 0)
          res[i][j] = 100000;
        else
          res[i][j] = 0;
    for (int i = 1; i <= n; i++) {
      for (int m = 1; m <= 2; m++) {
        int numb = 0;
        for (int j = 1; j <= m; j++) {
          if (j <= m / 2) {
            l = m - j + 1;
            res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            res[i][j] = min(res[i][j], res[i][l] + m - l + j);
          } else {
            l = m - j + 1;
            res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            res[i][j] = min(res[i][j], res[i][l] + m - j + l);
          }
        }
        for (int j = m; j >= 1; j--) {
          if (j >= m / 2) {
            l = m - j + 1;
            res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            res[i][j] = min(res[i][j], res[i][l] + m - j + l);
          } else {
            l = m - j + 1;
            res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            res[i][j] = min(res[i][j], res[i][l] + m - l + j);
          }
        }
      }
    }
  }
  int result = 10000000000000, resulttemp = 0;
  if (flag) {
    for (int j = 1; j <= m; j++) {
      resulttemp = 0;
      for (int i = 1; i <= n; i++) resulttemp += res[i][j];
      result = min(result, resulttemp);
    }
    cout << result << endl;
  }
  return 0;
}
