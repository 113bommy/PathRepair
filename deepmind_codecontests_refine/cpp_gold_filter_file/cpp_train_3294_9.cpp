#include <bits/stdc++.h>
using namespace std;
const int INF = 300;
int main() {
  int t, n, k, num, max, a[205], x[205];
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(x + 1, INF, sizeof(x));
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
      x[a[i]] = 1;
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        if (x[a[i] - j] > x[a[i] - j + 1] + 1 && a[i] - j > 0)
          x[a[i] - j] = x[a[i] - j + 1] + 1;
        if (x[a[i] + j] > x[a[i] + j - 1] + 1 && a[i] + j <= n)
          x[a[i] + j] = x[a[i] + j - 1] + 1;
      }
      max = 1;
      for (int i = 1; i <= n; i++) {
        if (max < x[i]) max = x[i];
      }
    }
    cout << max << endl;
  }
}
