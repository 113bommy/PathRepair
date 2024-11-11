#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, l[2005], d[2005][2005], ans = 0, t, a[2005], p;
char s[2005][505];
void rec(int x, int y, int z) {
  if (y == k) {
    ans = max(ans, z);
    return;
  }
  for (int i = x; i < n; i++) {
    t = 0;
    for (int j = 0; j < y; j++) {
      t += d[a[j]][i];
    }
    a[y] = i;
    rec(x + 1, y + 1, z + t);
  }
}
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    l[i] = strlen(s[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      t = min(l[i], l[j]);
      for (p = 0; p < t; p++) {
        if (s[i][p] != s[j][p]) break;
        d[i][j]++;
      }
    }
  }
  rec(0, 0, 0);
  printf("%d\n", ans);
  return 0;
}
