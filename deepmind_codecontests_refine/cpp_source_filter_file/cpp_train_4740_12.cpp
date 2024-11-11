#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000009;
vector<bool> vis;
vector<string> pos;
void gen(string cur) {
  if (cur.size() >= 4) {
    vis.push_back(false);
    pos.push_back(cur);
    return;
  }
  for (__typeof(10) i = (0) - ((0) > (10)); i != (10) - ((0) > (10));
       i += 1 - 2 * ((0) > (10))) {
    if (cur.find(i + '0') == cur.npos) gen(cur + (char)(i + '0'));
  }
}
bool cmp(string& str, string& s, int bull, int cow) {
  vector<bool> f(10, false);
  int res = 0;
  for (__typeof(str.size()) i = (0) - ((0) > (str.size()));
       i != (str.size()) - ((0) > (str.size()));
       i += 1 - 2 * ((0) > (str.size()))) {
    f[str[i] - '0'] = true;
    if (str[i] == s[i]) res++;
  }
  if (res != bull) return false;
  res = -bull;
  for (__typeof(s.size()) i = (0) - ((0) > (s.size()));
       i != (s.size()) - ((0) > (s.size())); i += 1 - 2 * ((0) > (s.size())))
    if (f[s[i] - '0']) res++;
  return res == cow;
}
int main() {
  gen("");
  int n, a, b;
  int k = pos.size();
  string str;
  cin >> n;
  while (n-- && k > 1) {
    cin >> str >> a >> b;
    for (__typeof(pos.size()) i = (0) - ((0) > (pos.size()));
         i != (pos.size()) - ((0) > (pos.size()));
         i += 1 - 2 * ((0) > (pos.size()))) {
      if (vis[i]) continue;
      bool can = cmp(str, pos[i], a, b);
      if (can) continue;
      k--;
      vis[i] = true;
    }
  }
  if (k == 0)
    cout << "Incorrect data";
  else if (k > 1)
    cout << "Need more data";
  else {
    for (__typeof(pos.size()) i = (0) - ((0) > (pos.size()));
         i != (pos.size()) - ((0) > (pos.size()));
         i += 1 - 2 * ((0) > (pos.size()))) {
      if (!vis[i]) {
        cout << pos[i];
        return 0;
      }
    }
  }
  return 0;
}
