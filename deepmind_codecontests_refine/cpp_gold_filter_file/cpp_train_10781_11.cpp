#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 99;
const int N = 1 << 19;
struct dat {
  long long d;
  int ans;
  int dL, dR;
  int lenL, lenR, len;
  void inc(long long dd) {
    d += dd;
    dL = dR = (d > 0) - (d < 0);
    lenL = lenR = ans = (d != 0);
    len = 1;
  }
  void merge(const dat &L, const dat &R) {
    ans = max(L.ans, R.ans);
    dL = L.dL;
    dR = R.dR;
    len = L.len + R.len;
    lenL = L.lenL;
    lenR = R.lenR;
    if (L.dR >= R.dL && L.dR && R.dL) {
      ans = max(ans, L.lenR + R.lenL);
      if (lenL == L.len) lenL += R.lenL;
      if (lenR == R.len) lenR += L.lenR;
    }
  }
} rmq[N + N];
void inc(int x, long long d) {
  x += N;
  rmq[x].inc(d);
  for (; x >>= 1;) rmq[x].merge(rmq[x + x], rmq[x + x + 1]);
}
int main() {
  int n;
  scanf("%d", &n);
  int pr = -1;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if (i > 1) inc(i - 1, a - pr);
    pr = a;
  }
  int m;
  scanf("%d", &m);
  for (; m--;) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    if (l > 1) inc(l - 1, d);
    if (r < n) inc(r, -d);
    printf("%d\n", rmq[1].ans + 1);
  }
}
