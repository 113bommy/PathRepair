#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
double ans;
int n, k, t, x[500010], y[500010];
double dis(int A, int B) {
  return sqrt(1.0 * (x[A] - x[B]) * (x[A] - x[B]) +
              1.0 * (y[A] - y[B]) * (y[A] - y[B]));
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n + 1; ++i) getint(x[i]);
  t = x[k];
  cin >> y[n + 1];
  sort(x + 1, x + n + 1);
  if (k == n + 1) {
    ans = min(dis(n + 1, 1), dis(n + 1, n)) + dis(1, n);
    printf("%.10f\n", ans);
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    if (x[i] == t) k = i;
  ans = dis(k, n + 1) + dis(1, n) + min(dis(n + 1, 1), dis(n + 1, n));
  ans = min(ans, min(dis(1, k) + dis(n, n + 1), dis(n, k) + dis(1, n + 1)) +
                     dis(1, n));
  for (int i = k; i <= n - 1; ++i)
    ans =
        min(ans, dis(1, i) +
                     min(dis(i, n + 1) + dis(1, k), dis(1, n + 1) + dis(i, k)) +
                     dis(i + 1, n) + min(dis(n + 1, i + 1), dis(n + 1, n)));
  for (int i = 2; i <= k; ++i)
    ans =
        min(ans, dis(i, n) +
                     min(dis(k, i) + dis(n + 1, n), dis(k, n) + dis(n + 1, i)) +
                     dis(1, i - 1) + min(dis(n + 1, i - 1), dis(n + 1, 1)));
  printf("%.10f\n", ans);
  return 0;
}
