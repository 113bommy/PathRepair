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
inline void gp(I x) {
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
using io::gp;
using io::gstr;
using io::pc;
using io::pstr;
void scan() { return; }
template <class T, typename... Args>
void scan(T &a, Args &&...args) {
  gi(a);
  scan(args...);
  return;
}
template <typename T>
void scann(T a, T b) {
  for (auto it = a; it != b; ++it) scan(*it);
}
template <typename T>
void scerr(T a, T b) {
  for (auto it = a; it != b; ++it) cerr << *it << " ";
  cerr << '\n';
}
void print() {
  pc('\n');
  return;
}
template <class T, typename... Args>
void print(T a, Args... args) {
  gp(a);
  pc(' ');
  print(args...);
  return;
}
void cer() { return; }
template <class T, typename... Args>
void cer(T a, Args... args) {
  cerr << " " << a;
  cer(args...);
  return;
}
const int N = 5e5 + 5;
const int M = 5e5;
const long long mod = 1e9 + 7;
const int inf = 1e9 + 3;
const long long INF = 1e15;
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
void data() {}
int T, n, was[N];
long long p, k[N], ans;
vector<long long> v;
stack<pair<int, int> > a;
long long add(long long a, long long b) {
  return (a + b + mod + mod + mod) % mod;
}
long long mul(long long a, long long b) { return (a * b) % mod; }
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n & 1) {
    return mul(binpow(a, n - 1), a);
  } else {
    long long cnt = binpow(a, n / 2);
    return mul(cnt, cnt);
  }
}
void add(int pw);
void make() {
  while ((int)a.size() && a.top().second == p) {
    int cnt = a.top().first + 1;
    a.pop();
    add(cnt);
  }
}
void add(int pw) {
  if ((int)a.size() && a.top().first == pw) {
    int cnt = a.top().second + 1;
    a.pop();
    a.push(make_pair(pw, cnt));
  } else {
    a.push(make_pair(pw, 1));
  }
}
int main() {
  data();
  scanf("%d", &T);
  while (T--) {
    scanf("%d %lld", &n, &p);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &k[i]);
    }
    ans = 0;
    if (p == 1) {
      printf("%d\n", n % 2);
      continue;
    }
    v.clear();
    for (int i = 1; i <= n; ++i) {
      v.push_back(k[i]);
      was[k[i]]++;
    }
    while ((int)a.size()) a.pop();
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
      if (was[v[i]] % 2 == 0) {
        continue;
      } else {
        while ((int)a.size()) a.pop();
        ans = add(ans, binpow(p, v[i]));
        bool f = 0;
        int ni;
        for (int j = i + 1; j < (int)v.size(); ++j) {
          for (int k = 1; k <= was[v[j]]; ++k) {
            add(v[j]);
            make();
            ans = add(ans, -binpow(p, v[j]));
            if ((int)a.size() == 1 && a.top().first == v[i]) {
              ni = j;
              f = 1;
              was[v[j]] -= k;
              break;
            }
          }
          if (f) break;
        }
        if (f) {
          i = ni - 1;
        } else {
          break;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      was[k[i]] = 0;
    }
    printf("%lld\n", ans);
  }
}
