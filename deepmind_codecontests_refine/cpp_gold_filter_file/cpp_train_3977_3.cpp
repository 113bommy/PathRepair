#include <bits/stdc++.h>
using namespace std;
long long inf = 1000000000000000000LL;
long long f[205][205], k;
int n, m, e, b[205], bo[205][205], sa[205];
char c[205];
bool cmp(int i, int j) { return b[i] < b[j]; }
void ud(int i, int j, long long x) {
  if (bo[i][j] != e) bo[i][j] = e, f[i][j] = 0;
  f[i][j] += x;
  if (f[i][j] > inf) f[i][j] = inf;
}
void dp() {
  ++e;
  bo[0][0] = e;
  f[0][0] = 1;
  for (int i = 0; i <= n - 1; ++i)
    for (int j = 0; j <= i; ++j)
      if (bo[i][j] == e) {
        if (c[i + 1] != '(' && j) ud(i + 1, j - 1, f[i][j]);
        if (c[i + 1] != ')') ud(i + 1, j + 1, f[i][j]);
      }
  if (bo[n][0] != e) f[n][0] = 0;
}
int main() {
  scanf("%d%d%I64d", &n, &m, &k);
  memset(b, 50, sizeof(b));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int x;
      scanf("%d", &x);
      b[i + j - 1] = ((b[i + j - 1]) < (x) ? (b[i + j - 1]) : (x));
    }
  n += m - 1;
  for (int i = 1; i <= n; ++i) sa[i] = i;
  sort(sa + 1, sa + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) {
    c[sa[i]] = '(';
    dp();
    if (f[n][0] < k) c[sa[i]] = ')', k -= f[n][0];
  }
  n -= m - 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%c", c[i + j - 1]);
    puts("");
  }
  return 0;
}
