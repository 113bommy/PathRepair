#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> deg(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }
  if (deg[x] == 1) {
    cout << "Ayush\n";
    return;
  }
  if (n & 1 && n > 1)
    cout << "Ashish";
  else
    cout << "Ayush";
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
