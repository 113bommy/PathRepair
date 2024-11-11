#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<string, int> m;
  map<string, vector<pair<int, int> > > mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int h;
    cin >> h;
    m[s] += h;
    mp[s].push_back(make_pair(h, i));
  }
  int max1 = 0;
  map<string, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (max1 < it->second) max1 = it->second;
  }
  vector<string> p;
  for (it = m.begin(); it != m.end(); it++) {
    if (max1 == it->second) p.push_back(it->first);
  }
  vector<pair<int, string> > vt;
  for (int i = 0; i < p.size(); i++) {
    int x = 0;
    int y = 0;
    for (int j = 0; j < mp[p[i]].size(); j++) {
      x += mp[p[i]][j].first;
      if (x == max1) {
        y = mp[p[i]][j].second;
        break;
      }
    }
    vt.push_back(make_pair(y, p[i]));
  }
  sort(vt.begin(), vt.end());
  cout << vt[0].second << endl;
  return 0;
}
