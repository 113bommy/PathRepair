#include <bits/stdc++.h>
constexpr auto Inf = 0X3F3F3F3F;
using namespace std;
namespace IO {
inline long long read() {
  long long o = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > '/' && c < ':') {
    o = o * 10 + c - '0';
    c = getchar();
  }
  return o * f;
}
inline char recd() {
  char o;
  while ((o = getchar()) < '0' || o > '9')
    ;
  return o;
}
inline double reod() {
  double o = read(), f = 1;
  char c;
  while ((c = getchar()) > '/' && c < ':') o += (c - '0') / (f *= 10);
  return o;
}
}  // namespace IO
using namespace IO;
const int SIZE = 1E5 + 7, Mod = 1E9 + 7;
long long a[] = {0,
                 9,
                 90,
                 900,
                 9000,
                 90000,
                 900000,
                 9000000,
                 90000000,
                 900000000,
                 9000000000,
                 90000000000,
                 900000000000,
                 9000000000000,
                 90000000000000,
                 900000000000000,
                 9000000000000000,
                 90000000000000000};
long long _pow(long long A, long long B) {
  long long res = 1;
  while (B) {
    if (B & 1) res *= A;
    A *= A, B >>= 1;
  }
  return res;
}
long long _log10(long long w) {
  int res = 0;
  while (w) res++, w /= 10;
  return res;
}
long long F(long long w) {
  if (!w) return 0;
  long long res = 0, S = 1, dig = log10(w) + 1;
  for (int pos = 1; pos < dig; pos++) {
    res += (S + S + (a[pos] - 1) * pos) * a[pos] / 2;
    S = S + (a[pos] - 1) * pos + pos + 1;
  }
  long long now = _pow(10, dig - 1);
  res += (S + S + (w - now) * dig) * (w - now + 1) / 2;
  return res;
}
int main() {
  int T = read();
  while (T--) {
    long long L = 1, R = 5E8, res = 0, M, N = read();
    while (L <= R) {
      M = (L + R) >> 1;
      F(M) < N ? (res = M, L = M + 1) : (R = M - 1);
    }
    N -= F(res), res += 1;
    int Ind = 1;
    while (N > a[Ind] * Ind) N -= a[Ind] * Ind, Ind++;
    long long ans = pow(10, Ind - 1) + N / Ind;
    N %= Ind;
    string e = to_string(ans);
    if (!N)
      printf("%d\n", (ans - 1) % 10);
    else
      printf("%c\n", e[N - 1]);
  }
}
