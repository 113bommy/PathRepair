#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y, u, v;
  pair<int, int> p;
  multiset<pair<int, int> >::iterator iter, busca;
  multiset<int>::iterator iter2, busca2;
  while (cin >> n >> m) {
    multiset<pair<int, int> > mark, tapa;
    multiset<int> solo, dim;
    while (n--) cin >> x >> y, mark.insert(make_pair(x, y));
    while (m--) cin >> x >> y, tapa.insert(make_pair(x, y));
    u = v = 0;
    for (iter = mark.begin(); iter != mark.end(); iter++) {
      busca = tapa.find(*iter);
      if (busca != tapa.end()) {
        tapa.erase(busca);
        u++, v++;
      } else {
        p = *iter;
        solo.insert(p.second);
      }
    }
    for (iter = tapa.begin(); iter != tapa.end(); iter++) {
      p = *iter;
      dim.insert(p.second);
    }
    for (iter2 = solo.begin(); iter2 != solo.end(); iter2++) {
      busca2 = dim.find(*iter2);
      if (busca2 != dim.end()) {
        dim.erase(busca2);
        u++;
      }
    }
    cout << u << " " << v << endl;
  }
  return (0);
}
