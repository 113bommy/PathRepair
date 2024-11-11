#include <bits/stdc++.h>
using namespace std;
short c1[25001], c2[25001];
int a[12][12];
int main() {
  int n, m, res = 0;
  cin >> n >> m;
  char c;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c == 'W')
        a[i][j] = 2;
      else if (c == 'P')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == 2) {
        if (a[max(i - 1, 0)][j] == 1) {
          res++;
          a[max(i - 1, 0)][j] = 0;
          continue;
        }
        if (a[i][max(j - 1, 0)] == 1) {
          a[i][max(j - 1, 0)] = 0;
          res++;
          continue;
        }
        if (a[i - 1][j] == 1) {
          res++;
          a[i - 1][j] = 0;
          continue;
        }
        if (a[i][j + 1] == 1) {
          a[i][j + 1] = 0;
          res++;
        }
      }
  cout << res;
  return 0;
}
