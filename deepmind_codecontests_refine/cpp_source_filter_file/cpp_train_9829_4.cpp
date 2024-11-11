#include <bits/stdc++.h>
using namespace std;
int mar[60][60];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &mar[i][j]);
  bool ok = 0;
  for (int i = 1; i <= n; ++i) {
    if (mar[i][1] || mar[i][n]) ok = 1;
  }
  for (int i = 1; i <= m; ++i)
    if (mar[1][i] || mar[n][i]) ok = 1;
  if (ok)
    printf("2\n");
  else
    printf("4\n");
}
