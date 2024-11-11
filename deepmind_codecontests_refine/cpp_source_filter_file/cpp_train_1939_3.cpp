#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> w(2 * n);
  for (int i = 0; i < 2 * n; i++) cin >> w[i];
  sort(w.begin(), w.end());
  int mx = -1, ans = 10000000, cur, p;
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      cur = 0;
      for (int k = 0; k < 2 * n;) {
        if (k == i || k == j) {
          k++;
          continue;
        }
        p = k + 1;
        while (p == i || p == k) p++;
        cur += w[p] - w[k];
        k = p + 1;
      }
      ans = min(ans, cur);
    }
  }
  cout << ans;
}
