#include <bits/stdc++.h>
using namespace std;
bool ma[101][101];
int m, n;
bool a[101][101];
int steluta(int i, int j) {
  int t = 1;
  while (j + t <= m && j - t >= 1 && i + t <= n && i - t >= 1 &&
         ma[i][j + t] == 1 && ma[i][j - t] == 1 && ma[i - t][j] == 1 &&
         ma[i + t][j] == 1) {
    a[i][j + t] = 1;
    a[i][j - t] = 1;
    a[i - t][j] = 1;
    a[i + t][j] = 1;
    t++;
  }
  t--;
  if (t) a[i][j] = 1;
  return t;
}
int main() {
  int i, j, ramas = 0, c = 0;
  char ch;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> ch;
      if (ch == '*') {
        ma[i][j] = 1;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (ma[i][j] == 1) {
        int val = steluta(i, j);
        if (val) {
          for (int w = 1; w <= val; w++) {
            c++;
          }
        }
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == 0 && ma[i][j] == 1) {
        ramas++;
      }
    }
  }
  if (ramas > 0) {
    cout << "-1";
  } else {
    cout << c << "\n";
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (ma[i][j] == 1) {
          int val = steluta(i, j);
          if (val) {
            for (int w = 1; w <= val; w++) {
              cout << i << " " << j << " " << w << "\n";
            }
          }
        }
      }
    }
  }
  return 0;
}
