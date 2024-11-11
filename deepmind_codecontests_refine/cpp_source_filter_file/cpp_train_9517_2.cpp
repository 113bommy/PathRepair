#include <bits/stdc++.h>
using namespace std;
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
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writesp(long long a) {
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
  printf(" ");
}
inline void writeln(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  write(a);
  puts("");
}
long long n, m, d, ans, a[150005], b[150005], t[150005], sum, f[3][305];
deque<long long> q;
signed main() {
  n = read(), m = read(), d = read();
  ans = INT_MAX;
  memset(f, 0x3f, sizeof(f));
  for (long long i = 1; i <= m; i++)
    a[i] = read(), b[i] = read(), t[i] = read(), sum += b[i];
  for (long long i = 1; i <= n; i++) f[1][i] = abs(a[1] - i);
  for (long long i = 2; i <= m; i++) {
    while (!q.empty()) q.pop_front();
    memset(f[i & 1], 0x3f, sizeof(f[i & 1]));
    for (long long j = 1; j <= n; j++) {
      while (!q.empty() && q.front() < j - (t[i] - t[i - 1]) * d) q.pop_front();
      while (!q.empty() && f[i & 1 ^ 1][q.front()] > f[i & 1 ^ 1][j])
        q.pop_back();
      q.push_back(j);
      f[i & 1][j] = min(f[i & 1][j], f[i & 1 ^ 1][q.front()] + abs(a[i] - j));
    }
    while (!q.empty()) q.pop_front();
    for (long long j = n; j >= 1; j--) {
      while (!q.empty() && q.front() > j + (t[i] - t[i - 1]) * d) q.pop_front();
      while (!q.empty() && f[i & 1 ^ 1][q.front()] > f[i & 1 ^ 1][j])
        q.pop_back();
      q.push_back(j);
      f[i & 1][j] = min(f[i & 1][j], f[i & 1 ^ 1][q.front()] + abs(a[i] - j));
    }
  }
  for (long long i = 1; i <= n; i++) ans = min(ans, f[m & 1][i]);
  writeln(sum - ans);
}
