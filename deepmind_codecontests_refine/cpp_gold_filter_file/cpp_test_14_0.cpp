#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int i, j, n, k, c, p;
    map<int, vector<int>> umap;
    cin >> n;
    c = -1;
    int a[n], b[n], f;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      umap[a[i]].push_back(i);
      b[i] = i;
    }
    vector<vector<int>> v;
    for (auto it = umap.begin(); it != umap.end(); it++) {
      k = it->second.size();
      for (j = 0; j < k; j++) {
        c++;
        if (b[it->second[j]] == c || c + 1 == n) continue;
        v.push_back({c + 1, n, b[it->second[j]] - c});
        f = b[it->second[j]] - c;
        for (p = 0; p < n; p++) {
          if (b[p] >= c) {
            if (b[p] - f >= c)
              b[p] -= f;
            else
              b[p] = b[p] - f + n - c;
          }
        }
      }
    }
    n = v.size();
    cout << n << "\n";
    for (i = 0; i < n; i++) {
      for (j = 0; j < 3; j++) cout << v[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
