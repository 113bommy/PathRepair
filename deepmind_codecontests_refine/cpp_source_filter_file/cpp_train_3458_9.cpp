#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vec(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vec[i][j];
      vec[i][j]--;
    }
  }
  long long ans = 0;
  for (int j = 0; j < n; j++) {
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
      if (vec[i][j] % m == j) {
        int pos = vec[i][j] / m;
        if (pos < n) {
          cnt[(i - pos + n) % n]++;
        }
      }
    }
    int curr = n - cnt[0];
    for (int i = 1; i < n; i++) {
      curr = min(n - cnt[i] + i, curr);
    }
    ans += curr;
  }
  cout << ans;
  return 0;
}
