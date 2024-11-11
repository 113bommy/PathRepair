#include <bits/stdc++.h>
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
using namespace std;
void file() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  file();
  string s1, s2;
  cin >> s1 >> s2;
  map<char, int> mp1, mp2;
  for (auto e : s1) mp1[e]++;
  for (auto e : s2) mp2[e]++;
  set<pair<double, pair<int, char> > > st;
  for (auto e : mp2)
    st.insert({mp1[e.first] * 1. / e.second, {mp1[e.second], e.first}});
  vector<char> ans;
  int t = mp1['?'];
  while (t--) {
    pair<double, pair<int, char> > p = *st.begin();
    st.erase(st.begin());
    p.second.first++;
    p.first = p.second.first * 1. / mp2[p.second.second];
    st.insert(p);
    ans.push_back(p.second.second);
  }
  int idx = 0;
  for (auto e : s1)
    if (e == '?')
      cout << ans[idx++];
    else
      cout << e;
}
