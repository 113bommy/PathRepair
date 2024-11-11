#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char a[550][550];
int b[550][550];
int s[550][550];
int abs(int x) { return (x > 0 ? x : -x); }
int star(int i, int j) {
  if (!(i > 0 && i < n - 1 && j > 0 && j < m - 1)) return 0;
  for (int(dx) = (-1); (dx) < (2); (dx)++)
    for (int(dy) = (-1); (dy) < (2); (dy)++)
      if (abs(dx) + abs(dy) <= 1 && a[i + dx][j + dy] == '0') return 0;
  return 1;
}
int sum(int i, int j) {
  if (i < 0 || j < 0) return 0;
  return s[i][j];
}
int get(int a, int b, int x, int y) {
  if (a > x || b > y) return 0;
  int ans = sum(x, y) - sum(a - 1, y) - sum(x, b - 1) + sum(a - 1, b - 1);
  return ans;
}
int main() {
  scanf("%d%d%d\n", &n, &m, &k);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%s\n", a[i]);
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (m); (j)++) b[i][j] = star(i, j);
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (m); (j)++)
      s[i][j] = b[i][j] + sum(i - 1, j) + sum(i, j - 1) - sum(i - 1, j - 1);
  int ans = 0;
  for (int(lo) = (0); (lo) < (n); (lo)++) {
    for (int(hi) = (lo + 2); (hi) < (n); (hi)++) {
      int r = 1;
      int curr = 0;
      for (int(l) = (0); (l) < (m - 2); (l)++) {
        while (r < m - 1 && curr < k) {
          curr += get(lo + 1, r, hi - 1, r);
          r++;
        }
        if (curr >= k) {
          ans += m - r;
        }
        curr -= get(lo + 1, l + 1, hi - 1, l + 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
