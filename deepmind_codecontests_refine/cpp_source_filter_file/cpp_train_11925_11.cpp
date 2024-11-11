#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int n, m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int len_n = 0, len_m = 0;
  for (int i = 1; i <= n; i *= 7) len_n++;
  for (int i = 1; i <= m; i *= 7) len_m++;
  if (len_n + len_m > 7) return 0 * puts("0");
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector<int> used(7, 0);
      for (int tmp = i, k = 0; k < len_n; tmp /= 7, k++) {
        used[tmp % 7]++;
      }
      for (int tmp = j, k = 0; k < len_m; tmp /= 7, k++) {
        used[tmp % 7]++;
      }
      if (*max_element(used.begin(), used.end()) <= 1) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
