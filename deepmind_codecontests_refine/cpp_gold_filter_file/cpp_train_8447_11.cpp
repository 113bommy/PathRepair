#include <bits/stdc++.h>
using namespace std;
const int maxn = 204;
void inv_col(int a[][maxn], int col, int n) {
  for (int i = 0; i < n; i++) a[i][col] ^= 1;
}
void inv_row(int a[][maxn], int row, int m) {
  for (int i = 0; i < m; i++) a[row][i] ^= 1;
}
int b[maxn][maxn];
int a[maxn][maxn];
int main(void) {
  int n, m;
  while (cin >> n >> m) {
    bool has_ans = false;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> b[i][j];
    for (int cnt0 = 0; cnt0 <= m; cnt0++) {
      memcpy(a, b, sizeof(a));
      string r(n, '0');
      string c(m, '0');
      for (int i = 0; i < m; i++) {
        if ((i < cnt0 && a[0][i] == 1) || (i >= cnt0 && a[0][i] == 0)) {
          inv_col(a, i, n);
          c[i] = '1';
        }
      }
      bool ok = true;
      if (cnt0 < m) {
        for (int i = 1; i < n; i++) {
          int sum = accumulate(a[i], a[i] + m, 0);
          if (sum != 0 && sum != m) {
            ok = false;
            break;
          } else if (sum == 0) {
            inv_row(a, i, m);
            r[i] = '1';
          }
        }
      } else {
        int idx = -1;
        for (int i = 1; i < n; i++) {
          int sum = accumulate(a[i], a[i] + m, 0);
          if (sum != 0 && sum != m) {
            if (idx == -1)
              idx = i;
            else {
              ok = false;
              break;
            }
          }
        }
        if (!ok) continue;
        if (idx == -1) {
          for (int i = 1; i < n; i++) {
            if (!a[i][0]) {
              inv_row(a, i, m);
              r[i] = '1';
            }
          }
        } else {
          if (a[idx][0]) {
            inv_row(a, idx, m);
            r[idx] = '1';
          }
          for (int i = 1; i < m; i++)
            if (a[idx][i] < a[idx][i - 1]) {
              ok = false;
              break;
            }
          if (!ok) continue;
          for (int i = 1; i < idx; i++) {
            if (a[i][0]) {
              inv_row(a, i, m);
              r[i] = '1';
            }
          }
          for (int i = idx + 1; i < n; i++) {
            if (!a[i][0]) {
              inv_row(a, i, m);
              r[i] = '1';
            }
          }
        }
      }
      if (ok) {
        cout << "YES" << endl << r << endl << c << endl;
        has_ans = true;
        break;
      }
    }
    if (!has_ans) cout << "NO" << endl;
  }
  return 0;
}
