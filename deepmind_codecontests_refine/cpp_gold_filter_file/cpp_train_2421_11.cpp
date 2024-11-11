#include <bits/stdc++.h>
using namespace std;
inline long long getint() {
  long long ssum = 0, ff = 1;
  char ch;
  for (ch = getchar(); !isdigit(ch) && ch != '-'; ch = getchar())
    ;
  if (ch == '-') ff = -1, ch = getchar();
  for (; isdigit(ch); ch = getchar()) ssum = ssum * 10 + ch - '0';
  return ssum * ff;
}
const long long M = 1e5 + 5;
long long u[M], d[M], l[M], r[M], n, m, q, ans = 1e18;
long long f[M][2];
char ch[M];
void Solveud() {
  memset(f, 0x3f, sizeof(f));
  f[1][0] = f[1][1] = 0;
  for (long long i = 1; i <= m; i++) {
    if (u[i])
      f[1][0]++;
    else
      f[1][1]++;
  }
  if (l[1])
    f[1][0]++;
  else
    f[1][1]++;
  if (r[1])
    f[1][0]++;
  else
    f[1][1]++;
  for (long long i = 2; i <= n; i++) {
    long long val0 = 0, val1 = 0;
    if (l[i])
      val0++;
    else
      val1++;
    if (r[i])
      val0++;
    else
      val1++;
    f[i][0] = min(f[i - 1][0] + val0, f[i - 1][1] + m + val0);
    f[i][1] = min(f[i - 1][1] + val1, f[i - 1][0] + m + val1);
  }
  for (long long i = 1; i <= m; i++) {
    if (d[i])
      f[n][0]++;
    else
      f[n][1]++;
  }
  ans = min(f[n][0], f[n][1]);
}
void Solvelr() {
  memset(f, 0x3f, sizeof(f));
  f[1][0] = f[1][1] = 0;
  for (long long i = 1; i <= n; i++) {
    if (l[i])
      f[1][0]++;
    else
      f[1][1]++;
  }
  if (u[1])
    f[1][0]++;
  else
    f[1][1]++;
  if (d[1])
    f[1][0]++;
  else
    f[1][1]++;
  for (long long i = 2; i <= m; i++) {
    long long val0 = 0, val1 = 0;
    if (u[i])
      val0++;
    else
      val1++;
    if (d[i])
      val0++;
    else
      val1++;
    f[i][0] = min(f[i - 1][0] + val0, f[i - 1][1] + n + val0);
    f[i][1] = min(f[i - 1][1] + val1, f[i - 1][0] + n + val1);
  }
  for (long long i = 1; i <= n; i++) {
    if (r[i])
      f[m][0]++;
    else
      f[m][1]++;
  }
  ans = min(ans, min(f[m][0], f[m][1]));
}
signed main() {
  cin >> n >> m >> q;
  cin >> (ch + 1);
  for (long long i = 1; i <= n; i++) l[i] = (ch[i] == 'R');
  cin >> (ch + 1);
  for (long long i = 1; i <= n; i++) r[i] = (ch[i] == 'R');
  cin >> (ch + 1);
  for (long long i = 1; i <= m; i++) u[i] = (ch[i] == 'R');
  cin >> (ch + 1);
  for (long long i = 1; i <= m; i++) d[i] = (ch[i] == 'R');
  Solveud();
  Solvelr();
  cout << ans << endl;
  return 0;
}
