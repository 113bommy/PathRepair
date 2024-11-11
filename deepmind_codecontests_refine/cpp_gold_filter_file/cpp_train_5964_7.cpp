#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;
const int MAXM = 4e6 + 10;
const long long MOD = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const unsigned long long BASE = 233;
const int base = 5;
mt19937_64 mt(time(0));
char rubbish[110];
bool GETDATA;
inline long long read() {
  long long x = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do {
    x = x * 10 + ch - 48;
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return x * f;
}
inline void write(long long x, char con = '\n') {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10, 0);
  putchar(x % 10 + '0');
  if (con) {
    printf("%c", con);
  }
}
long long N, M, K, Q;
long long a[MAXN];
pair<int, int> t[MAXN];
long long dp[MAXN];
void init() {}
void solve() {
  long long ans = 0;
  long long now;
  N = read();
  K = read();
  for (int i = 1; i <= N; i++) {
    t[i] = {read(), read()};
    a[i] = read();
  }
  init();
  for (int i = N; i >= 1; i--) {
    now = a[i] + (t[i].second == t[i + 1].first) * dp[i + 1];
    if ((t[i].second - t[i].first + 1) * K < now) {
      write(-1);
      return;
    }
    now -= (t[i].second - t[i].first) * K;
    dp[i] = max(0LL, now);
  }
  now = K;
  for (int i = 1; i <= N; i++) {
    if (now < dp[i]) {
      ans += now;
      now = K;
    }
    ans += a[i];
    (((now -= a[i]) %= K) += K) %= K;
  }
  write(ans);
}
int main() {
  int T;
  T = 1;
  for (int t = 1; t <= T; t++) {
    GETDATA = false;
    solve();
  }
  return 0;
}
