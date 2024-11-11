#include <bits/stdc++.h>
using namespace std;
int dcmp(double x, double y) {
  return fabs(x - y) <= 1e-9 ? 0 : x < y ? -1 : 1;
}
const int MAX = 100007;
long long arr[MAX], add[MAX], sub[MAX], n;
vector<vector<int> > adj;
void dfs(int u, int p) {
  add[u] = sub[u] = 0;
  for (int i = 0; i < ((int)((adj[u]).size())); ++i) {
    int child = adj[u][i];
    if (child != p) {
      dfs(child, u);
      add[u] = max(add[u], add[child]);
      sub[u] = max(sub[u], sub[child]);
    }
  }
  arr[u] += add[u] - sub[u];
  if (arr[u] > 0) {
    sub[u] += arr[u];
  } else {
    add[u] -= arr[u];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  adj = vector<vector<int> >(n + 1);
  for (int i = 0; i < (int)(n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    swap(u, v);
    adj[u].push_back(v);
  }
  for (int i = 0; i < (int)(n); ++i) {
    cin >> arr[i];
  }
  dfs(1, -1);
  cout << add[1] + sub[1] << '\n';
}
