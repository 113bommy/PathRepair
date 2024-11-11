#include <bits/stdc++.h>
using namespace std;
int n;
int w[105];
int ans = 1e9;
int main() {
  cin >> n;
  for (int i = 0; i < 2 * n; i++) scanf("%d", w + i);
  sort(w, w + 2 * n);
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      vector<int> q;
      q.clear();
      int nans = 0;
      for (int k = 0; k < 2 * n; k++) {
        if (k != i && k != j) q.push_back(w[k]);
      }
      for (int k = 0; k < n - 1; k++) {
        nans += w[2 * k + 1] - w[2 * k];
      }
      ans = min(ans, nans);
    }
  }
  cout << ans << "\n";
  return 0;
}
