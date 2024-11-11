#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0;
  long long d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
long long n, m;
long long st[105000][50];
long long stt[105000][50];
long long a[105000];
long long lg[105000] = {-1};
void init() {
  for (long long i = 1; i <= n; i++) {
    st[i][0] = a[i];
    stt[i][0] = a[i];
    lg[i] = lg[i >> 1] + 1;
  }
  for (long long i = 1; i <= lg[n]; i++)
    for (long long j = 1; j + (1 << i) - 1 <= n; j++)
      st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]),
      stt[j][i] = min(stt[j][i - 1], stt[j + (1 << (i - 1))][i - 1]);
}
long long query(long long l, long long r) {
  long long lglen = lg[r - l + 1];
  return max(st[l][lglen], st[r - (1 << lglen) + 1][lglen]);
}
long long queryy(long long l, long long r) {
  long long lglen = lg[r - l + 1];
  return min(stt[l][lglen], stt[r - (1 << lglen) + 1][lglen]);
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    long long x = read();
    a[i] -= x;
    a[i] += a[i - 1];
  }
  init();
  while (m--) {
    long long l = read();
    long long r = read();
    long long mi = queryy(l, r);
    long long mx = query(l, r);
    if (a[r] - a[l - 1] != 0 || mx - a[l - 1] > 0)
      printf("-1\n");
    else
      printf("%d\n", a[l - 1] - mi);
  }
  return 0;
}
