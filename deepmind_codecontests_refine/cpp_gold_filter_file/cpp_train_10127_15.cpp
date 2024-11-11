#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int dh[5] = {1, 0, 0, -1};
int dc[5] = {0, 1, -1, 0};
const int oo = 1111111111;
long long f[N][3], a[N], n, q;
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    f[i][0] = -oo;
    f[i][1] = -oo;
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      f[i][0] = a[i];
      continue;
    } else {
      f[i][0] = max(a[i], max(f[i - 1][1] + a[i], max(f[i][0], f[i - 1][0])));
      f[i][1] = max(f[i - 1][0] - a[i], max(f[i][1], f[i - 1][1]));
    }
  }
  cout << max(f[n][1], f[n][0]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
    cout << "\n";
  }
}
