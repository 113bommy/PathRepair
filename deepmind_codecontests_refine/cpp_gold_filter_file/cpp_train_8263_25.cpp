#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
long long n, nl, cnt[5];
long long f[1000010], dp[1000010];
const long long mod = 1e9 + 7;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    nl = read();
    cnt[nl]++;
  }
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= cnt[1]; i++) {
    f[i] = (f[i - 1] + f[i - 2] * (i - 1)) % mod;
  }
  for (int i = max(3ll, cnt[1] + 1); i <= cnt[1] + cnt[2]; i++) {
    f[i] = f[i - 1] * i % mod;
  }
  cout << f[n] << endl;
  return 0;
}
