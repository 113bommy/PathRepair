#include <bits/stdc++.h>
using namespace std;
const signed inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
long long chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
long long chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T mmin(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T mmax(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T aabs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
long long dcmp(T a, T b) {
  return a > b;
}
template <long long *a>
long long cmp_a(long long first, long long second) {
  return a[first] < a[second];
}
namespace io {
const long long SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
long long f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char first) {
  *oS++ = first;
  if (oS == oT) flush();
}
inline bool read(signed &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
  return 1;
}
inline bool read(long long &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
  return 1;
}
inline bool read(char &first) {
  first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                    : *iS++);
  return first != EOF;
}
inline bool read(char *first) {
  while ((*first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                                (iS == iT ? EOF : *iS++))
                             : *iS++)) == '\n' ||
         *first == ' ' || *first == '\r')
    if (*first == EOF) return 0;
  while (!(*first == '\n' || *first == ' ' || *first == '\r'))
    *(++first) = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                           : *iS++);
  *first = 0;
  return 1;
}
template <typename A, typename... B>
inline bool read(A &first, B &...second) {
  return read(first) && read(second...);
}
inline bool write(signed first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(long long first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(char first) {
  putc(first);
  return 0;
}
inline bool write(const char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
inline bool write(char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
template <typename A, typename... B>
inline bool write(A first, B... second) {
  return write(first) || write(second...);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::putc;
using io ::read;
using io ::write;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    cars[200005];
priority_queue<pair<long long, pair<long long, long long> >,
               vector<pair<long long, pair<long long, long long> > >,
               greater<pair<long long, pair<long long, long long> > > >
    willOK;
set<long long> qaq;
long long cnt[200005];
void add(long long first) {
  if (!cnt[first]) qaq.insert(first);
  ++cnt[first];
}
void del(long long first) {
  if (!(--cnt[first])) qaq.erase(first);
}
pair<long long, pair<pair<long long, long long>, long long> > closest(
    long long first) {
  auto i = qaq.lower_bound(first);
  if (i == qaq.end()) {
    --i;
    return make_pair(aabs(*i - first), make_pair(cars[*i].top(), *i));
  }
  if (i == qaq.begin()) {
    return make_pair(aabs(*i - first), make_pair(cars[*i].top(), *i));
  }
  pair<long long, pair<pair<long long, long long>, long long> > s =
      make_pair(aabs(*i - first), make_pair(cars[*i].top(), *i));
  --i;
  chkmin(s, make_pair(aabs(*i - first), make_pair(cars[*i].top(), *i)));
  return s;
}
int main() {
  long long n, k, m, first, a, b, t, xt = 0;
  read(n, k, m);
  for (long long i = 1; i <= k; ++i) {
    read(first);
    cars[first].push(make_pair(0, i));
    add(first);
  }
  for (; m; --m) {
    read(t, a, b);
    long long st = t;
    while (!(willOK.empty()) && willOK.top().first <= t) {
      cars[willOK.top().second.first].push(
          make_pair(willOK.top().first, willOK.top().second.second));
      add(willOK.top().second.first);
      willOK.pop();
    }
    if (qaq.empty()) {
      xt = willOK.top().first;
      while (!willOK.empty() && willOK.top().first == xt) {
        cars[willOK.top().second.first].push(
            make_pair(willOK.top().first, willOK.top().second.second));
        add(willOK.top().second.first);
        willOK.pop();
      }
    }
    chkmax(st, xt);
    pair<long long, pair<pair<long long, long long>, long long> > car =
        closest(a);
    cars[car.second.second].pop();
    del(car.second.second);
    t += car.first;
    willOK.push(
        make_pair(t + aabs(b - a), make_pair(b, car.second.first.second)));
    write(car.second.first.second, ' ', t - st, '\n');
  }
  return 0;
}
