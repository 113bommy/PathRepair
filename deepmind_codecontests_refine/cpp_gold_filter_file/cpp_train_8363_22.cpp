#include <bits/stdc++.h>
using namespace std;
const int oo = 1000000001;
int n, m;
int c3, c4, c5, ans, x, y, z, g;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 3) c3++;
    if (x == 4) c4++;
    if (x == 5) c5++;
  }
  n = c3 + c4 + c5;
  ans = oo;
  g = c5 / gcd(c4, c5);
  for (int i = m / n; i >= 0; i--)
    for (int j = (m - c3 * i) / (n - c3), v = 1; j >= i; j -= v) {
      int t1 = c3 * i, t2 = c4 * j;
      int k = (m - c3 * i - c4 * j) / c5;
      int t3 = c5 * k;
      if (t3 - t2 >= ans) break;
      if (t1 + t2 + t3 != m)
        continue;
      else
        v = g;
      int tmp = abs(t1 - t2) + abs(t2 - t3);
      if (tmp < ans) {
        ans = tmp;
        x = i;
        y = j;
        z = k;
      }
    }
  if (ans == oo)
    printf("-1\n");
  else
    printf("%d %d %d\n", x, y, z);
  return 0;
}
