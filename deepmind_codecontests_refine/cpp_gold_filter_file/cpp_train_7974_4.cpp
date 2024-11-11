#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
const int mod = 1e9 + 7;
long long pwr(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a);
    a = (a * a);
    b >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a[n][m];
  int row[n], col[m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j]) cnt++;
    }
    row[i] = cnt;
  }
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i]) cnt++;
    }
    col[i] = cnt;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int one = row[i], zero = m - row[i];
    ans += pwr(2, one) - 1 + pwr(2, zero) - 1;
  }
  for (int i = 0; i < m; i++) {
    int one = col[i], zero = n - col[i];
    if (one > 1) {
      ans += pwr(2, one) - 1 - one;
    }
    if (zero > 1) {
      ans += pwr(2, zero) - 1 - zero;
    }
  }
  cout << ans << endl;
  return 0;
}
