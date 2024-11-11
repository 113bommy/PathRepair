#include <bits/stdc++.h>
using namespace std;
const int max_int = (1LL << 31) - 1;
const int max_n = 3e3 + 100;
int d[max_n][2];
int a[max_n][3];
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 3; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[j][i];
  d[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    d[i][0] = d[i - 1][0] + a[i][(i < n)];
    d[i][0] = max(d[i][0], d[i - 1][1] + a[i][1 + (i < n)]);
    d[i][1] = d[i - 1][0] + a[i][0];
    d[i][1] = max(d[i][1], d[i - 1][1] + a[i][1]);
  }
  cout << max(d[n][0], d[n][1]) << endl;
  return 0;
}
