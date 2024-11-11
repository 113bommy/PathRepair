#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 50;
int n, k;
struct node {
  int mn[12], mx[12], sz;
  bool operator<(const node &A) const {
    for (int i = 0; i < k; i++)
      if (mx[i] > A.mn[i]) return false;
    return true;
  }
  void scan() {
    sz = 1;
    for (int i = 0; i < k; i++) {
      scanf("%d", &mn[i]);
      mx[i] = mn[i];
    }
  }
};
set<node> S;
set<node>::iterator iter1, iter2;
int main() {
  while (scanf("%d%d", &n, &k) == 2) {
    S.clear();
    node tmp;
    for (int i = 0; i < n; i++) {
      tmp.scan();
      iter1 = S.lower_bound(tmp);
      iter2 = S.upper_bound(tmp);
      while (iter1 != iter2) {
        for (int j = 0; j < k; j++) {
          tmp.mn[j] = min(tmp.mn[j], iter1->mn[j]);
          tmp.mx[j] = max(tmp.mx[j], iter1->mx[j]);
        }
        tmp.sz += iter1->sz;
        S.erase(iter1++);
      }
      S.insert(tmp);
      printf("%d\n", (--S.end())->sz);
    }
  }
  return 0;
}
