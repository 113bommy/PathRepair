#include <bits/stdc++.h>
using namespace std;
vector<int> lefts[200000], rights[200000];
vector<pair<pair<int, int>, bool>> lws;
int maxleft[200000];
int maxright[200000];
int minright[200000];
vector<int> ans;
bool fail = false;
int n;
int dfs(int v, int needed) {
  int cur = v;
  if (maxleft[v] > v) cur = dfs(cur + 1, maxleft[v]);
  ans.push_back(v);
  if (cur >= minright[v]) {
    fail = true;
    return n;
  }
  if (needed <= cur && maxright[v] <= cur) return cur;
  return dfs(cur + 1, max(needed, maxright[v]));
}
int main() {
  ios_base::sync_with_stdio(false);
  int c;
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    maxleft[i] = maxright[i] = i;
    minright[i] = 1e9;
  }
  for (int i = 0; i < c; i++) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    lws.push_back(make_pair(make_pair(a, b), s != "LEFT"));
    if (s == "LEFT") {
      lefts[a].push_back(b);
      if (b < a) fail = true;
      maxleft[a] = max(maxleft[a], b);
    }
    if (s == "RIGHT") {
      rights[a].push_back(b);
      if (b < a) fail = true;
      maxright[a] = max(maxright[a], b);
      minright[a] = min(minright[a], b);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (minright[i] <= maxleft[i]) fail = true;
  }
  dfs(1, n);
  if (fail)
    cout << "IMPOSSIBLE";
  else {
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
  }
}
