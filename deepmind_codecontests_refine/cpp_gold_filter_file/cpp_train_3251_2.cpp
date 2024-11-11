#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int> >;
const long long infl = 1LL << 60;
int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  int n, k, m;
  cin >> n >> m;
  vi adj[n + 1];
  vi adj1[n + 1];
  int arr[n + 1];
  int a[n + 1];
  int m1 = m;
  memset(arr, 0, sizeof(arr));
  while (m1--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj1[v].push_back(u);
  }
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> a[i];
  bool visited[n + 1];
  for (int i = 1; i <= n; i++) visited[i] = false;
  queue<int> q;
  q.push(a[k]);
  arr[a[k]] = 1;
  while (!q.empty()) {
    int x = q.front();
    visited[x] = true;
    q.pop();
    for (int y : adj1[x]) {
      if (!arr[y]) {
        q.push(y);
        arr[y] = arr[x] + 1;
      }
    }
  }
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 1; i < k; i++) {
    if (arr[a[i + 1]] != arr[a[i]] - 1) {
      ans1++;
      ans2++;
    } else {
      int f = 0;
      for (int j : adj[a[i]]) {
        if (arr[j] == arr[a[i]] - 1 && j != a[i + 1]) {
          f = 1;
          break;
        }
      }
      ans2 += f;
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
