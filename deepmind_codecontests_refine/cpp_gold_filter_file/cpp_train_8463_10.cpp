#include <bits/stdc++.h>
using namespace std;
int n, k, m, dai, dem, vt, ck, max1, min1, kq, tong, dd;
int a[111111];
char s[222][222], ss[222], kt;
int nh, nc, h1, c1, h2, c2;
void sol() {
  int i, j;
  h1 = 2147483647;
  c1 = 2147483647;
  h2 = 0;
  c2 = 0;
  for (i = 0; i < nh; i++) {
    for (j = 0; j < nc; j++) {
      if (s[i][j] == '*') {
        if (h2 < i) h2 = i;
        if (c2 < j) c2 = j;
        if (h1 > i) h1 = i;
        if (c1 > j) c1 = j;
      }
    }
  }
  for (i = h1; i <= h2; i++) {
    for (j = c1; j <= c2; j++) cout << s[i][j];
    cout << endl;
  }
}
int main() {
  int i, j;
  while (scanf("%d %d", &nh, &nc) > 0) {
    for (i = 0; i < nh; i++) {
      scanf("%s", &s[i]);
    }
    sol();
  }
  return 0;
}
