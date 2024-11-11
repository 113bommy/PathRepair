#include <bits/stdc++.h>
using namespace std;
int f[102][102];
int n, m;
void clear_(int a, int b) {
  if (f[b][a] <= f[a][b]) {
    f[a][b] = f[a][b] - f[b][a];
    f[b][a] = 0;
  } else if (f[a][b] <= f[b][a]) {
    f[b][a] = f[b][a] - f[a][b];
    f[a][b] = 0;
  }
}
void go(int x) {
  bool flag = false;
  int tmp1, tmp2, tmp3;
  for (int i = 1; i <= n; i++)
    if (f[x][i] != 0) {
      for (int j = 1; j <= n; j++)
        if ((f[i][j] != 0) && (j != x)) {
          flag = true;
          tmp1 = f[x][i];
          tmp2 = f[i][j];
          tmp3 = f[x][j];
          if (f[x][i] >= f[i][j]) {
            f[x][i] = tmp1 - tmp2;
            f[x][j] = f[x][j] + tmp2;
            f[i][j] = 0;
            clear_(x, i);
            clear_(x, j);
            clear_(i, j);
          }
          if (f[x][i] < f[i][j]) {
            f[x][i] = 0;
            f[x][j] = f[x][j] + tmp1;
            f[i][j] = f[i][j] - tmp1;
            clear_(x, i);
            clear_(i, j);
            clear_(x, j);
          }
        }
    }
  if (flag == true) go(x);
}
int main() {
  cin >> n >> m;
  int a, b, c;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    f[a][b] = c;
    clear_(a, b);
  }
  a = a;
  for (int i = 1; i <= n; i++) {
    go(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      ans = ans + f[i][j] + f[j][i];
    }
  cout << (ans / 2);
  return 0;
}
