#include <bits/stdc++.h>
using namespace std;
int a[1009][109];
int n, m, k;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int ans = 0;
  if (k == 0) {
    int c[2][10009];
    for (int i = 1; i <= m; i++) {
      for (int j = i; j <= m; j++) {
        int t = 0;
        for (int x = 1; x <= n; x++) {
          if (a[x][i] > a[x][j]) {
            swap(a[x][i], a[x][j]);
            t = 1;
          }
        }
        if (t == 1) {
          ans++;
          c[0][ans] = i;
          c[1][ans] = j;
        }
      }
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
      cout << c[0][i] << " " << c[1][i] << endl;
    }
  } else {
    int c[2][10009];
    for (int i = 1; i <= m; i++) {
      for (int j = i; j <= m; j++) {
        int t = 0;
        for (int x = 1; x <= n; x++) {
          if (a[x][i] < a[x][j]) {
            swap(a[x][i], a[x][j]);
            t = 1;
          }
        }
        if (t == 1) {
          ans++;
          c[0][ans] = j;
          c[1][ans] = i;
        }
      }
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
      cout << c[0][i] << " " << c[1][i] << endl;
    }
  }
  return 0;
}
