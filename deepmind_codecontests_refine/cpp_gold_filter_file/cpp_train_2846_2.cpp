#include <bits/stdc++.h>
using namespace std;
const int N = 2000228;
int a[N], b[N], dp[N], l[N], r[N];
int main() {
  ios::sync_with_stdio(false);
  int c, n, m;
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    r[i] = j;
    j = min(j + 1, m - 1);
  }
  j = m - 1;
  for (int i = n - 1; i >= 0; i--) {
    l[i] = j;
    j = max(j - 1, 0);
  }
  for (int i = 1; i <= m; i++) {
    dp[i] = (dp[i - 1] + b[i - 1]) % c;
  }
  for (int i = 0; i < n; i++) {
    a[i] = (a[i] + dp[r[i] + 1] + c - dp[l[i]]) % c;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
