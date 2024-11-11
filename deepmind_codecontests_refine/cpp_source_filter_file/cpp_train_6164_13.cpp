#include <bits/stdc++.h>
using namespace std;
struct Node {
  int u, v;
};
int vis[30];
int grp[30][30];
int fa[30];
int n;
vector<Node> v;
int find_fa(int x) { return x == fa[x] ? x : fa[x] = find_fa(fa[x]); }
int main() {
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    int sz = unique(s.begin(), s.end()) - s.begin();
    for (int j = 0; j < sz; j++)
      for (int k = j + 1; k < sz; k++)
        if (!grp[s[j] - 'a'][s[k] - 'a']) {
          grp[s[j] - 'a'][s[k] - 'a'] = grp[s[k] - 'a'][s[j] - 'a'] = 1;
          vis[s[j] - 'a'] = 1;
          vis[s[k] - 'a'] = 1;
          v.push_back(Node{s[j] - 'a', s[k] - 'a'});
        }
  }
  for (int i = 0; i < 26; i++) fa[i] = i;
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    int f1 = find_fa(v[i].u), f2 = find_fa(v[i].v);
    if (f1 != f2) {
      fa[f1] = f2;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++)
    if (vis[i] && fa[i] == i) {
      ans++;
    }
  cout << ans;
  return 0;
}
