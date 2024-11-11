#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  char a[26][26];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)n; ++i) scanf(" %s ", a[i]);
  int mx = 0;
  for (int i1 = 0; i1 < (int)n; ++i1)
    for (int j1 = 0; j1 < (int)m; ++j1)
      for (int i2 = 0; i2 < (int)i1 + 1; ++i2)
        for (int j2 = 0; j2 < (int)j1 + 1; ++j2) {
          bool ok = true;
          for (int i = i2; i <= i1; i++)
            for (int j = j2; j <= j1; j++) ok &= a[i][j] == '0';
          if (ok) mx = max(mx, 2 * (i1 - i2 + 1 + j1 - j2 + 1));
        }
  cout << mx << endl;
  return 0;
}
