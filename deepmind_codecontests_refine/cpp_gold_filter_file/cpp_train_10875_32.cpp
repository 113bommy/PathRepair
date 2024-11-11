#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b, ret = 2e18;
long long c[51][51];
void find_space() {
  for (long long i = 0; i < n - a + 1; i++) {
    for (long long j = 0; j < m - b + 1; j++) {
      long long cnt = 0;
      for (long long i2 = i; i2 < i + a; i2++) {
        for (long long j2 = j; j2 < j + b; j2++) {
          cnt += c[i2][j2];
        }
      }
      ret = min(ret, cnt);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) cin >> c[i][j];
  cin >> a >> b;
  find_space();
  swap(a, b);
  find_space();
  cout << ret << endl;
  return 0;
}
