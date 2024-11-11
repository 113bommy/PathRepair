#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e6 + 10;
long long INF = 1e9 + 10;
long long MOD = 998244353;
int n;
pair<int, int> a[MAXN];
pair<int, int> b[MAXN];
int func(int x, int cnt) {
  int res = 0;
  for (int pos = 0; pos < cnt; pos++) res += (1 << pos) * (int)((x >> pos) & 1);
  return res;
}
vector<pair<int, int> > gr[MAXN];
bool was[MAXN];
vector<int> ans;
void dfs(int u, int e) {
  while (gr[u].size() > 0) {
    if (was[gr[u].back().second])
      gr[u].pop_back();
    else {
      was[gr[u].back().second] = 1;
      dfs(gr[u].back().first, gr[u].back().second);
    }
  }
  if (e == -1) return;
  if (b[e].first == u) {
    ans.push_back(e * 2 + 1);
    ans.push_back(e * 2 + 2);
  } else {
    ans.push_back(e * 2 + 2);
    ans.push_back(e * 2 + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (int ANS = 20; ANS >= 0; ANS--) {
    for (int i = 0; i < MAXN; i++) gr[i].clear();
    for (int i = 0; i < n; i++) {
      b[i].first = func(a[i].first, ANS);
      b[i].second = func(a[i].second, ANS);
      gr[b[i].first].push_back({b[i].second, i});
      gr[b[i].second].push_back({b[i].first, i});
    }
    bool bad = 0;
    for (int i = 0; i < MAXN; i++) {
      if ((gr[i].size() % 2) == 1) bad = 1;
    }
    if (bad) continue;
    fill(was, was + MAXN, 0);
    int start = 0;
    while (gr[start].size() == 0) start++;
    ans.clear();
    dfs(start, -1);
    if (ans.size() == 2 * n) {
      cout << ANS << '\n';
      for (auto it : ans) cout << it << ' ';
      return 0;
    }
  }
  return 0;
}
