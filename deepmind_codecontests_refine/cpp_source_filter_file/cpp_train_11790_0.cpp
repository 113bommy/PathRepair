#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
void solve() {
  int n, k, a;
  cin >> n;
  vector<int> adj[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> k;
    while (k--) {
      cin >> a;
      adj[i].push_back(a - 1);
    }
  }
  vector<int> done(n, 0);
  map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    for (auto child : adj[i]) {
      if (mpp[child] == 0) {
        mpp[child]++;
        done[child]++;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (done[i] == 0) {
      for (int k = 0; k < n; k++) {
        if (mpp[k] == 0 &&
            find(adj[i].begin(), adj[i].end(), k) == adj[i].end()) {
          cout << "IMPROVE"
               << "\n";
          cout << i + 1 << " " << k + 1 << "\n";
          return;
        }
      }
    }
  }
  cout << "OPTIMAL"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
