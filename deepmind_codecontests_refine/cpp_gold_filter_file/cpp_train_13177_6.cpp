#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
template <class T>
inline bool read(T &n) {
  T x = 0, tmp = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
  if (c == EOF) return false;
  if (c == '-') c = getchar(), tmp = -1;
  while (c >= '0' && c <= '9') x *= 10, x += (c - '0'), c = getchar();
  n = x * tmp;
  return true;
}
template <class T>
inline void write(T n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  int len = 0, data[20];
  while (n) {
    data[len++] = n % 10;
    n /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
}
const int MAXN = 100010;
long long pre[MAXN], a[MAXN], mi[100];
map<long long, long long> dp;
int cnt = 0, n, k;
int main() {
  read(n), read(k);
  for (int i = 1; i <= n; i++) read(a[i]);
  if (k == 1) {
    mi[0] = 1;
    dp[mi[0]]++;
  } else if (k == -1) {
    mi[0] = 1;
    mi[1] = -1;
    cnt = 1;
    dp[mi[0]]++;
    dp[mi[1]]++;
  } else {
    long long t = 1;
    mi[cnt] = 1;
    dp[mi[cnt]]++;
    while (abs(t * k) < 1e15) {
      cnt++;
      t *= k;
      mi[cnt] = t;
      dp[mi[cnt]]++;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
    ans += dp[pre[i]];
    for (int j = 0; j <= cnt; j++) dp[pre[i] + mi[j]]++;
  }
  write(ans), putchar('\n');
  return 0;
}
