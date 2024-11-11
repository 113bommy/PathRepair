#include <bits/stdc++.h>
using namespace std;
const int Max_N(5050);
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <class I>
inline void gi(I &x) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= f;
}
template <class I>
inline void print(I x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io::gi;
using io::print;
using io::putc;
int N, S, E, X[Max_N], A[Max_N], B[Max_N], C[Max_N], D[Max_N];
long long int F[2][Max_N];
inline void upd(long long int &a, long long int b) { a = min(a, b); }
int main() {
  gi(N), gi(S), gi(E);
  for (int i = 1; i <= N; ++i) gi(X[i]);
  for (int i = 1; i <= N; ++i) gi(A[i]), A[i] += X[i];
  for (int i = 1; i <= N; ++i) gi(B[i]), B[i] -= X[i];
  for (int i = 1; i <= N; ++i) gi(C[i]), C[i] += X[i];
  for (int i = 1; i <= N; ++i) gi(D[i]), D[i] -= X[i];
  memset(F[0], 0X3F, sizeof(F[0])), F[0][0] = 0LL;
  int now = 0, lst = 1;
  for (int i = 1, a = 0, b = 0; i <= N; ++i) {
    now ^= 1, lst ^= 1, memset(F[now], 0X3F, sizeof(F[now]));
    for (int x = a + b; x <= i - 1; ++x) {
      upd(F[now][x + 1], F[lst][x] + (i != E) * D[i] + (i != S) * B[i]);
      if (i != E && x - a >= 1)
        upd(F[now][x], F[lst][x] + C[i] + B[i] * (i != S));
      if (i != S && x - b >= 1)
        upd(F[now][x], F[lst][x] + D[i] * (i != E) + A[i]);
      if (i != S && i != E && x >= 2)
        upd(F[now][x - 1], F[lst][x] + A[i] + C[i]);
    }
    a += (i == S), b += (i == E);
  }
  print(F[now][1]);
  return 0;
}
