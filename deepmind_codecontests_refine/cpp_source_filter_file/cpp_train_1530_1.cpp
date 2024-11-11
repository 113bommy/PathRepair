#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 5;
int m, n, c[N][N], sum[N][N];
char a[N][N];
void Input() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) cin >> (a[i] + 1);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == '1')
        c[i][j] = 1;
      else
        c[i][j] = 0;
    }
  }
}
void Sum() {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + c[i][j];
    }
  }
}
void Solve() {
  for (int i = 1; i <= m; i++) {
    bool check = false;
    for (int j = 1; j <= n; j++) {
      if (sum[i][j] - c[i][j] == 0) {
        check = true;
        break;
      }
    }
    if (!check) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int main() {
  Input();
  Sum();
  Solve();
  return 0;
}
