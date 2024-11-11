#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long INF = 1e18;
const int maxn = 1e6 + 18;
const int mod = 19260817;
inline bool read(long long &num) {
  char in;
  bool IsN = false;
  in = getchar();
  if (in == EOF) return false;
  while (in != '-' && (in < '0' || in > '9')) in = getchar();
  if (in == '-') {
    IsN = true;
    num = 0;
  } else
    num = in - '0';
  while (in = getchar(), in >= '0' && in <= '9') {
    num *= 10, num += in - '0';
  }
  if (IsN) num = -num;
  return true;
}
long long n, m;
long long f[2005][2005];
long long f1[2005][2005];
long long L, R;
long long num[maxn];
int main() {
  read(n);
  read(m);
  read(L);
  read(R);
  for (int i = 1; i <= n; i++) read(num[i]);
  memset(f, -1, sizeof(f));
  memset(f1, -1, sizeof(f1));
  f[0][0] = 0;
  f1[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= m; k++) {
      if (f[i - 1][k] != -1) {
        long long temp = (k + num[i]) % m;
        if (temp >= L && temp <= R)
          f[i][temp] = max(f[i][temp], f[i - 1][k] + 1);
        else
          f[i][temp] = max(f[i][temp], f[i - 1][k]);
        temp = (k + num[i] + m - 1) % m;
        if (temp >= L && temp <= R)
          f1[i][temp] = max(f1[i][temp], f[i - 1][k] + 1);
        else
          f1[i][temp] = max(f1[i][temp], f[i - 1][k]);
      }
      if (f1[i - 1][k] != -1) {
        long long temp = (k + num[i]) % m;
        if (temp >= L && temp <= R)
          f[i][temp] = max(f[i][temp], f1[i - 1][k] + 1);
        else
          f[i][temp] = max(f[i][temp], f1[i - 1][k]);
        temp = (k + num[i] - 1 + m) % m;
        if (temp >= L && temp <= R)
          f1[i][temp] = max(f1[i][temp], f1[i - 1][k] + 1);
        else
          f1[i][temp] = max(f1[i][temp], f1[i - 1][k]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= m; i++) ans = max(ans, max(f[n][i], f1[n][i]));
  printf("%lld\n", ans);
  return 0;
}
