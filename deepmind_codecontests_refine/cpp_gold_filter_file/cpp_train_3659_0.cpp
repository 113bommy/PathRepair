#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int DIG = 11;
struct tT {
  int h, m;
} beg, en;
int h, m, k;
void init();
void input();
void work();
long long getans(int hh, int mm);
int getcc(int x, int nk);
int getn0(int x) {
  int cc = 0;
  while (x) {
    if (x % 10) ++cc;
    x /= 10;
  }
  return cc;
}
string tos(int a) {
  string s;
  for (int i = 0; i < DIG; ++i) {
    s = static_cast<char>(a % 10 + '0') + s;
    a /= 10;
  }
  return s;
}
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d%d", &h, &m, &k);
  scanf("%d%d", &beg.h, &beg.m);
  scanf("%d%d", &en.h, &en.m);
}
void work() {
  long long ans = getans(en.h, en.m) - getans(beg.h, beg.m);
  if (en.h < beg.h || (en.h == beg.h && en.m < beg.m)) {
    ans += getans(h - 1, m - 1);
    if (getn0(h - 1) + getn0(m - 1) >= k) ++ans;
  }
  printf("%I64d\n", ans);
}
long long getans(int hh, int mm) {
  return (1LL * hh * getcc(m - 1, k) + getcc(mm, k) +
          getcc(hh, (((k - getn0(m - 1)) > (1)) ? (k - getn0(m - 1)) : (1))));
}
int getcc(int x, int nk) {
  int ans = 0, bs = 0;
  string nx = tos(x);
  for (int i = 0; i < DIG; ++i) {
    bs *= 10;
    bs += nx[i] - '0';
    if (DIG - i == nk) ans = bs;
  }
  return ans;
}
