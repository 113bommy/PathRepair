#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), partsum(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (i > 2) {
        if (a[i - 1] > a[i] && a[i - 2] < a[i - 1])
          partsum[i - 1] = partsum[i - 2] + 1;
        else
          partsum[i - 1] = partsum[i - 2];
      }
    }
    int peaks = 0, l = 0;
    for (int i = 1; i < n - k + 2; ++i) {
      if (partsum[i + k - 2] - partsum[i - 1] > peaks) {
        peaks = partsum[i + k - 2] - partsum[i - 1];
        l = i;
      }
    }
    cout << peaks + 1 << ' ' << l << '\n';
  }
  return 0;
}
