#include <bits/stdc++.h>
using namespace std;
inline long long Read() {
  long long s = 0, f = 1;
  char x;
  for (x = getchar(); x < '0' || x > '9'; x = getchar())
    if (x == '-') f = -1;
  for (; x >= '0' && x <= '9'; x = getchar()) s = (s * 10) + (x & 15);
  return f == 1 ? s : -s;
}
const long long A = 4e5 + 5;
long long T;
char a[A];
long long len;
long long las, sz;
struct SAM {
  long long len, f;
  long long nex[50];
} tr[A];
long long dp[A];
inline void build() {
  for (long long i = 0; i <= sz; i++)
    for (long long j = 0; j < 30; j++) tr[i].nex[j] = 0;
  memset(dp, 0, sizeof(dp));
  las = sz = 1;
  tr[1].len = 0, tr[1].f = 0;
  return;
}
inline void add(long long x) {
  long long cur = ++sz;
  tr[cur].len = tr[las].len + 1;
  long long p = las;
  while (p && !tr[p].nex[x]) {
    tr[p].nex[x] = cur;
    p = tr[p].f;
  }
  if (!p)
    tr[cur].f = 1;
  else {
    long long q = tr[p].nex[x];
    if (tr[p].len + 1 == tr[q].len)
      tr[cur].f = q;
    else {
      long long cn = ++sz;
      tr[cn] = tr[q];
      tr[cn].len = tr[p].len + 1;
      tr[cur].f = tr[q].f = cn;
      while (p && tr[p].nex[x] == q) {
        tr[p].nex[x] = cn;
        p = tr[p].f;
      }
    }
  }
  dp[cur] = 1;
  las = cur;
  return;
}
long long t[A], p[A];
inline void Sort() {
  for (long long i = 0; i <= sz; i++) t[i] = 0;
  for (long long i = 1; i <= sz; i++) t[tr[i].len]++;
  for (long long i = 2; i <= sz; i++) t[i] += t[i - 1];
  for (long long i = sz; i; i--) p[t[tr[i].len]--] = i;
  return;
}
signed main() {
  T = Read();
  while (T--) {
    scanf("%s", a + 1);
    len = strlen(a + 1);
    build();
    for (long long i = 1; i <= len; i++) add(a[i] - 'a');
    Sort();
    long long ans = 0;
    for (long long i = sz; i; i--) {
      long long j = p[i];
      dp[tr[j].f] += dp[j];
    }
    for (long long i = 1; i <= sz; i++)
      ans += (tr[i].len - tr[tr[i].f].len) * dp[i] * dp[i];
    printf("%lld\n", ans);
  }
  return 0;
}
