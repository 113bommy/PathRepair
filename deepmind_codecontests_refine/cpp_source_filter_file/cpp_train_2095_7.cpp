#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long T = 1;
  while (T--) {
    long long n, m, k, x = 0, y = 0, c = 0;
    cin >> n >> m;
    long long a[n + m][2];
    long long b[m], arr[m];
    memset(b, 0, sizeof(b));
    memset(arr, 0, sizeof(arr));
    for (long long i = 0; i < n + m; ++i) {
      cin >> a[i][0];
    }
    long long j = 0;
    for (long long i = 0; i < n + m; ++i) {
      cin >> a[i][1];
      if (a[i][1] == 1) arr[j++] = i;
    }
    if (m == 1) cout << n << "\n";
    if (m > 1) {
      for (long long i = 0; i < n + m; ++i) {
        if (a[i][1] == 1) {
          b[0] = i;
          break;
        }
      }
      long long p = 0;
      while (p < m - 1) {
        for (long long i = arr[p] + 1; i < arr[p + 1]; ++i) {
          if (abs(a[arr[p]][0] - a[i][0]) < abs(a[i][0] - a[arr[p + 1]][0]))
            b[p + 1]++;
          else
            b[p]++;
        }
        p++;
      }
      for (long long i = m + n - 1; i >= 0; --i) {
        if (a[i][1] == 1) {
          b[p] += n + m - i - 1;
          break;
        }
      }
      for (long long i = 0; i < m; ++i) {
        cout << b[i] << " ";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
