#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
template <class T>
inline bool read(T &x) {
  x = 0;
  register char c = getchar();
  register bool f = 0;
  while (!isdigit(c)) {
    if (c == EOF) return false;
    f ^= c == '-', c = getchar();
  }
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return true;
}
template <class T>
inline bool readc(T &x) {
  register char c = getchar();
  while (c == ' ' || c == '\n' || c == '\r' || c == '\t') c = getchar();
  if (c == EOF) return false;
  x = c;
  return true;
}
template <class T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 ^ 48);
}
template <class T>
inline void print(T x, char c) {
  print(x), putchar(c);
}
template <class T, class... S>
inline bool read(T &x, S &...y) {
  return read(x) && read(y...);
}
long long t, n, m, to, nxt[1000005], a[1000005], dp[2][1000005], ans1[1000005],
    ans2[1000005], res1, res2;
char x;
int main() {
  read(t);
  while (t--) {
    read(n, m);
    res1 = res2 = 0;
    fill(ans1, ans1 + n * m, 0);
    fill(ans2, ans2 + n * m, 0);
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++) {
        readc(x);
        a[(i - 1) * m + j] = x ^ 48;
      }
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++) {
        readc(x);
        if (x == 'U') to = (i - 2) * m + j;
        if (x == 'D') to = i * m + j;
        if (x == 'L') to = (i - 1) * m + j - 1;
        if (x == 'R') to = (i - 1) * m + j + 1;
        nxt[(i - 1) * m + j] = to;
      }
    for (long long i = 1; i <= n * m; i++) dp[0][i] = nxt[i];
    for (long long i = 1; i <= 20; i++) {
      for (long long j = 1; j <= n * m; j++) dp[1][j] = dp[0][dp[0][j]];
      for (long long j = 1; j <= n * m; j++) dp[0][j] = dp[1][j];
    }
    for (long long i = 1; i <= n * m; i++) {
      ans1[dp[0][i]]++;
      ans2[dp[0][i]] += a[i] ^ 1;
    }
    for (long long i = 1; i <= n * m; i++) {
      if (ans1[i]) res1++;
      if (ans2[i]) res2++;
    }
    print(res1, ' ');
    print(res2, '\n');
  }
}
