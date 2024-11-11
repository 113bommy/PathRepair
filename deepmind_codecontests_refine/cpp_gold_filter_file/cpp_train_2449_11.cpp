#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  return (b == 0) ? a : gcd(b, a % b);
}
int main() {
  int t, cas = 0, i, j, n, m;
  int g_l, g_r, b_l, b_r;
  while (scanf("%d %d %d %d", &g_l, &g_r, &b_l, &b_r) == 4) {
    bool flag = 0;
    n = g_l - b_r;
    if (n < 0) n *= (-1);
    m = g_r - b_l;
    if (m < 0) m *= (-1);
    if (g_r - b_l > 1 || b_l > (2 * g_r + 2)) {
      if (g_l - b_r > 1)
        cout << "NO" << endl;
      else if (b_r > (2 * g_l + 2))
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else if (g_l - b_r > 1 || b_r > (2 * g_l + 2)) {
      if (g_r - b_l > 1)
        cout << "NO" << endl;
      else if (b_l > (2 * g_r + 2))
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
