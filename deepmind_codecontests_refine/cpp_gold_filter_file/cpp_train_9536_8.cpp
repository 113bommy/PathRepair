#include <bits/stdc++.h>
using namespace std;
int n;
int p;
int q;
int r;
vector<pair<int, int> > v[500002];
set<pair<int, int> > s;
struct add2D {
  int H;
  int W;
  set<pair<int, int> > s;
  long long int ar;
  void resize(int h, int w) {
    H = h;
    W = w;
    ar = 0;
    s.insert(make_pair(0, 1));
    s.insert(make_pair(0, h + 1));
  }
  void add(int x, int y) {
    auto it = s.lower_bound(make_pair(-y, INT_MAX));
    if (it == s.end()) {
      return;
    }
    auto nex = it;
    nex++;
    if ((*it).second > x) {
      return;
    }
    long long int leff = (*it).second;
    while (nex != s.end()) {
      int lef = (*it).second;
      int rig = (*nex).second - 1;
      int val = -(*it).first;
      int add = y - val;
      int R = min(rig, x);
      if (lef > R) {
        s.insert(make_pair(-y, leff));
        return;
      }
      ar += (long long int)(add) * (R - lef + 1);
      if (R < rig) {
        s.erase(it);
        s.insert(make_pair(-y, leff));
        s.insert(make_pair(-val, R + 1));
        return;
      }
      s.erase(it);
      it = nex;
      nex++;
    }
    s.insert(make_pair(-y, leff));
  }
  long long int area() { return ar; }
};
add2D ad;
int main() {
  cin >> n >> p >> q >> r;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    v[p].push_back(make_pair(b, c));
    v[a].push_back(make_pair(b, r));
    v[a].push_back(make_pair(q, c));
  }
  ad.resize(q, r);
  s.insert(make_pair(0, 0));
  s.insert(make_pair(r, 0));
  long long int sum = 0;
  for (int i = p; i >= 1; i--) {
    for (int j = 0; j < v[i].size(); j++) {
      ad.add(v[i][j].first, v[i][j].second);
    }
    sum += (long long int)(q)*r - ad.area();
  }
  printf("%lld\n", sum);
  return 0;
}
