#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;
map<int, int> mp;
int n, h;
void add() {
  int a, b;
  scanf("%d%d", &a, &b);
  while (a) {
    mp[a] += b;
    a >>= 1;
  }
}
inline int val(int x) { return mp[x]; }
inline int l(int x) { return x * 2; }
inline int r(int x) { return x * 2 + 1; }
double query(int x, int level, double pval) {
  if (level == h + 1) {
    return max(pval, 1.0 * val(x));
  }
  int v1 = val(x), v2 = val(l(x)), v3 = val(r(x));
  double costl = max(1.0 * (v1 - v3), pval);
  double costr = max(1.0 * (v1 - v2), pval);
  if (v2 > v3) {
    return costl * (1 << (h - level)) + query(r(x), level + 1, costr);
  } else if (v2 < v3) {
    return costr * (1 << (h - level)) + query(l(x), level + 1, costl);
  } else {
    return (double)costl * (1 << (h - level + 1));
  }
}
void query() { printf("%lf\n", query(1, 1, 0) / (1 << h)); }
int main() {
  scanf("%d%d", &h, &n);
  while (n--) {
    char op[8];
    scanf("%s", op);
    if (op[0] == 'a') {
      add();
    } else {
      query();
    }
  }
  return 0;
}
