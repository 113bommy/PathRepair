#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 250005;
vector<int> g[maxn];
int pa[maxn];
int v[maxn];
int dep[maxn];
vector<int> leaf;
int n, m, k;
void build(int now) {
  int x = 0, y = 0;
  for (auto &i : g[now]) {
    if (i == pa[now]) {
      continue;
    } else if (x == 0) {
      x = i;
    } else {
      y = i;
    }
  }
  vector<int> ans;
  if ((dep[now] - dep[x] + 1) % 3) {
    ans.push_back(now);
    while (ans.back() != x) {
      ans.push_back(pa[ans.back()]);
    }
  } else if ((dep[now] - dep[y] + 1) % 3) {
    ans.push_back(now);
    while (ans.back() != y) {
      ans.push_back(pa[ans.back()]);
    }
  } else {
    if (dep[x] < dep[y]) {
      swap(x, y);
    }
    ans.push_back(now);
    ans.push_back(x);
    while (ans.back() != y) {
      ans.push_back(pa[ans.back()]);
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
void dfs(int now) {
  v[now] = 1;
  int f = 0;
  if (dep[now] >= n / k) {
    cout << "PATH\n";
    vector<int> ans{now};
    while (ans.back() != 1) {
      ans.push_back(pa[ans.back()]);
    }
    cout << ans.size() << '\n';
    for (auto &i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
    exit(0);
  }
  for (auto &i : g[now]) {
    if (v[i]) {
      continue;
    }
    dep[i] = dep[now] + 1;
    pa[i] = now;
    dfs(i);
    f = 1;
  }
  if (!f) {
    leaf.push_back(now);
  }
}
void go() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dep[1] = 1;
  dfs(1);
  cout << "CYCLES\n";
  for (int i = 0; i < k; i++) {
    build(leaf[i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 0;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    go();
  }
}
