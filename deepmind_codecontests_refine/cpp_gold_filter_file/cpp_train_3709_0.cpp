#include <bits/stdc++.h>
using namespace std;
int n, k;
struct node {
  int mx[15], mn[15], siz;
  bool operator<(const node &x) const {
    for (int i = 1; i <= k; ++i)
      if (mx[i] > x.mn[i]) return false;
    return true;
  }
};
set<node> s;
int main() {
  cin >> n >> k;
  while (n--) {
    node p;
    for (int i = 1; i <= k; ++i) {
      int x;
      scanf("%d", &x);
      p.mn[i] = p.mx[i] = x;
    }
    p.siz = 1;
    auto l = s.lower_bound(p);
    auto r = s.upper_bound(p);
    while (l != r) {
      p.siz += l->siz;
      for (int i = 1; i <= k; ++i) {
        p.mn[i] = min(p.mn[i], l->mn[i]);
        p.mx[i] = max(p.mx[i], l->mx[i]);
      }
      s.erase(l++);
    }
    s.insert(p);
    printf("%d\n", s.rbegin()->siz);
  }
  return 0;
}
