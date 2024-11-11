#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int ios = 1 << 17;
char R[ios], P[ios], *Rc = R, *RB = R, *Pc = P;
const char* PB = P + ios;
int stk[50], tp = 0, pass;
inline void flush() {
  fwrite(P, 1, Pc - P, stdout);
  Pc = P;
}
inline int gec() {
  return (Rc == RB && (RB = (Rc = R) + fread(R, 1, ios, stdin), Rc == RB))
             ? EOF
             : *Rc++;
}
inline void puc(const char& c) {
  if (Pc == PB) flush();
  *(Pc++) = c;
}
template <typename Tp>
inline int read(Tp& A) {
  static int c, sg;
  c = gec();
  sg = 0;
  A = 0;
  while (!isdigit(c) && c != EOF) sg |= (c == '-'), c = gec();
  if (c == EOF) return EOF;
  while (isdigit(c)) A = (A << 3) + (A << 1) + (c ^ '0'), c = gec();
  return A = sg ? -A : A, 0;
}
inline int read() { return read(pass), pass; }
template <typename Tp>
inline void print(Tp A) {
  if (A < 0) puc('-');
  if (!A) puc('0');
  for (int Q, P; A; A = Q) Q = A / 10, P = A - 10 * Q, stk[++tp] = P ^ '0';
  while (stk[tp]) puc(stk[tp--]);
}
}  // namespace IO
using IO::flush;
using IO::gec;
using IO::print;
using IO::puc;
using IO::read;
const int N = 1e7 + 10;
int n, m, res;
int f[N], a[N], b[N], Q[N];
int gf(int x) { return f[x] == x ? x : (f[x] = gf(f[x])); }
int Uid(int x) { return lower_bound(Q + 1, Q + m + 1, x) - Q; }
void Upd(int x) {
  if (x > res) res = x;
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
  memcpy(Q + 1, a + 1, sizeof(int) * n);
  memcpy(Q + n + 1, b + 1, sizeof(int) * n);
  sort(Q + 1, Q + n + n + 1);
  m = unique(Q + 1, Q + n + n + 1) - Q - 1;
  for (int i = 1; i <= m; i++) f[i] = i;
  for (int i = 1; i <= n; i++) {
    int x = gf(Uid(a[i])), y = gf(Uid(b[i]));
    if (!x && !y) {
      puts("-1");
      return 0;
    }
    if (x > y) swap(x, y);
    if (x == y || !x || !y)
      Upd(max(x, y)), f[x] = f[y] = 0;
    else
      Upd(min(x, y)), f[x] = y;
  }
  printf("%d", Q[res]);
  return flush(), 0;
}
