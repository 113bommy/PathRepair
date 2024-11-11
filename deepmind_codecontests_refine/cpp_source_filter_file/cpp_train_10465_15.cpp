#include <bits/stdc++.h>
using namespace std;
const int Max_R(3050);
const int Max_C(3050);
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
int R, C, N, K, Pre[Max_C], Nxt[Max_C], Val[Max_C], Sta[Max_C], Le[Max_C],
    Re[Max_C], Lim[Max_C], Inc[Max_C];
vector<int> V[Max_R];
long long int Ans, Sum;
inline int js(int p) { return (p - Pre[p]) * (C - Lim[p] + 1); }
int main() {
  gi(R), gi(C), gi(N), gi(K);
  for (int x, y; N--;) gi(x), gi(y), V[x].push_back(y);
  for (int U = 1; U <= R; ++U) {
    memset(Val, 0X3F, sizeof(Val)), Val[0] = Val[C + 1] = 0;
    for (int D = U, cnt = 0; D <= R; ++D)
      for (int i = 0; i < V[D].size(); ++i)
        Val[V[D][i]] = min(Val[V[D][i]], ++cnt);
    Sta[Sta[0] = 1] = 0;
    for (int i = 1; i <= C; ++i) {
      while (Val[i] < Val[Sta[Sta[0]]]) --Sta[0];
      Le[i] = Sta[Sta[0]], Sta[++Sta[0]] = i;
    }
    Sta[Sta[0] = 1] = C + 1;
    for (int i = C; i >= 1; --i) {
      while (Val[i] < Val[Sta[Sta[0]]]) --Sta[0];
      Re[i] = Sta[Sta[0]], Sta[++Sta[0]] = i;
    }
    Nxt[0] = C + 1, Pre[C + 1] = 0;
    memset(Val, 0, sizeof(Val)), memset(Inc, 0, sizeof(Inc)),
        Inc[0] = Val[Lim[0] = 0] = Inc[C + 1] = Val[Lim[C + 1] = C + 1] = K;
    Sum = 0LL;
    for (int D = U; D <= R; ++D) {
      for (int i = 0, y; i < V[D].size(); ++i) {
        if ((++Val[y = V[D][i]]) == 1) {
          Sum -= js(Nxt[y]);
          Nxt[Pre[y] = Le[y]] = Pre[Nxt[y] = Re[y]] = y;
          for (int &u = (Lim[y] = y);; u = Nxt[u])
            if ((Inc[y] += Val[u]) >= K) break;
          Sum += js(y);
          Sum += js(Nxt[y]);
        }
        for (int u = (Val[y] == 1 ? Pre[y] : y), cnt = 0; u; u = Pre[u]) {
          Sum -= js(u);
          Lim[u] = Lim[Nxt[u]], Inc[u] = Inc[Nxt[u]] + Val[u];
          for (;; Lim[u] = Pre[Lim[u]])
            if ((Inc[u] -= Val[Lim[u]]) < K) {
              Inc[u] += Val[Lim[u]];
              break;
            }
          Sum += js(u);
          if ((++cnt) == K) break;
        }
      }
      Ans += Sum;
    }
  }
  print(Ans);
  return 0;
}
