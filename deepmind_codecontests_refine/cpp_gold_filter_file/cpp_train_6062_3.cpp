#include <bits/stdc++.h>
using namespace std;
vector<int> d(2e5 + 1, 0);
vector<int> adj[200001];
vector<int> ad2[200001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = a[0];
    for (int i = 1; i < n; i++) {
      mx = min(m, mx + a[i]);
    }
    cout << mx << endl;
  }
  return 0;
}
