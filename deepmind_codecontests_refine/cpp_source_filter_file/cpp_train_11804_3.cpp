#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m, a, b, ans = 0, tmp, j, k, l, d, o, p, bb, t;
  int x[55][55];
  char c;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> c;
      if (c == 'W') {
        x[i][j] = 0;
      } else {
        x[i][j] = 1;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (x[i][j] == 1) {
        a = i;
        b = j;
        for (k = a; k <= n; k++) {
          for (l = b + 1; l <= m; l++) {
            if (x[k][l] == 1) {
              c = k;
              d = l;
              bb = 2;
              for (o = a; o <= c; o++) {
                if (x[o][b] == 0) {
                  bb = 1;
                  break;
                }
              }
              if (bb == 2) {
                if (d <= b)
                  for (p = d; p <= b; p++) {
                    if (x[c][p] == 0) {
                      bb = 1;
                      break;
                    }
                  }
                else {
                  for (p = b; p <= d; p++) {
                    if (x[c][p] == 0) {
                      bb = 1;
                      break;
                    }
                  }
                }
              }
              if (bb == 1) {
                for (o = a; o <= c; o++) {
                  if (x[o][d] == 0) {
                    bb = 0;
                    break;
                  }
                }
                if (bb == 1) {
                  if (d <= b) {
                    for (p = d; p <= b; p++) {
                      if (x[a][p] == 0) {
                        bb = 0;
                        break;
                      }
                    }
                  } else {
                    for (p = b; p <= d; p++) {
                      if (x[a][p] == 0) {
                        bb = 0;
                        break;
                      }
                    }
                  }
                }
              }
              if (bb == 0) {
                cout << "NO" << endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
