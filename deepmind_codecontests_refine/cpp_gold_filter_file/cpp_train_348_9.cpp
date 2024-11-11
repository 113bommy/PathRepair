#include <bits/stdc++.h>
using namespace std;
int length(set<pair<int, int> >& s) {
  int last = 0, len = 0;
  for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it) {
    if (last <= it->first) {
      len += it->second - it->first;
      last = it->second;
    } else if (it->second >= last) {
      len += it->second - last;
      last = it->second;
    }
  }
  return len;
}
int Buscar(set<pair<int, int> >& s, int obj) {
  int last = 0, len = 0;
  for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it) {
    if (it->first >= last) {
      len += it->first - last;
      last = it->second;
      if (len >= obj) {
        return it->first - (len - obj);
      }
    } else
      last = max(last, it->second);
  }
  return last - (len - obj);
}
int main() {
  int w, h, k;
  cin >> w >> h >> k;
  map<int, set<pair<int, int> > > hcuts, vcuts;
  for (int i = 0; i < k; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      vcuts[x1].insert(pair<int, int>(min(y1, y2), max(y1, y2)));
    else
      hcuts[y1].insert(pair<int, int>(min(x1, x2), max(x1, x2)));
  }
  int nim = 0;
  nim ^= h * ((w - 1 - vcuts.size()) % 2);
  nim ^= w * ((h - 1 - hcuts.size()) % 2);
  vector<pair<int, int> > hc, vc;
  for (map<int, set<pair<int, int> > >::iterator it = hcuts.begin();
       it != hcuts.end(); ++it) {
    hc.push_back(pair<int, int>(it->first, w - length(it->second)));
    nim ^= hc.back().second;
  }
  for (map<int, set<pair<int, int> > >::iterator it = vcuts.begin();
       it != vcuts.end(); ++it) {
    vc.push_back(pair<int, int>(it->first, h - length(it->second)));
    nim ^= vc.back().second;
  }
  if (nim) {
    cout << "FIRST" << endl;
    bool found = false;
    int last = 0, nvc = vc.size();
    for (int j = 0; j < nvc and not found; ++j) {
      int col = vc[j].first;
      if (col > last + 1) {
        if ((nim ^ h) <= h) {
          cout << last + 1 << " 0 " << last + 1 << " " << h - (nim ^ h) << endl;
          found = true;
        }
      }
      if (not found) {
        int libre = vc[j].second;
        if ((nim ^ libre) <= libre) {
          cout << col << " " << Buscar(vcuts[col], nim ^ libre) << " " << col
               << " " << h << endl;
          found = true;
        }
      }
      last = col;
    }
    if (not found and w > last + 1) {
      if ((nim ^ h) <= h) {
        cout << last + 1 << " 0 " << last + 1 << " " << h - (nim ^ h) << endl;
        found = true;
      }
    }
    last = 0;
    int nhc = hc.size();
    for (int j = 0; j < nhc and not found; ++j) {
      int row = hc[j].first;
      if (row > last + 1) {
        if ((nim ^ w) <= w) {
          cout << "0 " << last + 1 << " " << w - (nim ^ w) << " " << last + 1
               << endl;
          found = true;
        }
      }
      if (not found) {
        int libre = hc[j].second;
        if ((nim ^ libre) <= libre) {
          cout << Buscar(hcuts[row], nim ^ libre) << " " << row << " " << w
               << " " << row << endl;
          found = true;
        }
      }
      last = row;
    }
    if (not found and h > last + 1) {
      if ((nim ^ w) <= w) {
        cout << "0 " << last + 1 << " " << w - (nim ^ w) << " " << last + 1
             << endl;
        found = true;
      }
    }
  } else
    cout << "SECOND" << endl;
}
