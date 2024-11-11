#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, n;
  cin >> w >> h >> n;
  set<pair<int, int> > vi, hi;
  multiset<int> vt, ht;
  vi.insert({0, w});
  hi.insert({0, h});
  vt.insert(w);
  ht.insert(h);
  int maxh = h, maxv = w;
  for (int i = 0, Wub = n; i < Wub; ++i) {
    char x;
    int y;
    cin >> x >> y;
    if (x == 'H') {
      set<pair<int, int> >::iterator it = hi.lower_bound({y, 0});
      it--;
      int au1 = it->first, au2 = it->second;
      hi.erase(it);
      hi.insert({au1, y - au1});
      hi.insert({y, au2 + au1 - y});
      set<int>::iterator it1 = ht.find(au2);
      ht.erase(it1);
      ht.insert(y - au1);
      ht.insert(au2 + au1 - y);
      maxh = *ht.rbegin();
      cout << maxh * maxv << "\n";
    } else {
      set<pair<int, int> >::iterator it = vi.lower_bound({y, 0});
      it--;
      int au1 = it->first, au2 = it->second;
      vi.erase(it);
      vi.insert({au1, y - au1});
      vi.insert({y, au2 + au1 - y});
      set<int>::iterator it1 = vt.find(au2);
      vt.erase(it1);
      vt.insert(y - au1);
      vt.insert(au2 + au1 - y);
      maxv = *vt.rbegin();
      cout << maxh * maxv << "\n";
    }
  }
  return 0;
}
