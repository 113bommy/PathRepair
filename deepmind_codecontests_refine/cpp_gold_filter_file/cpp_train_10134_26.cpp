#include <bits/stdc++.h>
using namespace std;
inline const int read() {
  int r = 0, k = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') k = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) r = r * 10 + c - '0';
  return r * k;
}
int n;
double a, x;
void input() { cin >> n >> a >> x; }
void solve() {
  double ans = 0;
  while (n--) {
    double t, v;
    scanf("%lf%lf", &t, &v);
    if (sqrt(2 * a * x) <= v)
      ans = max(ans, t + sqrt(2 * x / a));
    else
      ans = max(ans, t + v / a + (x - v * v / 2.0 / a) / v);
    printf("%.10f\n", ans);
  }
}
int main() {
  input(), solve();
  return 0;
}
