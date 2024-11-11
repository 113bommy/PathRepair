#include <bits/stdc++.h>
using namespace std;
const int N = 50;
const long long inf = 1e18;
long long n, m, a[N], b[N], dp[N], c[N];
struct matrix {
  long long a[N][N];
  int n, m;
  matrix(int _n = 0, int _m = 0) {
    n = _n, m = _m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = inf;
  }
} f, s;
matrix operator*(matrix a, matrix b) {
  matrix c(a.n, b.m);
  for (int i = 0; i < c.n; i++)
    for (int j = 0; j < c.m; j++)
      for (int k = 0; k < a.m; k++)
        c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
  return c;
}
void out(matrix a) {
  puts("-------------");
  cout << "a.n = " << a.n << " a.m = " << a.m << endl;
  for (int i = 0; i < a.n; i++, puts(""))
    for (int j = 0; j < a.m; j++) cout << a.a[i][j] << " ";
  puts("-------------");
}
matrix bp(matrix a, int n) {
  matrix ans(a.n, a.m);
  for (int i = 0; i < a.n; i++) ans.a[i][i] = 0;
  while (n) {
    if (n & 1) ans = ans * a;
    a = a * a;
    n >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  f = matrix(1, n + n + 1);
  s = matrix(n + n + 1, n + n + 1);
  for (int st = 0; st <= n + n; st++) {
    for (int i = 0; i <= n + n; i++) dp[i] = inf;
    dp[st] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n + n; j++) {
        c[j] = inf;
        if (j > 0) c[j] = min(c[j], dp[j - 1] + a[i]);
        if (j + 1 <= n + n) c[j] = min(c[j], dp[j + 1] + b[i]);
      }
      for (int j = 0; j <= n + n; j++) dp[j] = c[j];
    }
    for (int j = 0; j <= n + n; j++) s.a[st][j] = dp[j];
  }
  f.a[0][0] = 0;
  f = f * bp(s, m);
  cout << f.a[0][0];
  return 0;
}
