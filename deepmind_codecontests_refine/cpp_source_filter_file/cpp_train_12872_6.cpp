#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
int par[50];
int pFind(int r) {
  if (par[r] == r) {
    return r;
  } else
    return par[r] = pFind(par[r]);
}
int main() {
  int k = 0;
  for (char x = 'a'; x <= 'z'; x++) {
    mp[x] = ++k;
  }
  int n;
  string s1, s2;
  while (cin >> n) {
    cin >> s1 >> s2;
    for (int i = 1; i <= 45; i++) {
      par[i] = i;
    }
    vector<pair<char, char> > vec;
    for (int i = 0; i < n; i++) {
      int u = mp[s1[i]];
      int v = mp[s2[i]];
      int pu = pFind(u);
      int pv = pFind(v);
      if (pu == pv) {
        continue;
      } else {
        par[u] = v;
        vec.push_back(make_pair(s1[i], s2[i]));
      }
    }
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
      cout << vec[i].first << ' ' << vec[i].second << endl;
    }
  }
  return 0;
}
