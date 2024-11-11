#include <bits/stdc++.h>
using namespace std;
const long long ml = 1e6 + 101;
const long long mo = 1e9 + 7;
long long n, m, t;
inline long long read() {
  long long r = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return r * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void port(long long x, char s) {
  write(x);
  putchar(s);
}
struct Segment_tree {
  long long tag[ml << 2], sum[ml << 2];
  void push_down(long long x) {
    if (tag[x] == 0) return;
    tag[x << 1] = tag[x << 1 | 1] = 1;
    sum[x << 1] = sum[x << 1 | 1] = 0;
    tag[x] = 0;
  }
  void push_up(long long x) { sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % mo; }
  void modify(long long dir, long long k, long long x = 1, long long l = 1,
              long long r = m) {
    if ((dir == l) && (dir == r)) return sum[x] = k, void();
    push_down(x);
    long long mid = (l + r) >> 1;
    if (dir <= mid)
      modify(dir, k, x << 1, l, mid);
    else
      modify(dir, k, x << 1 | 1, mid + 1, r);
    push_up(x);
  }
  void clear(long long ql, long long qr, long long x = 1, long long l = 1,
             long long r = m) {
    if ((ql <= l) && (qr >= r)) return tag[x] = 1, sum[x] = 0, void();
    push_down(x);
    long long mid = (l + r) >> 1;
    if (ql <= mid) clear(ql, qr, x << 1, l, mid);
    if (qr > mid) clear(ql, qr, x << 1 | 1, mid + 1, r);
    push_up(x);
  }
  long long query(long long ql, long long qr, long long x = 1, long long l = 1,
                  long long r = m) {
    if ((ql <= l) && (qr >= r)) return sum[x];
    push_down(x);
    long long mid = (l + r) >> 1, res = 0;
    if (ql <= mid) res = (res + query(ql, qr, x << 1, l, mid)) % mo;
    if (qr > mid) res = (res + query(ql, qr, x << 1 | 1, mid + 1, r)) % mo;
    return res;
  }
} str;
vector<pair<long long, long long> > add[ml], del[ml];
multiset<pair<long long, long long> > s;
int main() {
  n = read(), m = read(), t = read();
  for (long long i = 1; i <= t; i++) {
    long long X1 = read(), Y1 = read(), X2 = read(), Y2 = read();
    add[X1].push_back(make_pair(Y1, Y2));
    del[X2 + 1].push_back(make_pair(Y1, Y2));
  }
  s.insert(make_pair(0, 0));
  for (auto Seg : add[1]) s.insert(Seg);
  str.modify(1, 1);
  for (long long i = 2; i <= n; i++) {
    sort(add[i].begin(), add[i].end());
    reverse(add[i].begin(), add[i].end());
    for (auto Seg : add[i]) {
      long long x = Seg.first, y = Seg.second;
      if (y == m) continue;
      auto it = s.lower_bound(make_pair(y + 2, 0));
      it--;
      long long ans = 0;
      auto tmp = *it;
      if (tmp.second <= y) ans = str.query(tmp.second + 1, y + 1);
      str.modify(y + 1, ans);
    }
    for (auto Seg : del[i]) s.erase(Seg);
    for (auto Seg : add[i]) s.insert(Seg), str.clear(Seg.first, Seg.second);
  }
  auto it = s.end();
  it--;
  port(str.query((*it).second + 1, m), '\n');
  return 0;
}
