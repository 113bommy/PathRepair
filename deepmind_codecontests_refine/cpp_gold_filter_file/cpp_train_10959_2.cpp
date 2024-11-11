#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
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
void init() {}
void solve() {
  long long ans = 0;
  long long x, y;
  N = read();
  ans = (N + 2) / 2 + 1;
  x = ans / 2 % MOD;
  y = (ans - x) % MOD;
  write(x * y % MOD);
}
int main() {
  int T;
  T = 1;
  T = read();
  for (int t = 1; t <= T; t++) {
    GETDATA = false;
    solve();
  }
  return 0;
}
