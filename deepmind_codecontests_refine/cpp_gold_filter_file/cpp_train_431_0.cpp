#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int in_matching[3 * n];
    vector<int> matching;
    for (int i = 0; i < 3 * n; i++) in_matching[i] = 0;
    for (int i = 0; i < m; i++) {
      int v, u;
      cin >> v >> u;
      v--;
      u--;
      if (!in_matching[u] && !in_matching[v]) {
        in_matching[u] = in_matching[v] = 1;
        matching.push_back(i + 1);
      }
    }
    if (matching.size() < n) {
      cout << "IndSet\n";
      int cnt = 0;
      for (int i = 0; i < 3 * n; i++)
        if (!in_matching[i]) {
          cout << i + 1 << " ";
          cnt++;
          if (cnt == n) break;
        }
      cout << "\n";
    } else {
      cout << "Matching\n";
      int cnt = 0;
      for (auto ele : matching) {
        cout << ele << " ";
        cnt++;
        if (cnt == n) break;
      }
      cout << "\n";
    }
  }
  return 0;
}
