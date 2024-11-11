#include <bits/stdc++.h>
using namespace std;
namespace io {
const int __SIZE = (1 << 21) + 1;
char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1,
                                           __c, qu[55];
int __f, qr, _eof;
inline void flush() { fwrite(obuf, 1, oS - obuf, stdout), oS = obuf; }
inline void gc(char &x) {
  x = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                   (iS == iT ? EOF : *iS++))
                : *iS++);
}
inline void pc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
inline void pstr(const char *s) {
  int __len = strlen(s);
  for (__f = 0; __f < __len; ++__f) pc(s[__f]);
}
inline void gstr(char *s) {
  for (__c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++);
       __c < 32 || __c > 126 || __c == ' ';)
    __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                    : *iS++);
  for (; __c > 31 && __c < 127 && __c != ' ';
       ++s, __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++))
    *s = __c;
  *s = 0;
}
template <class I>
inline bool gi(I &x) {
  _eof = 0;
  for (__f = 1,
      __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                        (iS == iT ? EOF : *iS++))
                      : *iS++);
       (__c < '0' || __c > '9') && !_eof;
       __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++)) {
    if (__c == '-') __f = -1;
    _eof |= __c == EOF;
  }
  for (x = 0; __c <= '9' && __c >= '0' && !_eof;
       __c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++))
    x = x * 10 + (__c & 15), _eof |= __c == EOF;
  x *= __f;
  return !_eof;
}
template <class I>
inline void print(I x) {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) pc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io::gc;
using io::gi;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1000000007;
struct iP {
  ll num, den;
  iP(ll Num, ll Den) {
    num = Num;
    den = Den;
    if (num == 0 && den == 0) {
      cout << -1 << endl;
      exit(0);
    }
    if (den == 0) {
      if (num < 0) num = -100000000000;
      if (num > 0) num = 100000000000;
      den = 1;
    }
    if (den < 0) den = -den, num = -num;
  }
  const bool operator<(const iP &o) const {
    if (den * o.den > 0) return num * o.den < o.num * den;
    return num * o.den > o.num * den;
  }
  const bool operator<=(const iP o) const { return num * o.den <= o.num * den; }
};
vector<pair<iP, int>> event;
iP zero(0, 1);
bool fail = 0;
int x1, yyyyyyy1, x2, y2;
void isc(int rx, int ry, int vx, int vy) {
  iP tX1(x1 - rx, vx), tX2(x2 - rx, vx);
  iP tY1(yyyyyyy1 - ry, vy), tY2(y2 - ry, vy);
  if (tX2 < tX1) swap(tX1, tX2);
  event.push_back({tX1, 1});
  event.push_back({tX2, -1});
  if (tY2 < tY1) swap(tY1, tY2);
  event.push_back({tY1, 1});
  event.push_back({tY2, -1});
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  gi(n);
  gi(x1), gi(yyyyyyy1), gi(x2), gi(y2);
  for (int i = (0); i < (n); i++) {
    int rx, ry, vx, vy;
    gi(rx), gi(ry), gi(vx), gi(vy);
    isc(rx, ry, vx, vy);
  }
  sort(event.begin(), event.end());
  int tot = 2 * n, cur = 0;
  for (auto &k : event) {
    if (zero < k.first && cur == tot) {
      cout << "0.0" << endl;
      return 0;
    }
    cur += k.second;
    if (zero <= k.first && cur == tot) {
      cout << fixed << setprecision(20)
           << ((long double)(k.first.num)) / (k.first.den) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
