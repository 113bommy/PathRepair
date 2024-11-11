#include <bits/stdc++.h>
using namespace std;
int tr[55][55];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> tr[i][j];
    }
  }
  int a, b;
  cin >> a >> b;
  int cut = 3000;
  int now = 0;
  for (int i = 1; i <= n - a + 1; i++) {
    for (int j = 1; j <= m - b + 1; j++) {
      now = 0;
      for (int k = i; k <= i + a - 1; k++) {
        for (int l = j; l <= j + b - 1; l++) {
          now += tr[k][l];
        }
      }
      cut = min(cut, now);
    }
  }
  for (int i = 1; i <= n - b + 1; i++) {
    for (int j = 1; j <= m - a + 1; j++) {
      now = 0;
      for (int k = i; k <= i + b - 1; k++) {
        for (int l = j; l <= j + a - 1; l++) {
          now += tr[k][l];
        }
      }
      cut = min(cut, now);
    }
  }
  cout << cut << "\n";
}
