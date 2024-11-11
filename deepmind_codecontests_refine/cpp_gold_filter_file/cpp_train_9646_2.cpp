#include <bits/stdc++.h>
using namespace std;
set<int> Set;
stringstream ss;
string s, sn;
int n, i, k, l, ans;
bool sqr(int a) {
  int l = 0, r = 44721, d;
  while (l <= r) {
    d = (l + r) / 2;
    if (d * d < a)
      l = d + 1;
    else if (d * d > a)
      r = d - 1;
    else
      return 1;
  }
  return 0;
}
void dfs(int deep) {
  if (deep == s.size()) {
    if (s.size() == Set.size()) return;
    sn = "";
    for (i = 0; i < s.size(); i++)
      if (Set.find(i) == Set.end()) sn += s[i];
    if (sn[0] == '0') return;
    ss.clear();
    ss << sn;
    ss >> l;
    if (sqr(l)) ans = min(ans, int(Set.size()));
    return;
  }
  dfs(deep + 1);
  Set.insert(deep);
  dfs(deep + 1);
  Set.erase(deep);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  ans = 1000000000;
  dfs(0);
  if (ans != 1000000000)
    cout << ans;
  else
    cout << "-1";
  cout << '\n';
  return 0;
}
