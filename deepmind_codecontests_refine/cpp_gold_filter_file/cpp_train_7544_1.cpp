#include <bits/stdc++.h>
using namespace std;
set<int> cuth, cutv;
set<pair<int, int> > dh, dv;
int w, h, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> w >> h >> n;
  cuth.insert(0);
  cuth.insert(h);
  dh.insert(make_pair(h, 1));
  cutv.insert(0);
  cutv.insert(w);
  dv.insert(make_pair(w, 1));
  while (n--) {
    char fi;
    int se;
    cin >> fi >> se;
    if (fi == 'H') {
      set<int>::iterator it1 = cuth.lower_bound(se), it2 = it1;
      it1--;
      int dis1 = se - (*it1), dis2 = (*it2) - se;
      set<pair<int, int> >::iterator it3 =
          dh.lower_bound(make_pair((*it2) - (*it1), 0));
      dh.erase(it3);
      pair<int, int> t = *it3;
      t.second--;
      if (t.second) dh.insert(t);
      it3 = dh.lower_bound(make_pair(dis1, 0));
      if (it3 == dh.end() or it3->first != dis1)
        dh.insert(make_pair(dis1, 1));
      else {
        t = *it3;
        dh.erase(it3);
        t.second++;
        dh.insert(t);
      }
      it3 = dh.lower_bound(make_pair(dis2, 0));
      if (it3 == dh.end() or it3->first != dis2)
        dh.insert(make_pair(dis2, 1));
      else {
        t = *it3;
        dh.erase(it3);
        t.second++;
        dh.insert(t);
      }
      cuth.insert(se);
    } else {
      set<int>::iterator it1 = cutv.lower_bound(se), it2 = it1;
      it1--;
      int dis1 = se - (*it1), dis2 = (*it2) - se;
      set<pair<int, int> >::iterator it3 =
          dv.lower_bound(make_pair((*it2) - (*it1), 0));
      dv.erase(it3);
      pair<int, int> t = *it3;
      t.second--;
      if (t.second) dv.insert(t);
      it3 = dv.lower_bound(make_pair(dis1, 0));
      if (it3 == dv.end() or it3->first != dis1)
        dv.insert(make_pair(dis1, 1));
      else {
        t = *it3;
        dv.erase(it3);
        t.second++;
        dv.insert(t);
      }
      it3 = dv.lower_bound(make_pair(dis2, 0));
      if (it3 == dv.end() or it3->first != dis2)
        dv.insert(make_pair(dis2, 1));
      else {
        t = *it3;
        dv.erase(it3);
        t.second++;
        dv.insert(t);
      }
      cutv.insert(se);
    }
    set<pair<int, int> >::iterator ith = dh.end(), itv = dv.end();
    ith--;
    itv--;
    cout << 1LL * (ith->first) * (itv->first) << endl;
  }
  return 0;
}
