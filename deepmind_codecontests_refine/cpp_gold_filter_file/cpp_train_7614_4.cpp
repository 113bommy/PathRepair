#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h, i, j, k, l;
  int a[105][105], b[105][105];
  int c[105], d[105];
  for (i = 0; i < 103; i++) {
    for (j = 0; j < 103; j++) b[i][j] = -1;
  }
  cin >> n >> m >> h;
  for (i = 0; i < m; i++) cin >> c[i];
  for (i = 0; i < n; i++) cin >> d[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      if (!a[i][j]) b[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (b[i][j] < 0) b[i][j] = d[i];
    }
  }
  for (j = 0; j < m; j++) {
    int g = -2;
    for (i = 0; i < n; i++) g = max(g, b[i][j]);
    if (g > c[j]) {
      for (i = 0; i < n; i++) {
        b[i][j] = min(b[i][j], c[j]);
      }
    } else if (g < c[j]) {
      for (i = 0; i < n; i++) b[i][j] = max(b[i][j], c[j]);
    }
  }
  for (i = 0; i < n; i++) {
    int g = -2;
    for (j = 0; j < m; j++) g = max(g, b[i][j]);
    if (g > d[i]) {
      for (j = 0; j < m; j++) {
        b[i][j] = min(b[i][j], d[i]);
      }
    } else if (g < d[i]) {
      for (j = 0; j < m; j++) b[i][j] = max(b[i][j], d[i]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cout << b[i][j] << " ";
    cout << '\n';
  }
}
