#include <bits/stdc++.h>
using namespace std;
namespace Fread {
const int MAXN = 1 << 20;
char buf[MAXN], *S, *T;
inline char getchar() {
  if (S == T) {
    T = (S = buf) + fread(buf, 1, MAXN, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
}  // namespace Fread
inline int read() {
  int f = 1, x = 0;
  char ch = Fread::getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = Fread::getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = Fread::getchar();
  }
  return x * f;
}
inline long long readll() {
  long long f = 1, x = 0;
  char ch = Fread::getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = Fread::getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = Fread::getchar();
  }
  return x * f;
}
int cnt[30], len;
long long comb(long long n, long long k) {
  if (n < k) return 0;
  long long res = 1;
  for (long long i = n; i >= n - k + 1; --i) res *= i;
  for (long long i = 1; i <= k; ++i) res /= i;
  return res;
}
long long calc() {
  int j = len + 1, ch = 0;
  long long res = 1;
  for (int i = 20; i >= 0; --i) {
    if (!cnt[i]) continue;
    while (j - 1 >= 1 && j > i) --j;
    res *= comb(len - j + 1 - ch, cnt[i]);
    ch += cnt[i];
  }
  return res;
}
int main() {
  int T = read();
  while (T--) {
    long long n = read();
    memset(cnt, 0, sizeof(cnt));
    len = 0;
    for (int i = 2;; ++i) {
      cnt[n % i]++;
      len++;
      n /= i;
      if (!n) break;
    }
    long long ans1 = calc(), ans2 = 0;
    if (cnt[0]) {
      cnt[0]--;
      len--;
      ans2 = calc();
    }
    printf("%lld\n", ans1 - ans2 - 1);
  }
  return 0;
}
