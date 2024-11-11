#include <bits/stdc++.h>
using namespace std;
int n, m, c, a[1000005], k;
bool check() {
  for (int i = 1; i <= n; i++)
    if (a[i] == 0 || a[i] < a[i - 1]) return false;
  return true;
}
void solve() {
  cin >> n >> m >> c;
  for (int i = 1; i <= m; i++) {
    cin >> k;
    if (k == c) {
      for (int j = n; j >= 1; j--)
        if (a[j] != k) {
          cout << j << endl;
          fflush(stdout);
          a[j] = k;
          break;
        }
      if (check()) break;
    } else if (k == 1) {
      for (int j = 1; j <= n; j++)
        if (a[j] != k) {
          cout << j << endl;
          fflush(stdout);
          a[j] = k;
          break;
        }
      if (check()) break;
    } else {
      for (int j = n; j >= 1; j--)
        if (k > a[j] || a[j] == 0) {
          cout << j << endl;
          fflush(stdout);
          a[j] = k;
          break;
        }
      if (check()) break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
}
