#include <bits/stdc++.h>
using namespace std;
struct widget {
  string name;
  long long x, y;
};
struct box {
  string name;
  bool type;
  long long border, spacing, x, y;
  vector<pair<int, bool> > pack;
};
vector<widget> vw;
vector<box> vb;
pair<long long, long long> go(int n) {
  pair<long long, long long> xy;
  int xx = 0, yy = 0;
  for (int j = 0; j < vb[n].pack.size(); j++) {
    if (vb[n].pack[j].second == 1) {
      if (vb[vb[n].pack[j].first].x == -1)
        xy = go(vb[n].pack[j].first);
      else {
        xy.first = vb[vb[n].pack[j].first].x;
        xy.second = vb[vb[n].pack[j].first].y;
      }
    } else
      xy = make_pair(vw[vb[n].pack[j].first].x, vw[vb[n].pack[j].first].y);
    if (vb[n].type == 0) {
      if (xy.second > yy) yy = xy.second;
      xx += xy.first;
    } else {
      if (xy.first > xx) xx = xy.first;
      yy += xy.second;
    }
  }
  if (vb[n].pack.size() > 0) {
    xx = xx + vb[n].border * 2;
    yy = yy + vb[n].border * 2;
    if (vb[n].pack.size() > 0 && vb[n].type == 0) {
      xx += (vb[n].pack.size() - 1) * vb[n].spacing;
    } else {
      yy += (vb[n].pack.size() - 1) * vb[n].spacing;
    }
  }
  vb[n].x = xx;
  vb[n].y = yy;
  return make_pair(xx, yy);
}
int main() {
  int n;
  pair<long long, long long> xy;
  string com, name, x, y;
  widget vwv;
  box vbv;
  long long a, b, xx, yy;
  cin >> n;
  getline(cin, com);
  for (int i = 0; i < n; i++) {
    getline(cin, com);
    if (com.find("Widget") == 0) {
      a = com.find("(");
      b = com.find(",");
      vwv.name = com.substr(7, a - 7);
      x = com.substr(a + 1, b - (a + 1));
      y = com.substr(b + 1, com.size() - 1 - (b + 1));
      xx = 0;
      for (int j = 0; j < x.size(); j++) {
        xx = xx * 10 + (x[j] - '0');
      }
      yy = 0;
      for (int j = 0; j < y.size(); j++) {
        yy = yy * 10 + (y[j] - '0');
      }
      vwv.x = xx;
      vwv.y = yy;
      vw.push_back(vwv);
    }
    if (com.find("HBox") == 0) {
      vbv.name = com.substr(5, com.size() - 5);
      vbv.type = 0;
      vbv.border = 0;
      vbv.spacing = 0;
      vbv.x = -1;
      vb.push_back(vbv);
    }
    if (com.find("VBox") == 0) {
      vbv.name = com.substr(5, com.size() - 5);
      vbv.type = 1;
      vbv.border = 0;
      vbv.spacing = 0;
      vbv.x = -1;
      vb.push_back(vbv);
    }
    if (com.find(".pack") < com.size()) {
      name = com.substr(0, com.find("."));
      for (a = 0; a < vb.size(); a++) {
        if (name == vb[a].name) break;
      }
      name = com.substr(com.find(".pack(") + 6,
                        com.size() - 1 - (com.find(".pack(") + 6));
      for (b = 0; b < vw.size(); b++) {
        if (name == vw[b].name) break;
      }
      if (b < vw.size() && name == vw[b].name)
        vb[a].pack.push_back(make_pair(b, 0));
      else {
        for (b = 0; b < vb.size(); b++) {
          if (name == vb[b].name) break;
        }
        vb[a].pack.push_back(make_pair(b, 1));
      }
    }
    if (com.find(".set_border") < com.size()) {
      name = com.substr(0, com.find("."));
      for (a = 0; a < vb.size(); a++) {
        if (name == vb[a].name) break;
      }
      y = com.substr(com.find(".set_border") + 12,
                     com.size() - 1 - (com.find(".set_border") + 12));
      yy = 0;
      for (int j = 0; j < y.size(); j++) {
        yy = yy * 10 + (y[j] - '0');
      }
      vb[a].border = yy;
    }
    if (com.find(".set_spacing") < com.size()) {
      name = com.substr(0, com.find("."));
      for (a = 0; a < vb.size(); a++) {
        if (name == vb[a].name) break;
      }
      y = com.substr(com.find(".set_spacing") + 13,
                     com.size() - 1 - (com.find(".set_spacing") + 13));
      yy = 0;
      for (int j = 0; j < y.size(); j++) {
        yy = yy * 10 + (y[j] - '0');
      }
      vb[a].spacing = yy;
    }
  }
  set<pair<string, pair<long long, long long> > > s;
  for (int i = 0; i < vw.size(); i++) {
    com = vw[i].name;
    s.insert(make_pair(com, make_pair(vw[i].x, vw[i].y)));
  }
  for (int i = 0; i < vb.size(); i++) {
    xy = go(i);
    com = vb[i].name;
    s.insert(make_pair(com, make_pair(xy.first, xy.second)));
  }
  for (set<pair<string, pair<long long, long long> > >::iterator it = s.begin();
       it != s.end(); ++it) {
    cout << (*it).first << ' ' << (*it).second.first << ' '
         << (*it).second.second << endl;
  }
  return 0;
}
