#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t, n, m, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<long long> matching;
    vector<long long> indset;
    vector<bool> removed(3 * n + 1, false);
    for (long long i = 1; i <= m; i++) {
      cin >> u >> v;
      if (!removed[u] && !removed[v]) {
        matching.push_back(i);
        removed[u] = true;
        removed[v] = true;
      }
    }
    if (matching.size() >= n) {
      cout << "Matching\n";
      cout << matching[0];
      for (long long i = 1; i < n; i++) cout << " " << matching[i];
      cout << "\n";
    } else {
      for (long long i = 1; i <= 3 * n; i++) {
        if (!removed[i]) {
          indset.push_back(i);
        }
      }
      cout << "IndSet\n";
      cout << indset[0];
      for (long long i = 1; i < n; i++) cout << " " << indset[i];
      cout << "\n";
    }
  }
}
