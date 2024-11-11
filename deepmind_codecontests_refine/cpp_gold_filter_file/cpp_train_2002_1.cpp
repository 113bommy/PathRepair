#include <bits/stdc++.h>
using namespace std;
int n, m, k, A[550][550];
int csum[550][550];
int input() {
  string s;
  cin >> n >> m >> k;
  for (int i = (int)(1); i <= (int)(n); i++) {
    cin >> s;
    for (int j = (int)(1); j <= (int)(m); j++) A[i][j] = s[j - 1] - '0';
  }
  return 0;
}
int chk(int a, int b) {
  if (a < 2 || b < 2 || a > (n - 1) || b > (m - 1)) return 0;
  return (A[a][b] && A[a - 1][b] && A[a + 1][b] && A[a][b - 1] && A[a][b + 1]);
}
int sum(int a, int b, int c, int d) {
  if (a < 1 || a > n || b < 1 || b > m || c < a || c > n || d < b || d > m)
    return -10000000;
  return csum[c][d] - csum[c][b - 1] - csum[a - 1][d] + csum[a - 1][b - 1];
}
int bsearchR(int x, int y, int a, int b, int c, int d) {
  int i;
  for (i = b; i <= d; i++)
    if (sum(x + 1, y + 1, a - 1, i - 1) >= k) break;
  if (i > d) i = 0;
  return i;
}
int bsearchC(int x, int y, int a, int b, int c, int d) {
  int i;
  for (i = a; i <= c; i++)
    if (sum(x + 1, y + 1, i - 1, b - 1) >= k) break;
  if (i > c) i = 0;
  return i;
}
unsigned long long calc(int x, int y, int a, int b, int c, int d) {
  int i, j, t;
  unsigned long long rv = 0;
  if (a > c || b > d) return 0;
  if (a == c && b == d) return (sum(x + 1, y + 1, c - 1, d - 1) >= k) ? 1 : 0;
  if (sum(x + 1, y + 1, a - 1, b - 1) >= k) return (c - a + 1) * (d - b + 1);
  if (sum(x + 1, y + 1, c - 1, d - 1) < k) return 0;
  if (a == c) {
    t = bsearchR(x, y, a, b, c, d);
    if (t == 0) return 0;
    return (d - t + 1);
  }
  if (b == d) {
    t = bsearchC(x, y, a, b, c, d);
    if (t == 0) return 0;
    return (c - t + 1);
  }
  for (i = a, j = b; i < c && j < d && sum(x + 1, y + 1, i, j) < k; i++, j++)
    ;
  if (i == c && j == d) return calc(x, y, c, d, c, d);
  if (i == c) return calc(x, y, a, j + 1, c, d);
  if (j == d) return calc(x, y, i + 1, b, c, d);
  t = bsearchC(x, y, i + 1, j, c, j);
  if (t) rv += (c - t + 1);
  t = bsearchR(x, y, i, j + 1, i, d);
  if (t) rv += (d - t + 1);
  rv += (c - i) * (d - j);
  if (i != a) rv += calc(x, y, a, j + 1, i - 1, d);
  if (j != b) rv += calc(x, y, i + 1, b, c, j - 1);
  return rv;
}
unsigned long long solve() {
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++)
      csum[i][j] =
          csum[i - 1][j] + csum[i][j - 1] - csum[i - 1][j - 1] + chk(i, j);
  unsigned long long ans = 0;
  if (k > sum(2, 2, n - 1, m - 1)) return 0;
  for (int a = (int)(1); a <= (int)(n - 2); a++)
    for (int b = (int)(1); b <= (int)(m - 2); b++)
      ans += calc(a, b, a + 2, b + 2, n, m);
  return ans;
}
int main() {
  input();
  cout << solve() << endl;
  return 0;
}
