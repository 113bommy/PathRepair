#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 1e6 + 5;
constexpr long long M = 998244353;
struct IO {
  char buf[(1 << 20)], *p1, *p2;
  char pbuf[(1 << 20)], *pp;
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
  inline char gc() {
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, (1 << 20), stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T>
  inline void read(T &x) {
    double tmp = 1;
    bool sign = 0;
    x = 0;
    char ch = gc();
    for (; !(ch >= '0' && ch <= '9'); ch = gc())
      if (ch == '-') sign = 1;
    for (; (ch >= '0' && ch <= '9'); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  inline void push(const char &c) {
    if (pp - pbuf == (1 << 20)) fwrite(pbuf, 1, (1 << 20), stdout), pp = pbuf;
    *pp++ = c;
  }
  template <class T>
  inline void write(T x) {
    if (x < 0) x = -x, push('-');
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }
  template <class T>
  inline void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;
char s[N];
char t[N];
long long nx[N][26];
pair<long long, long long> dp[N];
long long have[26];
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> (s + 1) >> (t + 1);
  long long n = strlen(s + 1), m = strlen(t + 1);
  for (long long c = 0; c < 26; c++) nx[n][c] = n + 1;
  for (long long i = 1; i <= n; i++) have[s[i] - 'a'] = 1;
  for (long long j = 1; j <= m; j++) {
    if (!have[t[j] - 'a']) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    for (long long c = 0; c < 26; c++)
      nx[i][c] = (s[i + 1] == 'a' + c) ? i + 1 : nx[i + 1][c];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = {1, 0};
  for (long long i = 1; i <= m; i++) {
    if (nx[dp[i - 1].second][t[i] - 'a'] > n)
      dp[i] = {dp[i - 1].first + 1, nx[0][t[i] - 'a']};
    else
      dp[i] = {dp[i - 1].first, nx[dp[i - 1].second][t[i] - 'a']};
  }
  if (dp[m].first > n)
    cout << -1 << endl;
  else
    cout << dp[m].first << endl;
  return 0;
}
