#include <bits/stdc++.h>
int main() {
  using namespace std;
  string s, ss, temp;
  cin >> s;
  vector<string> v;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      ss += s[j];
      v.push_back(ss);
    }
    ss.clear();
  }
  map<string, int> mp;
  for (int i = 0; i < v.size(); i++) {
    mp[v[i]]++;
  }
  int mx = 0;
  for (auto u : mp) {
    string ok = u.first;
    int x = ok.size();
    if (u.second >= 2) {
      if (x > mx) {
        mx = max(x, mx);
      }
    }
  }
  cout << mx << endl;
  return 0;
}
