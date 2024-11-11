#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
using namespace std;
const int MAXN = 2e5 + 10;
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
char a[MAXN];
long long sum[MAXN];
void init() {
  N = strlen(a + 1);
  sum[1] = 1;
  for (long long i = 2; i <= N; i++) {
    sum[i] = sum[i - 1] * 10 % MOD;
  }
  for (long long i = 2; i <= N; i++) {
    ((sum[i] *= i) += sum[i - 1]) %= MOD;
  }
}
void solve() {
  long long ans = 0;
  long long now = 1;
  scanf("%s", a + 1);
  init();
  for (int i = 1; i <= N; i++) {
    (ans += (a[i] - '0') * sum[N - i]) %= MOD;
  }
  for (long long i = N; i >= 1; i--) {
    (ans += (a[i] - '0') * now * i * (i - 1) / 2) %= MOD;
    (now *= 10) %= MOD;
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
