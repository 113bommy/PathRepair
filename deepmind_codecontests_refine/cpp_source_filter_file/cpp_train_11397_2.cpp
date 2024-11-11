#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
const long long maxn = 4e5 + 700;
const long long mod = 1e9 + 7;
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
long long n, m, p;
long long dp[1005][205][2];
long long a[100];
long long qb[10005];
int cnt = 0;
long long dfs(int pos, int lead, int sta, int f, int pre, bool limit) {
  long long sum = 0;
  if (!pos) return f && pre;
  if (!limit && dp[pos][sta][f] != -1) return dp[pos][sta][f];
  int up = (limit ? a[pos] : 9);
  for (int i = 0; i <= up; i++) {
    if (lead)
      sum = (sum + dfs(pos - 1, i == 0, i == 0 ? 0 : (i * qb[n - pos]) % m,
                       i == 0 ? 0 : !((i * qb[n - pos]) % m), i,
                       limit && i == up)) %
            p;
    else
      sum = (sum + dfs(pos - 1, lead, (sta + i * qb[n - pos]) % m,
                       f ? f : !((sta + i * qb[n - pos]) % m), i,
                       limit && i == up)) %
            p;
  }
  if (!limit) dp[pos][sta][f] = sum;
  return sum;
}
char s[maxn], t[maxn];
long long solve(char *p) {
  long long cnt = 0;
  int len = strlen(p + 1);
  for (int i = len; i >= 1; i--) a[++cnt] = p[i] - '0';
  return dfs(cnt, 1, 0, 0, 0, 1);
}
int main() {
  memset(dp, -1, sizeof(dp));
  read(n);
  read(m);
  read(p);
  qb[0] = 1;
  for (int i = 1; i <= n; i++) qb[i] = (qb[i - 1] * 10) % m;
  for (int i = 1; i <= n; i++) s[i] = '9';
  printf("%lld\n", solve(s) % p);
  return 0;
}
