#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 55, mod = 1e9 + 7;
struct record {
  string name;
  long long x;
  set<string> s;
};
map<string, struct record> mm, ans;
map<string, struct record>::iterator it;
set<string>::iterator itt;
int main() {
  long long i, j, k, x, y, z, n, a, b, c, f, l;
  cin >> n;
  string dd, gg, s;
  for (i = 1; i <= n; i++) {
    cin >> s;
    mm[s].name = s;
    cin >> x;
    for (j = 1; j <= x; j++) {
      cin >> gg;
      mm[s].s.insert(gg);
    }
  }
  struct record first;
  vector<string> v;
  for (it = mm.begin(); it != mm.end(); it++) {
    v.clear();
    s = it->first;
    first = it->second;
    for (itt = first.s.begin(); itt != first.s.end(); itt++) {
      v.push_back(*itt);
    }
    for (i = 0; i < v.size(); i++) {
      f = 0;
      for (j = 0; j < v.size(); j++) {
        if (j == i) continue;
        if (v[i].size() > v[j].size()) continue;
        k = v[i].size();
        k--;
        for (l = v[j].size() - 1; l >= 0; l--) {
          if (v[j][l] == v[i][k]) {
            k--;
          } else {
            break;
          }
          if (k < 0) {
            break;
          }
        }
        if (k < 0) {
          f = 1;
          break;
        }
      }
      if (f) first.s.erase(first.s.find(v[i]));
    }
    ans[s] = first;
  }
  z = ans.size();
  cout << z << "\n";
  for (it = ans.begin(); it != ans.end(); it++) {
    first = it->second;
    cout << first.name << " ";
    y = first.s.size();
    cout << y << " ";
    for (itt = first.s.begin(); itt != first.s.end(); itt++)
      cout << (*itt) << " ";
    cout << "\n";
  }
}
