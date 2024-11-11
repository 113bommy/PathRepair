#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6;
long long rd() {
  long long x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
long long m;
int q;
struct node {
  long long x, y;
  bool operator<(const node &bb) const { return x < bb.x; }
  node operator-(const node &bb) const { return (node){x - bb.x, y - bb.y}; }
  long long operator*(const node &bb) const { return x * bb.y - y * bb.x; }
} aa, bb;
multiset<node> sb;
multiset<node>::iterator ft, it, rbq;
int main() {
  q = rd(), m = rd();
  sb.insert((node){0, 0});
  int la = 0;
  for (int h = 1; h <= q; ++h) {
    int op = rd();
    long long x = (rd() + la) % mod + 1, y = (rd() + la) % mod + 1;
    if (op == 1) {
      it = --sb.upper_bound((node){x, 0});
      if (it != (--sb.end())) {
        ft = it, ++ft;
        aa = *it, bb = *ft;
        if (aa.y * (bb.x - aa.x) + (x - aa.x) * (bb.y - aa.y) <=
            y * (bb.x - aa.x))
          continue;
      }
      aa = (node){x, y};
      ft = it, --ft;
      while (it != sb.begin() && (aa - (*ft)) * ((*it) - (*ft)) >= 0) {
        rbq = it, --ft, --it;
        sb.erase(rbq);
      }
      it = sb.upper_bound(aa), ft = it, ++ft;
      while (it != (--sb.end()) && it != sb.end() &&
             ((*it) - aa) * ((*ft) - aa) >= 0) {
        rbq = it, ++ft, ++it;
        sb.erase(rbq);
      }
      sb.insert(aa);
    } else {
      if ((*(--sb.end())).x < (y + x - 1) / x) {
        puts("NO");
        continue;
      }
      it = sb.lower_bound((node){(y + x - 1) / x, 0});
      bb = *it, aa = *(--it);
      if (x * aa.y * (bb.x - aa.x) + (y - x * aa.x) * (bb.y - aa.y) <=
          m * (bb.x - aa.x))
        la = h, puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
