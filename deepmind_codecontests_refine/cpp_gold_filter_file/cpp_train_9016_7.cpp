#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
int main() {
  int n, k, m, a[100005];
  cin >> n >> k >> m;
  std::vector<int> v[100005];
  for (__typeof(n) i = 0; i < n; ++i) {
    cin >> a[i];
    v[a[i] % m].push_back(a[i]);
  }
  for (__typeof(n) i = 0; i < n; ++i) {
    if (!vis[a[i] % m] && v[a[i] % m].size() >= k) {
      vis[a[i] % m] = 1;
      int j = 0;
      cout << "Yes\n";
      for (auto x : v[a[i] % m]) {
        if (j == k) break;
        cout << x << " ";
        j++;
      }
      return 0;
    }
  }
  cout << "No\n";
}
