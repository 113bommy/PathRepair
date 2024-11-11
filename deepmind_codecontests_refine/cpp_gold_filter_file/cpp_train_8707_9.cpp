#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int n, a[N], s[3][N], d[N], dm[N], DM = 0, ans = 0, t;
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); ++i)
    for (int k = (1); k <= (2); ++k) s[k][i] = s[k][i - 1] + (a[i] == k);
  for (int i = (1); i <= (n); ++i) d[i] = s[1][i] - s[2][i];
  dm[n + 1] = -oo;
  for (int i = (n); i >= (1); --i)
    dm[i] = ((dm[i + 1]) > (d[i]) ? (dm[i + 1]) : (d[i]));
  for (int i = (1); i <= (n); ++i) {
    t = s[1][i] + s[2][n] - s[2][i];
    t += dm[i] - d[i], t += ((DM - d[i - 1]) > (0) ? (DM - d[i - 1]) : (0));
    if (a[i] == 1) ans = ((ans) > (t) ? (ans) : (t));
    DM = ((DM) > (d[i]) ? (DM) : (d[i]));
  }
  ans = ((ans) > (s[2][n]) ? (ans) : (s[2][n]));
  printf("%d\n", ans);
  return 0;
}
