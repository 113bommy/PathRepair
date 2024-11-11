#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<pair<int, int> > tree[200001];
int nr[200001];
int arr[200001];
bool o[200001];
vector<int> bfs;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    tree[x].push_back(make_pair(0, y));
    tree[y].push_back(make_pair(0, x));
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    nr[arr[i]] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < tree[i].size(); j++)
      tree[i][j].first = nr[tree[i][j].second];
    sort(tree[i].begin(), tree[i].end());
  }
  bfs.push_back(1);
  for (int i = 0; i < bfs.size(); i++) {
    o[bfs[i]] = 1;
    for (int j = 0; j < tree[bfs[i]].size(); j++)
      if (!o[tree[bfs[i]][j].second]) bfs.push_back(tree[bfs[i]][j].second);
  }
  for (int i = 0; i < n; i++) {
    if (bfs[i] != arr[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
