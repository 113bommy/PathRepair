#include <bits/stdc++.h>
using namespace std;
int countbomb(int i, int j, char A[][102]) {
  int t = 0;
  char c = '*';
  for (int l = i - 1; l <= i + 1; l++)
    for (int m = j - 1; m <= j + 1; m++) {
      if (l == i && m == j) continue;
      if (A[l][m] == c) t++;
    }
  return t;
}
int main() {
  int n, m;
  cin >> n >> m;
  char A[102][102];
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) A[i][j] = '0';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> A[i][j];
    }
  bool result = true;
  for (int i = 1; i <= n && result == true; i++)
    for (int j = 1; j <= m && result == true; j++) {
      int mine = countbomb(i, j, A);
      if (A[i][j] == '*')
        continue;
      else if (A[i][j] == '.') {
        if (mine != 0) result = false;
      } else {
        int num = A[i][j] - 48;
        if (mine != num) result = false;
      }
    }
  if (result)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
