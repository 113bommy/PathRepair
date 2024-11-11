#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int memo[200000 + 5][8];
int main() {
  int n;
  scanf("%d", &n);
  int a[3];
  scanf("%d%d%d", a, a + 1, a + 2);
  sort(a, a + 3);
  int st = 0;
  multiset<int> t;
  for (int i = 0, _n = n; i < _n; i++) {
    int tr;
    scanf("%d", &tr);
    t.insert(tr);
    if (tr > a[0] + a[1] + a[2]) {
      printf("-1\n");
      return 0;
    }
  }
  while (t.upper_bound(a[1] + a[2]) != t.end()) {
    t.erase(t.upper_bound(a[2] + a[1]));
    st++;
  }
  while (t.upper_bound(a[0] + a[2]) != t.end()) {
    t.erase(t.upper_bound(a[0] + a[2]));
    multiset<int>::iterator it = t.upper_bound(a[1]);
    if (it != t.begin()) {
      it--;
      t.erase(it);
    }
    st++;
  }
  int vecji = max(a[0] + a[1], a[2]);
  while (t.upper_bound(vecji) != t.end()) {
    t.erase(t.upper_bound(vecji));
    multiset<int>::iterator it = t.upper_bound(a[0]);
    if (it != t.begin()) {
      it--;
      t.erase(it);
    }
    st++;
  }
  int x = 0, y = 0;
  for (multiset<int>::iterator it = t.begin(); it != t.end(); it++) {
    if (*it <= a[0] + a[1]) x++;
    if (*it <= a[2]) y++;
  }
  int mali = 200000 + 4;
  for (int i = 0; i < n; i++) {
    mali = min(mali, i + max((int)(t.size() + 1) / 2, abs(x - y)));
    if (t.size() == 0) break;
    multiset<int>::iterator it = t.upper_bound(a[0]);
    if (it != t.begin()) {
      it--;
      t.erase(it);
      x--;
      y--;
    }
    it = t.upper_bound(a[1]);
    if (it != t.begin()) {
      it--;
      t.erase(it);
      x--;
      y--;
    }
    it = t.upper_bound(a[2]);
    if (it != t.begin()) {
      it--;
      if (*it <= a[0] + a[1]) x--;
      t.erase(it);
      y--;
    }
  }
  st += mali;
  printf("%d\n", st);
  return 0;
}
