#include <bits/stdc++.h>
using namespace std;
const long long N = 200;
long long n, m, a[N], b[N];
bool used[N];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) cin >> b[i];
  for (long long i = 0; i < m - 1; ++i) {
    if (b[i + 1] > b[i]) {
      if (!a[b[i] - 1]) a[b[i] - 1] = b[i + 1] - b[i];
      if (a[b[i] - 1] != b[i + 1] - b[i]) {
        cout << -1;
        return 0;
      }
    } else {
      if (!a[b[i] - 1]) a[b[i] - 1] = n - b[i] + b[i + 1];
      if (a[b[i] - 1] != n - b[i] + b[i + 1]) {
        cout << -1;
        return 0;
      }
    }
    used[a[i]] = 1;
  }
  for (long long i = 0; i < n; ++i) {
    if (!a[i]) {
      for (long long j = 1; j <= n; ++j) {
        if (!used[j]) {
          a[i] = j;
          used[j] = 1;
          break;
        }
      }
    }
  }
  fill(used + 1, used + N, 0);
  for (long long i = 0; i < n; ++i) {
    if (used[a[i]]) {
      cout << -1;
      return 0;
    }
    used[a[i]] = 1;
  }
  for (long long i = 0; i < n; ++i) cout << a[i] << ' ';
}
