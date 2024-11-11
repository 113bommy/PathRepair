#include <bits/stdc++.h>
using namespace std;
int a[26][26];
vector<string> b;
int i, j, k, n, m, ii, jj;
int sum(int i, int j, int ii, int jj) {
  int res = 0;
  for (int k = i; k <= ii; k++)
    for (int kk = j; kk <= jj; kk++) res += a[k][kk];
  return res;
}
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    string str;
    cin >> str;
    b.push_back(str);
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      a[i][j] = b[i - 1][j - 1] - '0';
    }
  int res = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      for (ii = i; ii <= n; ii++)
        for (jj = j; jj <= m; jj++)
          if (sum(i, j, ii, jj) == 0)
            if (2 * (ii - i + 1) + 2 * (jj - j + 1) - 2 > res) {
              res = 2 * (ii - i + 1) + 2 * (jj - j + 1);
            }
  cout << res;
  return 0;
}
