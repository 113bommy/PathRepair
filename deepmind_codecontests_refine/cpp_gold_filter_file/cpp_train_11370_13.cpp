#include <bits/stdc++.h>
using namespace std;
const int N = 60 + 5;
char a[N][N];
int l[N][N];
int r[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> (a[i] + 1);
    int f1 = 0, f2 = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == 'A') f1 = 1;
        if (a[i][j] == 'P') f2 = 1;
      }
    }
    if (!f2) {
      printf("0\n");
      continue;
    }
    if (!f1) {
      printf("MORTAL\n");
      continue;
    }
    int visl = 0, visb = 0, visj = 0;
    if (a[1][1] == 'A' || a[1][m] == 'A' || a[n][1] == 'A' || a[n][m] == 'A')
      visj = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i == 1 || j == 1 || i == n || j == m) {
          if (a[i][j] == 'A') visb = 1;
        }
        if (a[i][j] == 'A') l[i][j] = l[i][j - 1] + 1;
      }
      if (l[i][m] == m) visl = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == 'A') r[i][j] = r[i - 1][j] + 1;
        if (r[n][j] == n) visl = 1;
      }
    }
    int visjl = 0;
    if (r[n][m] == n || l[n][m] == m || r[n][1] == n || l[1][m] == m) visjl = 1;
    if (visjl)
      printf("1\n");
    else if (visj)
      printf("2\n");
    else if (visl && visb)
      printf("2\n");
    else if (visb)
      printf("3\n");
    else
      printf("4\n");
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
  }
  return 0;
}
