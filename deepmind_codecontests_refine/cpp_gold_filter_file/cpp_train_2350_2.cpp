#include <bits/stdc++.h>
using namespace std;
struct pull {
  vector<vector<char>> g;
  int maximal;
  set<int> ind_max;
  pull(void) {
    g.resize(26, vector<char>(26, 0));
    maximal = 0;
  }
  bool push(char a, char b) {
    int ind1 = a - 'a', ind2 = b - 'a';
    if ((g[ind1][ind2] != true && g[ind2][ind1] != true) || (ind1 == ind2)) {
      g[ind1][ind2] = g[ind2][ind1] = true;
      if ((ind1 != ind2) && (ind_max.find(ind1) != ind_max.end() ||
                             ind_max.find(ind2) != ind_max.end()))
        return false;
      else {
        ind_max.insert(ind1);
        ind_max.insert(ind2);
        return true;
      }
    } else
      return false;
  }
};
int main() {
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << 0;
    return 0;
  }
  map<char, char> m;
  for (int i = 0; i < s.length(); i++) {
    char a = min(s[i], t[i]);
    char b = max(s[i], t[i]);
    if (a != b) {
      if (m.find(a) == m.end() && m.find(b) == m.end())
        m[a] = b, m[b] = a;
      else if ((m.find(a) != m.end() && m[a] != b) ||
               (m.find(b) != m.end() && m[b] != a)) {
        cout << -1;
        return 0;
      }
    } else {
      if (m.find(a) != m.end()) {
        if (m[a] != a) {
          cout << -1;
          return 0;
        }
      } else
        m[a] = a;
    }
  }
  int answer = 0;
  for (auto it = m.begin(); it != m.end(); ++it)
    if (it->first < it->second) answer++;
  cout << answer << '\n';
  for (auto it = m.begin(); it != m.end(); ++it)
    if (it->first < it->second) cout << it->first << " " << it->second << '\n';
  return 0;
}
