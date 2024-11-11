#include <bits/stdc++.h>
using namespace std;
char a[1003][1003];
int r, c, cc, rr;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  rr = n;
  cc = m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'X') {
        r = min(r, i);
        rr = max(rr, i);
        c = min(c, j);
        cc = max(cc, j);
      }
    }
  }
  for (int i = r; i <= rr; i++) {
    for (int j = c; j <= c; j++) {
      if (a[i][j] == '.') {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
