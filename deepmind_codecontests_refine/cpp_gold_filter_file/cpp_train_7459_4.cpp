#include <bits/stdc++.h>
using namespace std;
inline long long gin() {
  long long s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = (s << 3) + (s << 1) + (c ^ 48);
    c = getchar();
  }
  return s * f;
}
const long long N = 5e5 + 5, mod = 1e9 + 7, P = 131;
long long n, m, k, ml[N], mr[N];
char s[N], t[N];
struct Hash {
  long long hash[N], bin[N];
  void hs(char* s) {
    long long len = strlen(s + 1);
    bin[0] = 1;
    for (long long i = 1; i <= len; i++) {
      hash[i] = (hash[i - 1] * P + s[i] - 'a') % mod;
      bin[i] = bin[i - 1] * P % mod;
    }
  }
  long long get(long long l, long long r) {
    return ((hash[r] - hash[l - 1] * bin[r - l + 1]) % mod + mod) % mod;
  }
} S, T;
signed main() {
  n = gin(), m = gin(), k = gin();
  scanf("%s%s", s + 1, t + 1);
  S.hs(s), T.hs(t);
  long long pos = k;
  for (long long i = 1; i <= m; i++) ml[i] = n + 1;
  for (long long i = 1; i <= min(m, k); i++) {
    while (pos <= n && S.get(pos - i + 1, pos) != T.get(1, i)) pos++;
    if (S.get(k - i + 1, k) == T.get(1, i)) pos = k;
    ml[i] = pos;
  }
  pos = n - k + 1;
  for (long long i = 1; i <= min(m, k); i++) {
    while (pos && S.get(pos, pos + i - 1) != T.get(m - i + 1, m)) pos--;
    if (S.get(n - k + 1, n - k + i) == T.get(m - i + 1, m)) pos = n - k + 1;
    mr[m - i + 1] = pos;
  }
  for (long long i = 1; i <= n - m + 1; i++) {
    if (S.get(i, i + m - 1) == T.get(1, m)) {
      if (k >= i && n - k + 1 <= i + m - 1) continue;
      puts("Yes");
      printf("%lld %lld\n", min(max(1ll, i - k + 1), n - k + 1 - k),
             max(k + 1, min(n - k + 1, i)));
      return 0;
    }
  }
  for (long long i = 1; i < m; i++) {
    if (ml[i] < mr[i + 1] && ml[i] <= n && mr[i + 1]) {
      puts("Yes");
      printf("%lld %lld\n", ml[i] - k + 1, mr[i + 1]);
      return 0;
    }
  }
  puts("No");
  return 0;
}
