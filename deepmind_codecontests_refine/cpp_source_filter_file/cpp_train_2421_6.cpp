#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, m;
long long u[110000], d[110000], l[110000], r[110000];
char ch[110000];
long long f[2][2];
long long ans;
void calc() {
  memset(f, 0, sizeof(f));
  long long p = 0;
  for (long long i = 1; i <= m; i++) f[p][0] += u[i], f[p][1] += !u[i];
  for (long long i = 1; i <= n; i++) {
    p ^= 1;
    f[p][0] = min(f[(p ^ 1)][0], f[(p ^ 1)][1] + m) + l[i] + r[i];
    f[p][1] = min(f[(p ^ 1)][0] + m, f[(p ^ 1)][1]) + (!l[i]) + (!r[i]);
  }
  for (long long i = 1; i <= m; i++) f[p][0] += d[i], f[p][1] += !d[i];
  ans = min(ans, min(f[p][0], f[p][1]));
}
signed main() {
  n = read(), m = read();
  read();
  ans = n * m;
  scanf("%s", ch + 1);
  for (long long i = 1; i <= n; i++) l[i] = (ch[i] == 'R');
  scanf("%s", ch + 1);
  for (long long i = 1; i <= n; i++) r[i] = (ch[i] == 'R');
  scanf("%s", ch + 1);
  for (long long i = 1; i <= m; i++) u[i] = (ch[i] == 'R');
  scanf("%s", ch + 1);
  for (long long i = 1; i <= m; i++) d[i] = (ch[i] == 'R');
  calc();
  swap(n, m);
  swap(r, d);
  swap(l, u);
  calc();
  cout << ans << endl;
  return 0;
}
