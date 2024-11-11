#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4;
int n, m, d, ans, a[MAX_N];
int main() {
  cin >> n >> m >> d;
  int mod = 0, x = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[x];
      if (i == 0 && j == 0) {
        mod = a[x] % d;
      }
      if (a[x] % d != mod) {
        cout << "-1\n";
        return 0;
      }
      ++x;
    }
  }
  sort(a, a + n * m);
  int median = a[(n * m) / 2];
  for (int i = 0; i < n * m; ++i) {
    ans += abs(a[i] - median) / d;
  }
  cout << ans << '\n';
}
