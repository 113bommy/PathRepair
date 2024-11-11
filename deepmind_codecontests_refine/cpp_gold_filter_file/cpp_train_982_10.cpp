#include <bits/stdc++.h>
using namespace std;
int n, k, d, ans[1005][1005];
void setup() {
  cin >> n >> k >> d;
  long long check = 1;
  for (int i = 1; i <= d; i++) {
    check *= k;
    if (check > n) break;
  }
  if (check < n) {
    cout << -1;
    exit(0);
  }
}
void xuly() {
  for (int i = 1; i <= d; i++) ans[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= d; j++) ans[i][j] = ans[i - 1][j];
    for (int j = d; j >= 1; j--) {
      if (ans[i][j] < k) {
        ans[i][j]++;
        break;
      }
      ans[i][j] = 1;
    }
  }
  for (int i = 1; i <= d; i++) {
    for (int j = 1; j <= n; j++) cout << ans[j][i] << ' ';
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  setup();
  xuly();
  return 0;
}
