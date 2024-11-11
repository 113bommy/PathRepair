#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int n;
int a[N];
int ans[N];
vector<int> s[N];
vector<pair<int, int> > con[N];
bool mycmp(int x, int y) { return x > y; }
int day;
int temp[N];
bool dfs(int t, int fr, int cap) {
  bool ok = false;
  if (t != 0) {
    cap = min(cap, (int)(s[t]).size());
    sort((s[t]).begin(), (s[t]).end(), mycmp);
    for (int i = 0; i < (int)cap; ++i) {
      s[fr].push_back(s[t][i]);
      if (fr == 0) {
        ans[s[t][i]] = day + 1;
      }
      ok = true;
    }
    int q = 0;
    for (int i = cap; i < (int)(s[t]).size(); i++) temp[q++] = s[t][i];
    s[t].resize(q);
    for (int i = 0; i < (int)q; ++i) s[t][i] = temp[i];
  }
  for (int i = 0; i < (int)(int)(con[t]).size(); ++i)
    if (con[t][i].first != fr) {
      ok |= dfs(con[t][i].first, t, con[t][i].second);
    }
  return ok;
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)n; ++i) scanf("%d", &a[i]), s[i].push_back(i);
  for (int i = 0; i < (int)n - 1; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--, v--;
    con[u].push_back(make_pair(v, c));
    con[v].push_back(make_pair(u, c));
  }
  while (dfs(0, -1, 0)) day++;
  for (int i = 0; i < (int)n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
