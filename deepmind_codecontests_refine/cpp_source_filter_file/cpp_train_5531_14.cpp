#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n, m, arr[maxn], nxt = 1;
vector<int> adj[maxn];
void no() {
  cout << "NO\n";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  if (n == 1) no();
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) arr[i] = i;
  for (int it = 0; it < 500; it++) {
    shuffle(arr + 1, arr + n + 1, rng);
    for (int i = 1; i <= n; i++) {
      int mx = 0;
      int mn = n + 1;
      for (int u : adj[i]) {
        if (arr[u] < arr[i])
          mx = max(mx, arr[u]);
        else
          mn = min(mn, arr[u]);
      }
      if (mx + 1 != mn - 1) {
        cout << "YES\n";
        for (int j = 1; j <= n; j++) cout << arr[j] << " ";
        cout << "\n";
        for (int j = mx + 1; j < mn; j++)
          if (j != arr[i]) {
            arr[i] = j;
            break;
          }
        for (int j = 1; j <= n; j++) cout << arr[j] << " ";
        cout << "\n";
        return 0;
      }
    }
  }
  no();
  return 0;
}
