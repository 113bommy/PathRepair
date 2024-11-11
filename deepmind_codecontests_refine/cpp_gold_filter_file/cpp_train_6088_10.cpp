#include <bits/stdc++.h>
using namespace std;
map<string, vector<string> > g;
map<string, unsigned char> vis;
int dfs(string s) {
  vis[s] = true;
  int maxs = 0;
  if (g[s].size() == 0) return 1;
  for (auto it : g[s]) {
    if (!vis[it]) {
      maxs = max(dfs(it), maxs);
    }
  }
  return maxs + 1;
}
string tolower(string s) {
  for (char &i : s) {
    if (i < 97) i += ' ';
  }
  return s;
}
void print() {
  for (map<string, vector<string> >::iterator it = g.begin(); it != g.end();
       it++) {
    cout << it->first << " length (" << it->second.size() << "): ";
    for (string s : it->second) {
      cout << s << " ";
    }
    cout << endl;
  }
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    string a, b, c, tempa, tempc;
    cin >> a >> b >> c;
    tempa = tolower(a);
    tempc = tolower(c);
    g[tempc].push_back(tempa);
  }
  cout << dfs("polycarp");
}
