#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace _buff {
const size_t BUFF = 1 << 19;
char buff[BUFF], *begin = buff, *end = buff;
char getc() {
  if (begin == end) {
    begin = buff;
    end = buff + fread(buff, 1, BUFF, stdin);
  }
  return begin == end ? -1 : *begin++;
}
}  // namespace _buff
LL read() {
  using namespace _buff;
  LL ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
    assert(~c);
  }
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc()) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  }
  return pos ? ret : -ret;
}
const size_t N = 1e5 + 5;
struct Point {
  LL x, y;
  Point(LL x = 0, LL y = 0) : x(x), y(y) {}
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  bool operator<(const Point &p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  LL operator%(const Point &p) const { return x * p.y - y * p.x; }
} p[N];
int n, stk[N], tp;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    LL x = read(), y = read();
    p[i] = Point(x, y - x * x);
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    while (tp > 1 && (p[stk[tp]] - p[stk[tp - 1]]) % (p[i] - p[stk[tp]]) >= 0)
      --tp;
    stk[++tp] = i;
  }
  int st = 1;
  while (st < tp && p[stk[st]].x == p[stk[st + 1]].x) ++st;
  cout << tp - st << '\n';
  return 0;
}
