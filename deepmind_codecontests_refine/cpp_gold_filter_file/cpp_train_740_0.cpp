#include <bits/stdc++.h>
using namespace std;
int n, fv[1005], v[405], sol[25][25];
int main() {
  int i, impar = 0, j;
  cin >> n;
  for (i = 1; i <= n * n; i++) {
    cin >> v[i];
    fv[v[i]]++;
  }
  for (i = 1; i <= 1000; i++)
    if (fv[i] % 2 == 1) impar++;
  if (impar != 0 && n % 2 == 0) {
    cout << "NO";
    return 0;
  }
  if (n % 2 == 0) {
    for (i = 1; i <= 1000; i++)
      if (fv[i] % 4 != 0) {
        cout << "NO";
        return 0;
      }
    cout << "YES" << '\n';
    int x = 1, y = 1;
    for (i = 1; i <= 1000; i++) {
      while (fv[i] != 0) {
        sol[x][y] = i;
        sol[x][n - y + 1] = i;
        sol[n - x + 1][y] = i;
        sol[n - x + 1][n - y + 1] = i;
        fv[i] -= 4;
        y++;
        if (y == n / 2 + 1) y = 1, x++;
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) cout << sol[i][j] << " ";
      cout << '\n';
    }
  } else {
    for (i = 1; i <= 1000; i++)
      if (fv[i] % 2 == 1) {
        sol[n / 2 + 1][n / 2 + 1] = i;
        fv[i]--;
        break;
      }
    if (n == 1) {
      cout << "YES" << '\n';
      cout << sol[1][1];
      return 0;
    }
    int x = 1, y = 1;
    for (i = 1; i <= 1000; i++)
      if (fv[i] >= 4) {
        while (fv[i] >= 4) {
          sol[x][y] = i;
          sol[x][n - y + 1] = i;
          sol[n - x + 1][y] = i;
          sol[n - x + 1][n - y + 1] = i;
          fv[i] -= 4;
          y++;
          if (y == (n / 2 + 1)) y = 1, x++;
          if (x == (n / 2 + 1)) break;
        }
        if (x == (n / 2 + 1)) break;
      }
    x = 1;
    for (i = 1; i <= 1000; i++) {
      while (fv[i] >= 2) {
        sol[x][n / 2 + 1] = i;
        sol[n - x + 1][n / 2 + 1] = i;
        fv[i] -= 2;
        x++;
        if (x == (n / 2 + 1)) break;
      }
      if (x == (n / 2 + 1)) break;
    }
    x = 1;
    for (i = 1; i <= 1000; i++)
      while (fv[i] >= 2) {
        sol[n / 2 + 1][x] = i;
        sol[n / 2 + 1][n - x + 1] = i;
        fv[i] -= 2;
        x++;
        if (x == (n / 2 + 1)) {
          for (i = 1; i <= 1000; i++)
            if (fv[i] != 0) {
              cout << "NO";
              return 0;
            }
          cout << "YES" << '\n';
          for (j = 1; j <= n; j++) {
            for (int co = 1; co <= n; co++) cout << sol[j][co] << " ";
            cout << '\n';
          }
          return 0;
        }
      }
    cout << "NO";
  }
  return 0;
}
