#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;
ll INF = 1LL << 60;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> tree[n + 1];
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  bool ans = true;
  for (int i = 1; i <= n; i++) {
    if (tree[i].size() == 2) {
      ans = false;
      break;
    }
  }
  cout << (ans ? "YES" : "NO") << "\n";
}
