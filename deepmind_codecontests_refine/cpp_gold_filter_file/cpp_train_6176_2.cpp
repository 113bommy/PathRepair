#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
long long n, m;
int onmat(long long x, long long y) {
  return (x <= n && y <= m && x > 0 && y > 0);
}
void solve() {
  cin >> n >> m;
  long long xo, yo;
  cin >> xo >> yo;
  int k;
  cin >> k;
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    for (long long num = (long long)1e9; num; num /= (long long)2) {
      while (onmat(xo + x * num, yo + y * num)) {
        xo = xo + x * num;
        yo = yo + y * num;
        ans += num;
      }
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
