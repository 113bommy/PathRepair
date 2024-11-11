#include <bits/stdc++.h>
using namespace std;
int n, q;
map<int, int> r;
map<int, int> l;
int main() {
  scanf("%d%d", &n, &q);
  map<int, int>::iterator it;
  for (int i = 0; i < q; i++) {
    int x, y;
    char cm[2];
    scanf("%d%d%s", &x, &y, cm);
    if (cm[0] == 'U') {
      if (r.count(x)) {
        printf("0\n");
        continue;
      }
      it = r.lower_bound(x);
      int res;
      if (it == r.end()) {
        res = y;
      } else {
        res = y - it->second;
      }
      printf("%d\n", res);
      r[x] = y - res;
      l[y] = x;
    } else {
      if (l.count(y)) {
        printf("0\n");
        continue;
      }
      int res;
      it = l.lower_bound(y);
      if (it == l.end()) {
        res = x;
      } else {
        res = x - it->second;
      }
      printf("%d\n", res);
      l[y] = x - res;
      r[x] = y;
    }
  }
  return 0;
}
