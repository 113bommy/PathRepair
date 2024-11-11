#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MINF = 0x80000000;
const long long mod = 1000000007;
const int cons = 100001;
struct fenwickTree {
  vector<long long> tree;
  fenwickTree(int n) { tree.resize(n + 1); }
  void upd(int pos, long long vl) {
    while (pos < tree.size()) {
      tree[pos] += vl;
      pos += (pos & -pos);
    }
  }
  long long sum(int pos) {
    long long ret = 0;
    while (pos) {
      ret += tree[pos];
      pos &= (pos - 1);
    }
    return ret;
  }
};
int main() {
  int n, k, q;
  long long a, b;
  scanf("%d%d%I64d%I64d%d", &n, &k, &a, &b, &q);
  fenwickTree before(n), after(n);
  for (int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int d;
      long long x;
      scanf("%d%I64d", &d, &x);
      long long bt = before.sum(d) - before.sum(d - 1);
      long long at = after.sum(d) - after.sum(a - 1);
      if (bt != b) {
        long long diff = b - bt;
        before.upd(d, min(diff, x));
      }
      if (at != a) {
        long long diff = a - at;
        after.upd(d, min(diff, x));
      }
    } else {
      int p;
      scanf("%d", &p);
      long long s =
          before.sum(p - 1) + after.sum(n) - after.sum(min(n, p + k - 1));
      printf("%I64d\n", s);
    }
  }
  return 0;
}
