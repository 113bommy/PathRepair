#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, mi, mj;
  uint64_t c[1000][1000], vsum[1000] = {0}, hsum[1000] = {0}, cx[1001] = {0},
                          cy[1001] = {0};
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> c[i][j];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      hsum[i] += c[i][j];
      vsum[j] += c[i][j];
    }
  mi = 0;
  mj = 0;
  for (i = 0; i <= m; i++) {
    for (j = 0; j < m; j++) {
      cx[i] += (vsum[j]) * ((((j) >= (i) ? (j) - (i) : (i) - (j)-1) * 4 + 2)) *
               ((((j) >= (i) ? (j) - (i) : (i) - (j)-1) * 4 + 2));
    }
    if (cx[i] < cx[mi]) mi = i;
  }
  for (i = 0; i <= n; i++) {
    for (j = 0; j < n; j++) {
      cy[i] += (hsum[j]) * ((((j) >= (i) ? (j) - (i) : (i) - (j)-1) * 4 + 2)) *
               ((((j) >= (i) ? (j) - (i) : (i) - (j)-1) * 4 + 2));
    }
    if (cy[i] < cy[mj]) mj = i;
  }
  cout << cx[mi] + cy[mj] << endl;
  cout << mj << ' ' << mi << endl;
}
