#include <bits/stdc++.h>
using namespace std;
const int N = 201;
int n, m, T, k, flag;
int a[N][N];
inline int read() {
  char C = getchar();
  int F = 1, ANS = 0;
  while (C < '0' || C > '9') {
    if (C == '-') F = -1;
    C = getchar();
  }
  while (C >= '0' && C <= '9') {
    ANS = ANS * 10 + C - '0';
    C = getchar();
  }
  return F * ANS;
}
void print(int x) {
  if (flag == 0) return;
  if (x == 0) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char y = a[i][j] + 'a' - 1;
        cout << y;
      }
      cout << endl;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char y = a[j][i] + 'a' - 1;
        cout << y;
      }
      cout << endl;
    }
  }
}
void f(int x, int y, int z) {
  if (x % 2 == 1) {
    if (z < y / 2) {
      cout << "NO\n";
      return;
    }
    if ((z - y / 2) % 2 == 1) {
      cout << "NO\n";
      return;
    } else {
      int tot = 1;
      for (int i = 1; i <= y; i += 2) {
        a[1][i] = a[1][i + 1] = tot;
        tot = 3 - tot;
      }
      z -= y / 2;
      for (int i = 1; i <= y; i += 2) {
        if (z > x - 1) {
          int tot = 4;
          if (i % 4 == 3) tot = 6;
          for (int j = 2; j <= x; j++) {
            a[j][i] = tot, a[j][i + 1] = tot;
            tot = tot ^ 1;
          }
          z -= (x - 1);
        } else {
          int tot = 4;
          if (i % 4 == 3) tot = 6;
          for (int j = 2; j <= z + 1; j++) {
            a[j][i] = tot, a[j][i + 1] = tot;
            tot = tot ^ 1;
          }
          break;
        }
      }
      cout << "YES\n";
    }
  } else {
    if (z % 2 == 1) {
      cout << "NO\n";
      return;
    } else {
      cout << "YES\n";
      for (int i = 1; i <= y; i += 2) {
        if (z > x) {
          int tot = 4;
          if (i % 4 == 3) tot = 6;
          for (int j = 1; j <= x; j++) {
            a[j][i] = tot, a[j][i + 1] = tot;
            tot = tot ^ 1;
          }
          z -= x;
        } else {
          int tot = 4;
          if (i % 4 == 3) tot = 6;
          for (int j = 1; j <= z; j++) {
            a[j][i] = tot, a[j][i + 1] = tot;
            tot = tot ^ 1;
          }
          break;
        }
      }
    }
  }
  flag = 1;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      if (a[i][j] == 0) {
        int u = 10;
        if (j % 2 == 0) u++;
        if (i % 4 <= 1) u += 2;
        a[i][j] = u, a[i + 1][j] = u;
      }
    }
  }
}
void work() {
  memset(a, 0, sizeof(a));
  flag = 0;
  n = read(), m = read(), k = read();
  int p = n * m / 2 - k;
  if (m % 2 == 0) {
    f(n, m, k);
    print(0);
  } else {
    f(m, n, p);
    print(1);
  }
  return;
}
int main() {
  T = read();
  while (T--) {
    work();
  }
  return 0;
}
