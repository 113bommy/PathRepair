#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n * k);
    for (int i = 0; i < n * k; i++) {
      cin >> v[i];
    }
    int max_cost = 0;
    int idx = (n + 1) / 2 - 1;
    for (int i = idx * k; i < n * k; i += (n - idx)) {
      max_cost += v[i];
    }
    cout << max_cost << '\n';
  }
  return 0;
}
