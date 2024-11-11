#include <bits/stdc++.h>
using namespace std;
int n, m, q;
long long All;
struct bit {
  long long s1[4010000];
  long long s2[4010000];
  int N;
  inline void init(int b) { N = b; }
  inline void adder(int r, long long v) {
    if (!r) return;
    for (int x = r; x <= N; x += x & -x) s2[x] += v * r, s1[x] += v;
  }
  inline void add(int l, int r, long long v) {
    adder(r, v);
    adder(l - 1, -v);
  }
  inline long long asker(int x) {
    long long res = 0;
    for (int r = x; r; r -= r & -r) res += s2[r];
    for (int r = N; r; r -= r & -r) res += s1[r] * x;
    for (int r = x; r; r -= r & -r) res -= s1[r] * x;
    return res;
  }
  inline long long ask(int l, int r) {
    long long res = 0;
    res = asker(r);
    res -= asker(l - 1);
    return res;
  }
} X, Y;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  X.init(n);
  Y.init(m);
  for (int i = 1; i <= q; i++) {
    int x1, x2, y1, y2, type, v;
    scanf("%d%d%d%d%d", &type, &x1, &y1, &x2, &y2);
    if (type) {
      long long res = All;
      res -= X.ask(x1, x2);
      res -= Y.ask(y1, y2);
      printf("%I64d\n", -res);
    } else {
      scanf("%d", &v);
      All += v * 1ll * (x2 - x1 + 1) * (y2 - y1 + 1);
      X.add(x1, x2, (y2 - y1 + 1) * 1ll * v);
      Y.add(y1, y2, (x2 - x1 + 1) * 1ll * v);
    }
  }
  return 0;
}
