#include <bits/stdc++.h>
using namespace std;
int b[100005];
void solve() {
  int T = 1;
  while (T--) {
    int n, m, k, x = 0, y = 0, c = 0;
    cin >> n >> m;
    int a[n + m][2];
    for (int i = 0; i < n + m; ++i) {
      cin >> a[i][0];
    }
    for (int i = 0; i < n + m; ++i) {
      cin >> a[i][1];
    }
    for (int i = 0; i < n + m; ++i) {
      if (a[i][1] == 1) {
        b[0] = i;
        break;
      }
    }
    int p = 0;
    for (int i = 0; i < n + m; ++i) {
      if (a[i][1] == 1) {
        p++;
        int j = i + 1;
        if (p < m) {
          while (a[j][1] != 1) {
            j++;
            if (j == n + m) break;
          }
          for (int k = i + 1; k < j; ++k) {
            if (abs(a[k][0] - a[i][0]) < abs(a[k][0] - a[j][0]))
              b[p]++;
            else
              b[p - 1]++;
          }
        }
      }
    }
    for (int i = m + n - 1; i >= 0; --i) {
      if (a[i][1] == 1) {
        b[p - 1] += n + m - i - 1;
        break;
      }
    }
    for (int i = 0; i < m; ++i) {
      cout << b[i] << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
