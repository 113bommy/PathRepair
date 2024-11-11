#include <bits/stdc++.h>
using namespace std;
void file() {
  freopen("haywire.in", "r", stdin);
  freopen("haywire.out", "w", stdout);
}
int n, c[200001], x, y, k, to, ans;
int num[200001];
vector<int> a[200001];
vector<int> b[200001];
bool used[200001];
void dfs1(int v, int cv, int nm) {
  if (c[v] != cv) return;
  used[v] = true;
  num[v] = nm;
  for (int j = 0; j < a[v].size(); ++j) {
    if (!used[a[v][j]]) {
      dfs1(a[v][j], cv, nm);
    }
  }
}
int dfs2(int v) {
  int res1 = 0;
  int res2 = 0;
  int k1 = 0;
  used[v] = true;
  for (int j = 0; j < b[v].size(); ++j) {
    if (!used[b[v][j]]) {
      k1 = dfs2(b[v][j]) + 1;
      if (k1 > res1) {
        res2 = res1;
        res1 = k1;
      } else if (k1 > res2) {
        res2 = k1;
      }
    }
  }
  ans = max(res1 + res2, ans);
  return max(res1, res2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      k++;
      dfs1(i, c[i], k);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i].size(); ++j) {
      to = a[i][j];
      if (num[i] != num[to]) {
        b[num[i]].push_back(num[to]);
        b[num[to]].push_back(num[i]);
      }
    }
  }
  for (int i = 1; i <= k; ++i) {
    used[i] = false;
  }
  dfs2(1);
  cout << (ans + 1) / 2;
}
