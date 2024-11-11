#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
inline int read() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  register int x = false;
  register char ch =
      p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
          ? EOF
          : *p1++;
  ;
  register bool sgn = false;
  while (ch != '-' && (ch < '0' || ch > '9'))
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  if (ch == '-')
    sgn = true,
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48),
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  return sgn ? -x : x;
}
long long fpow(long long a, int b, int mod) {
  long long res = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long d[N];
long long cnt[26];
long long fac[N];
char s[N];
int len;
long long num[N];
long long calc(int x) {
  long long tot = 0;
  for (int i = 0; i < x; i++) tot += cnt[i];
  return tot;
}
long long dfs(int d) {
  if (d == len + 1) return 0;
  long long tot = calc(s[d] - 'a') * fac[len - d] % mod;
  if (cnt[s[d] - 'a']) {
    cnt[s[d] - 'a']--;
    long long u = dfs(d + 1);
    cnt[s[d] - 'a']++;
    tot = (tot + cnt[s[d] - 'a'] * u % mod) % mod;
  }
  return tot;
}
int main() {
  fac[0] = 1;
  for (long long i = 1; i < N; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  scanf("%s", s + 1);
  len = strlen(s + 1);
  for (int i = 1; i <= len; i++) cnt[s[i] - 'a']++;
  long long ans = dfs(1);
  scanf("%s", s + 1);
  ans = (dfs(1) - ans + mod) % mod;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] >= 1) ans = ans * fpow(fac[cnt[i]], mod - 2, mod) % mod;
  }
  cout << ans - 1 << endl;
  return 0;
}
