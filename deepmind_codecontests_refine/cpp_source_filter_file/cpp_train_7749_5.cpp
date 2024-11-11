#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[401];
int n, k, val[401][401], parent[401];
vector<int> a[401][401];
void build() {
  for (int j = 0; j < 401; j++)
    for (int i = 0; i < 401; i++) val[j][i] = 1000001;
  cin >> n >> k;
  for (int j = 0; j < n - 1; j++) {
    int l, r;
    cin >> l >> r;
    adj[l].push_back(make_pair(r, j));
    adj[r].push_back(make_pair(l, j));
  }
  return;
}
void dfs(int src, int par, int where) {
  parent[src] = where + 1;
  val[src][0] = 1;
  a[src][0].push_back(where);
  if (par != 0 && adj[src].size() == 1) {
    val[src][1] = 0;
    return;
  }
  int t = 0, arr[401];
  vector<int> val_[401];
  for (int j = 0; j < adj[src].size(); j++) {
    pair<int, int> p = adj[src][j];
    if (p.first == par) continue;
    int curr = p.first, num = p.second;
    dfs(curr, src, num);
    t++;
    if (t == 1) {
      for (int i = 0; i < 401; i++) {
        val[src][i] = val[curr][i];
        arr[i] = val[curr][i];
        a[src][i] = a[curr][i];
        val_[i] = a[curr][i];
      }
      continue;
    }
    for (int i = 0; i < 401; i++) {
      int x = val[src][i] + val[curr][0];
      vector<int> tem = a[src][i];
      for (int m = 0; m < a[curr][0].size(); m++) tem.push_back(a[curr][0][m]);
      for (int m = 0; m <= i; m++)
        if (arr[m] + val[curr][i - m] < x) {
          x = arr[m] + val[curr][i - m];
          tem = val_[m];
          for (int l = 0; l < a[curr][i - m].size(); l++)
            tem.push_back(a[curr][i - m][l]);
        }
      val[src][i] = x;
      a[src][i] = tem;
    }
    for (int i = 0; i < 401; i++) {
      arr[i] = val[src][i];
      val_[i] = a[src][i];
    }
  }
  for (int j = 400; j > 0; j--) {
    val[src][j] = val[src][j - 1];
    a[src][j] = a[src][j - 1];
  }
  val[src][0] = 1;
  a[src][0].clear();
  a[src][0].push_back(where);
  return;
}
void print() {
  for (int j = 1; j <= n; j++) {
    cout << j << " -- > ";
    for (int i = 0; i <= 10; i++) cout << val[j][i] << " ";
    cout << endl;
  }
  return;
}
int main() {
  build();
  dfs(1, 0, -1);
  if (n == k) {
    cout << "0\n";
    return 0;
  }
  int ans_ = 1000001, ind = -1;
  vector<int> ans;
  for (int j = 1; j <= n; j++) {
    if (val[j][k] < ans_) {
      ind = j;
      ans_ = val[j][k];
      ans = a[j][k];
    }
  }
  if (parent[ind] != 0) ans.push_back(parent[ind]);
  cout << ans.size() << endl;
  for (int j = 0; j < ans.size(); j++) cout << (ans[j] + 1) << " ";
  cout << endl;
  return 0;
}
