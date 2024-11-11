#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n;
int l[maxn];
int r[maxn];
int clr[maxn];
bool mark[maxn];
vector<int> cmp;
map<int, int> compress;
stack<pair<int, int>> adj[maxn];
void in();
void solve();
void dfs(int u);
void out();
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  in();
  solve();
  out();
}
void in() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    r[i]++;
    cmp.push_back(l[i]);
    cmp.push_back(r[i]);
  }
  sort(cmp.begin(), cmp.end());
  cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
  for (int i = 0; i < cmp.size(); i++) compress[cmp[i]] = i;
  for (int i = 0; i < n; i++) {
    l[i] = compress[l[i]];
    r[i] = compress[r[i]];
    adj[l[i]].push({i, r[i]});
    adj[r[i]].push({i, l[i]});
  }
}
void solve() {
  int last = -1;
  for (int i = 0; i < maxn; i++) {
    if (adj[i].size() % 2) {
      if (last == -1)
        last = i;
      else {
        adj[i].push({maxn - i, last});
        adj[last].push({maxn - i, i});
        last = -1;
      }
    }
  }
  for (int i = 0; i < maxn; i++)
    while (adj[i].size()) dfs(i);
}
void dfs(int u) {
  if (adj[u].size()) {
    auto x = adj[u].top();
    adj[u].pop();
    if (mark[x.first]) dfs(u);
    mark[x.first] = 1;
    clr[x.first] = x.second > u;
    dfs(x.second);
  }
}
void out() {
  for (int i = 0; i < n; i++) cout << clr[i] << ' ';
}
