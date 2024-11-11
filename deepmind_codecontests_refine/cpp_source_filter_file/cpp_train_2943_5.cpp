#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
using namespace std;
const long long maxn = 2e3 + 7;
const double eps = 1e-10;
const long long mod = 1e9 + 7;
long long field_u[maxn][maxn];
long long field_d[maxn][maxn];
long long field_l[maxn][maxn];
long long field_r[maxn][maxn];
string s[maxn];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  long long ans = n * m;
  for (long long i = 0; i < (long long)(n); i++) cin >> s[i];
  for (long long j = 0; j < (long long)(m); j++) {
    for (long long i = 1; i < n; i++)
      if (s[i][j] == s[i - 1][j]) field_u[i][j] = field_u[i - 1][j] + 1;
    for (long long i = n - 2; i >= 0; i--)
      if (s[i][j] == s[i + 1][j]) field_d[i][j] = field_d[i + 1][j] + 1;
  }
  for (long long i = 0; i < (long long)(n); i++)
    for (long long j = 0; j < (long long)(m); j++)
      field_d[i][j] = min(field_u[i][j], field_d[i][j]);
  for (long long i = 0; i < (long long)(n); i++) {
    for (long long j = 1; j < n; j++)
      if (s[i][j] == s[i][j - 1])
        field_l[i][j] = min(field_l[i][j - 1] + 1, field_d[i][j]);
    for (long long j = m - 2; j >= 0; j--)
      if (s[i][j] == s[i][j + 1])
        field_r[i][j] = min(field_l[i][j + 1] + 1, field_d[i][j]);
  }
  for (long long i = 0; i < (long long)(n); i++)
    for (long long j = 0; j < (long long)(m); j++)
      ans += min(field_l[i][j], field_r[i][j]);
  cout << ans << "\n";
}
