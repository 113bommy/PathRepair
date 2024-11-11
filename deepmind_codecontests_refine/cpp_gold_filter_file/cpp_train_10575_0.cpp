#include <bits/stdc++.h>
using namespace std;
int n, it;
int sz[300030];
pair<int, int> ans;
vector<int> node;
struct Node {
  int can[26];
  int mx;
} bor[300030], t[300030];
void dfs(int v) {
  sz[v]++;
  for (int i = 0; i < 26; i++) {
    int to = bor[v].can[i];
    if (to == 0) continue;
    dfs(to);
    sz[v] += sz[to];
  }
}
void update(int v, int w) {
  for (int i = 0; i < 26; i++) {
    if (!bor[w].can[i]) continue;
    if (!t[v].can[i]) t[v].can[i] = ++it;
    update(t[v].can[i], bor[w].can[i]);
  }
}
void update_mx(int v, int w) {
  for (int i = 0; i < 26; i++) {
    if (!bor[w].can[i]) continue;
    if (!t[v].can[i])
      it += sz[bor[w].can[i]];
    else
      update_mx(t[v].can[i], bor[w].can[i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    bor[x].can[c - 'a'] = y;
  }
  dfs(1);
  node.push_back(1);
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 0; j < 26; j++)
      if (sz[bor[i].can[j]] > sz[bor[i].can[mx]]) mx = j;
    bor[i].mx = mx;
  }
  int l = 0, r = 1;
  for (int p = 0; p < n && node.size(); p++) {
    int NewSize = 0;
    for (int i = l; i < r; i++) {
      int v = node[i];
      for (int j = 0; j < 26; j++) {
        if (!bor[v].can[j]) continue;
        node.push_back(bor[v].can[j]);
        if (j != bor[v].mx) update(0, bor[v].can[j]);
      }
      int it_mn = it;
      update_mx(0, bor[v].can[bor[v].mx]);
      NewSize += sz[v] - it - 1;
      for (int q = 0; q < it_mn + 5; q++) {
        for (int qq = 0; qq < 26; qq++) t[q].can[qq] = 0;
        t[q].mx = 0;
      }
      it = 0;
    }
    l = r;
    r = node.size();
    if (NewSize > ans.first) {
      ans.first = NewSize;
      ans.second = p + 1;
    }
  }
  cout << sz[1] - ans.first << endl << ans.second << endl;
}
