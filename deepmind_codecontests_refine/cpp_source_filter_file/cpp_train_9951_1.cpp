#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void next_int(T &x) {
  x = 0;
  char c;
  bool neg = false;
  while (!isdigit(c = getchar()))
    if (c == '-') neg = true;
  do x = x * 10 + c - 48;
  while (isdigit(c = getchar()));
  if (neg) x = -x;
}
template <typename T>
inline void write_int(T x, char last = 0) {
  if (x < 0) putchar('-'), x = abs(x);
  char tmp[20];
  int cnt = 0;
  while (x >= 10) tmp[cnt++] = x % 10 + 48, x /= 10;
  tmp[cnt] = x + 48;
  for (int i = (cnt); i >= (0); --i) putchar(tmp[i]);
  if (last) putchar(last);
}
const int N = (int)2e5 + 5;
const long long base = (long long)1e9 + 7;
int n, n1, n2;
long long fact[N], inv[N];
char s[N];
long long fast_pw(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long tmp = fast_pw(x, y / 2LL);
  tmp = (tmp * tmp) % base;
  if (y % 2LL) tmp = (tmp * x) % base;
  return tmp;
}
long long nCk(int N, int K) {
  if (N < K) return 0;
  long long tmp1 = fact[N], tmp2 = inv[K], tmp3 = inv[N - K];
  return (tmp1 * ((tmp2 * tmp3) % base)) % base;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1), fact[0] = 1, inv[0] = 1;
  for (int i = (1); i <= (n); ++i)
    fact[i] = (fact[i - 1] * (long long)i) % base,
    inv[i] = fast_pw(fact[i], base - 2LL), n2 += (s[i] == ')');
  long long res = 0;
  for (int i = (1); i <= (n); ++i) {
    if (!n2) break;
    n1 += (s[i] == '(');
    if (s[i] == '(') res = (res + nCk(n1 + n2 - 1, n2 - 1));
    n2 -= (s[i] == ')');
  }
  write_int(res);
  return 0;
}
