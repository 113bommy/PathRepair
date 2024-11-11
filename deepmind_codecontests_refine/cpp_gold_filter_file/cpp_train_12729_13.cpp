#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
int main() {
  string s, t, u;
  cin >> s >> t >> u;
  for (int i = 0; i < s.size(); ++i) mp[s[i]] -= 1;
  for (int i = 0; i < t.size(); ++i) mp[t[i]] -= 1;
  for (int i = 0; i < u.size(); ++i) mp[u[i]] += 1;
  for (map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
    pair<char, int> cur = *it;
    if (cur.second != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
