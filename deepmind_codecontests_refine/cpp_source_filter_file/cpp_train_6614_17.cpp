#include <bits/stdc++.h>
using namespace std;
struct zap {
  int t;
  int r;
  int c;
  int x;
};
zap a[10000];
int d[100][100], n, m;
void csd(int r) {
  int next = d[n - 1][r];
  for (int i = n - 1; i >= 1; i--) {
    d[i][r] = d[i - 1][r];
  }
  d[0][r] = next;
}
void csl(int r) {
  int next = d[m - 1][r];
  for (int i = m - 1; i >= 1; i--) {
    d[r][i] = d[r][i - 1];
  }
  d[r][0] = next;
}
int main() {
  int q;
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    a[i].t = t;
    if (t == 3) {
      int d, b, c;
      cin >> d >> b >> c;
      d--;
      b--;
      a[i].r = d;
      a[i].c = b;
      a[i].x = c;
    } else {
      int d;
      cin >> d;
      d--;
      a[i].r = d;
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    if (a[i].t == 3) {
      int x = a[i].r, y = a[i].c;
      d[x][y] = a[i].x;
    }
    if (a[i].t == 2) {
      csd(a[i].r);
    }
    if (a[i].t == 1) {
      csl(a[i].r);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << d[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
