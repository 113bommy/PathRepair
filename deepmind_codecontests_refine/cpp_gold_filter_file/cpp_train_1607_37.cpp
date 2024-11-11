#include <bits/stdc++.h>
int main() {
  int v[2][3];
  for (int i = 0; i != 2; ++i)
    for (int j = 0; j != 3; ++j) scanf("%d", &v[i][j]);
  int cnt = 0;
  for (int i = 0; i != 3; ++i)
    if (v[0][i] == v[1][i]) ++cnt;
  puts(cnt ? "YES" : "NO");
  return 0;
}
