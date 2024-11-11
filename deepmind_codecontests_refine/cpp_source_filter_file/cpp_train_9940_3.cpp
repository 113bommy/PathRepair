#include <bits/stdc++.h>
using namespace std;
struct chunk {
  set<int> sid;
  map<int, int> len_map;
  multiset<int> lens;
  chunk(int n) {
    sid.insert(0);
    len_map[0] = n;
    lens.insert(n);
  }
  void partition(int v) {
    auto f = *(--sid.lower_bound(v));
    sid.insert(v);
    int ol = len_map[f];
    len_map[v] = ol - v;
    len_map[f] = v - f;
    lens.erase(lens.find(ol));
    lens.insert(ol - v);
    lens.insert(v - f);
  }
  int max() { return *lens.rbegin(); }
};
int main() {
  int w, h, n;
  scanf("%d", &w), scanf("%d", &h), scanf("%d", &n);
  chunk hc(h), vc(w);
  while (n--) {
    char t;
    int v;
    scanf(" %c %d", &t, &v);
    if (t == 'H')
      hc.partition(v);
    else
      vc.partition(v);
    printf("%lld\n", (hc.max() * 1LL * vc.max()));
  }
  return 0;
}
