#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[205][205];
int row[205];
int col[205];
bool solve(int x, int y) {
  if (x == 1) {
    for (int i = 1; i <= y; i++) {
      if (a[1][i] != 0) {
        col[i] = 1;
      } else
        col[i] = 0;
    }
    for (int i = y + 1; i <= m; i++) {
      if (a[1][i] != 1) {
        col[i] = 1;
      } else
        col[i] = 0;
    }
    bool judge = true;
    for (int i = 2; i <= n; i++) {
      int sum = 0;
      for (int j = 1; j <= m; j++) {
        sum += a[i][j] ^ col[j];
      }
      if (sum == 0)
        row[i] = 1;
      else if (sum == m)
        row[i] = 0;
      else
        return false;
    }
    return true;
  } else if (x >= 2) {
    for (int i = 1; i <= m; i++) {
      col[i] = a[1][i] ^ 0;
    }
    for (int i = 2; i < x; i++) {
      int sum = 0;
      for (int j = 1; j <= m; j++) {
        sum += a[i][j] ^ col[j];
      }
      if (sum == 0)
        row[i] = 0;
      else if (sum == m)
        row[i] = 1;
      else
        return false;
    }
    int sum1 = 0, sum2 = 0;
    for (int j = 1; j <= y; j++) {
      sum1 += a[x][j] ^ col[j];
    }
    for (int j = y + 1; j <= m; j++) {
      sum2 += a[x][j] ^ col[j];
    }
    if (sum1 == 0 && sum2 == m - y) {
      row[x] = 0;
    } else if (sum1 == y && sum2 == 0) {
      row[x] = 1;
    } else
      return false;
    for (int i = x + 1; i <= n; i++) {
      int sum = 0;
      for (int j = 1; j <= m; j++) {
        sum += a[i][j] ^ col[j];
      }
      if (sum == 0)
        row[i] = 1;
      else if (sum == m)
        row[i] = 0;
      else
        return false;
    }
    return true;
  }
}
void print() {
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    printf("%d", row[i]);
  }
  printf("\n");
  for (int j = 1; j <= m; j++) {
    printf("%d", col[j]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  bool judge = false;
  for (int i = 1; i <= n; i++) {
    if (judge) break;
    for (int j = 1; j <= m; j++) {
      if (solve(i, j)) {
        print();
        judge = true;
        break;
      }
    }
  }
  if (!judge) {
    printf("NO\n");
  }
}
