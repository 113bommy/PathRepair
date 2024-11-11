#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
inline int read() {
  char ch = getchar();
  int r = 0, s = 1;
  while (ch > 57 || ch < 48) s = ch == 45 ? 0 : s, ch = getchar();
  while (ch >= 48 && ch <= 57)
    r = (r << 1) + (r << 3) + (ch ^ 48), ch = getchar();
  return s ? r : -r;
}
int n;
double ans;
int w[maxn];
double s[maxn];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  n = read();
  for (register int i = 0; i <= n; ++i) {
    cin >> s[i];
    w[i] = n - (i << 1);
  }
  int x1, x2;
  for (register int i = 0; i <= (n - 1) >> 1; ++i) {
    for (register int j = (n >> 1) + 1; j <= n; ++j) {
      int tmp = gcd((w[i] < 0 ? -w[i] : w[i]), (w[j] < 0 ? -w[j] : w[j]));
      int lcm = (w[i] < 0 ? -w[i] : w[i]) * (w[j] < 0 ? -w[j] : w[j]) / tmp;
      x1 = lcm / (w[i] < 0 ? -w[i] : w[i]),
      x2 = lcm / (w[j] < 0 ? -w[j] : w[j]);
      ans = (ans > (s[i] * x1 + s[j] * x2) / (x1 + x2)
                 ? ans
                 : (s[i] * x1 + s[j] * x2) / (x1 + x2));
    }
  }
  ans = (ans > s[n >> 1] ? ans : s[n >> 1]);
  printf("%0.10lf", ans);
  return 0;
}
