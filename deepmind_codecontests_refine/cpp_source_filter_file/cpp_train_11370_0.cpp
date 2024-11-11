#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 65;
const int mod = 1000000007;
string s[maxn];
int main() {
  ios::sync_with_stdio(false);
  int T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int numa = 0;
    int numx1 = 0, numx2 = 0, numy1 = 0, numy2 = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'A') numa++;
        if (s[i][j] == 'A' && i == 0) numx1++;
        if (s[i][j] == 'A' && i == n - 1) numx2++;
        if (s[i][j] == 'A' && j == 0) numy1++;
        if (s[i][j] == 'A' && j == m - 1) numy2++;
      }
    }
    if (numa == 0)
      cout << "MORTAL\n";
    else if (numa == n * m)
      cout << "0\n";
    else if (numx1 == m || numx2 == m || numy1 == n || numy2 == n)
      cout << "1\n";
    else if (numx1 == 0 || numx2 == 0 || numy1 == 0 || numy2 == 0)
      cout << "4\n";
    else {
      int flag = 0;
      int start = -1, end = m, x;
      for (int k = 0; k < 2; k++) {
        if (k == 0)
          x = 0;
        else
          x = n - 1;
        for (int i = 0; i < m; i++) {
          if (s[x][i] == 'P' && start == -1) start = i;
          if (s[x][i] == 'P') end = i;
        }
        for (int i = 0; i < n; i++) {
          int num = 0;
          for (int j = start; j <= end; j++) {
            if (s[i][j] == 'A') num++;
          }
          if (num == end - start + 1) {
            flag = 1;
            break;
          }
        }
      }
      start = -1, end = n;
      for (int k = 0; k < 2; k++) {
        if (k == 0)
          x = 0;
        else
          x = m - 1;
        for (int i = 0; i < n; i++) {
          if (s[i][x] == 'P' && start == -1) start = i;
          if (s[i][x] == 'P') end = i;
        }
        for (int i = 0; i < m; i++) {
          int num = 0;
          for (int j = start; j <= end; j++) {
            if (s[j][i] == 'A') num++;
          }
          if (num == end - start + 1) {
            flag = 1;
            break;
          }
        }
      }
      if (s[0][0] == 'A' || s[0][m - 1] == 'A' || s[n - 1][0] == 'A' ||
          s[n - 1][m - 1] == 'A') {
        flag = 1;
      }
      if (flag == 1)
        cout << "2\n";
      else
        cout << "3\n";
    }
  }
  return 0;
}
