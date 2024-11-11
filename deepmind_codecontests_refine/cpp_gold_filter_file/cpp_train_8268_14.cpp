#include <bits/stdc++.h>
using namespace std;
int state[1005][1005];
int L[1005][1005];
int R[1005][1005];
int n, m, q;
void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << L[i][j] << " ";
    cout << endl;
  }
  cout << "****" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << R[i][j] << " ";
    cout << endl;
  }
  cout << "****" << endl;
}
int main() {
  cin >> n >> m >> q;
  memset(L, 0, sizeof(L));
  memset(R, 0, sizeof(R));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &state[i][j]);
      L[i][j] = R[i][j] = state[i][j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (state[i][j]) {
        L[i][j] = L[i][j - 1] + 1;
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--) {
      if (state[i][j]) {
        R[i][j] = R[i][j + 1] + 1;
      }
    }
  while (q--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if (op == 1) {
      state[x][y] = 1 - state[x][y];
      if (state[x][y] == 0) {
        L[x][y] = R[x][y] = 0;
      } else {
        L[x][y] = L[x][y - 1] + 1;
        R[x][y] = R[x][y + 1] + 1;
      }
      for (int i = y - 1; i >= 1 && state[x][i]; i--) R[x][i] = R[x][i + 1] + 1;
      for (int i = y + 1; i <= m && state[x][i]; i++) L[x][i] = L[x][i - 1] + 1;
    } else {
      int ans = 0;
      int width = 0x3f3f3f3f;
      for (int i = x, j = x; i >= 1 && j <= n;) {
        width = min(width, min(L[i][y], L[j][y]));
        ans = max(ans, width * (j - i + 1));
        if (j < n && i > 1) {
          if (L[i - 1][y] > L[j + 1][y])
            i--;
          else
            j++;
        } else if (j < n)
          j++;
        else
          i--;
      }
      width = 0x3f3f3f3f;
      for (int i = x, j = x; i >= 1 && j <= n;) {
        width = min(width, min(R[i][y], R[j][y]));
        ans = max(ans, width * (j - i + 1));
        if (j < n && i > 1) {
          if (R[i - 1][y] > R[j + 1][y])
            i--;
          else
            j++;
        } else if (j < n)
          j++;
        else
          i--;
      }
      int Lwidth = 0x3f3f3f3f;
      int Rwidth = 0x3f3f3f3f;
      for (int i = x; i <= n; i++) {
        Lwidth = min(Lwidth, L[i][y]);
        Rwidth = min(Rwidth, R[i][y]);
        ans = max(ans, (Lwidth + Rwidth - 1) * (i - x + 1));
      }
      Lwidth = 0x3f3f3f3f;
      Rwidth = 0x3f3f3f3f;
      for (int i = x; i >= 1; i--) {
        Lwidth = min(Lwidth, L[i][y]);
        Rwidth = min(Rwidth, R[i][y]);
        ans = max(ans, (Lwidth + Rwidth - 1) * (x - i + 1));
      }
      cout << ans << endl;
    }
  }
}
