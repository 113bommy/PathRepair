#include <bits/stdc++.h>
using namespace std;
int n, m, a[205][205], b[205][205];
void Read() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
}
void InverseR(int r) {
  for (int i = 1; i <= m; i++) {
    b[r][i] ^= 1;
  }
}
void InverseC(int c) {
  for (int i = 1; i <= n; i++) {
    b[i][c] ^= 1;
  }
}
void Solve() {
  for (int cnt = 0; cnt <= m; cnt++) {
    string row = "", col = "";
    for (int i = 1; i <= n; i++) {
      row += '0';
    }
    for (int i = 1; i <= m; i++) {
      col += '0';
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        b[i][j] = a[i][j];
      }
    }
    for (int i = 1; i <= cnt; i++) {
      if (b[1][i] == 1) {
        col[i - 1] = '1';
        InverseC(i);
      }
    }
    for (int i = cnt + 1; i <= m; i++) {
      if (b[1][i] == 0) {
        col[i - 1] = '1';
        InverseC(i);
      }
    }
    bool ok = 1;
    if (cnt < m) {
      for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
          sum += b[i][j];
        }
        if (sum != 0 && sum != m) {
          ok = 0;
          break;
        }
        if (sum == 0) {
          row[i - 1] = '1';
        }
      }
    } else {
      int idx = -1;
      for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
          sum += b[i][j];
        }
        if (sum != 0 && sum != m) {
          if (idx != -1) {
            ok = 0;
            break;
          } else {
            idx = i;
          }
        }
      }
      if (idx == -1) {
        for (int i = 2; i <= n; i++) {
          int sum = 0;
          for (int j = 1; j <= m; j++) {
            sum += b[i][j];
          }
          if (sum == 0) {
            row[i - 1] = '1';
          }
        }
      } else {
        for (int i = 1; i < idx; i++) {
          int sum = 0;
          for (int j = 1; j <= m; j++) {
            sum += b[i][j];
          }
          if (sum == m) {
            row[i - 1] = '1';
          }
        }
        if (b[idx][1] == 1) {
          InverseR(idx);
          row[idx] = '1';
        }
        for (int j = 2; j <= m; j++) {
          if (b[idx][j] < b[idx][j - 1]) {
            ok = 0;
            break;
          }
        }
        for (int i = idx + 1; i <= n; i++) {
          int sum = 0;
          for (int j = 1; j <= m; j++) {
            sum += b[i][j];
          }
          if (sum == 0) {
            row[i - 1] = '1';
          }
        }
      }
    }
    if (ok) {
      cout << "YES" << endl << row << endl << col << endl;
      return;
    }
  }
  printf("NO");
}
int main() {
  Read();
  Solve();
  return 0;
}
