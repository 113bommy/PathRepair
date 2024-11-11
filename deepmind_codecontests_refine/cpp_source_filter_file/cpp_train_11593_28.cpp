#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
template <class T>
inline T sqr(T a) {
  return a * a;
}
struct team {
  string name;
  int gin, gout, o;
  team() {
    gin = 0;
    gout = 0;
    o = 0;
    name = "";
  }
};
bool comp(const team &l, const team &r) {
  if (l.o == r.o && l.gin - l.gout == r.gin - r.gout && l.gin == r.gin)
    return l.name < r.name;
  if (l.o == r.o && l.gin - l.gout == r.gin - r.gout) return l.gin > r.gin;
  if (l.o == r.o) return l.gin - l.gout > r.gin - r.gout;
  return l.o > r.o;
}
bool comp1(const pair<int, int> &l, const pair<int, int> &r) {
  if (l.first - l.second == r.first - r.second) return l.second < r.first;
  return l.first - l.second < r.first - r.second;
}
int main() {
  map<string, int> name;
  name["BERLAND"] = 0;
  vector<team> t(4);
  t[0].name = "BERLAND";
  set<pair<int, int> > was;
  for (int i = 0; i < 5; ++i) {
    string t1, t2;
    cin >> t1 >> t2;
    int k1, k2;
    scanf("%d:%d", &k1, &k2);
    if (name.find(t1) == name.end()) {
      int k = (int)(name).size();
      name[t1] = k;
      t[k].name = t1;
    }
    if (name.find(t2) == name.end()) {
      int k = (int)(name).size();
      name[t2] = k;
      t[k].name = t2;
    }
    t[name[t1]].gin += k1;
    t[name[t2]].gin += k2;
    t[name[t1]].gout += k2;
    t[name[t2]].gout += k1;
    if (k1 == k2) {
      ++t[name[t2]].o;
      ++t[name[t1]].o;
    }
    if (k1 > k2) t[name[t1]].o += 3;
    if (k1 < k2) t[name[t2]].o += 3;
    was.insert(make_pair(name[t2], name[t1]));
    was.insert(make_pair(name[t1], name[t2]));
  }
  int m;
  for (int i = 1; i < 4; ++i) {
    if (was.find(make_pair(0, i)) != was.end()) continue;
    m = i;
    break;
  }
  vector<pair<int, int> > v;
  for (int x = 1; x < 500; ++x) {
    for (int y = x - 1; y >= 0; --y) v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end(), comp1);
  for (int j = 0; j < (int)(v).size(); ++j) {
    vector<team> ct(t);
    int x = v[j].first, y = v[j].second;
    ct[0].gin += x;
    ct[0].gout += y;
    ct[m].gin += y;
    ct[m].gout += x;
    ct[0].o += 3;
    sort((ct).begin(), (ct).end(), comp);
    for (int i = 0; i < 2; ++i) {
      if (ct[i].name == "BERLAND") {
        printf("%d:%d", x, y);
        return 0;
      }
    }
  }
  puts("IMPOSSIBLE");
  return 0;
}
