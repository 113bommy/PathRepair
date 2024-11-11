#include <bits/stdc++.h>
using namespace std;
const int mxN = 200001;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(m + 1, 0);
  for (int i = 1; i <= m; ++i) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ans = INT_MAX;
  for (int i = 1; i <= m; ++i) {
    int j = i + n - 1;
    if (j <= m) {
      ans = min(ans, p[j] - p[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}
