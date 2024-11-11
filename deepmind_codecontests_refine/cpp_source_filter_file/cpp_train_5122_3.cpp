#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 100;
void solve() {
  int n, m, res = 101;
  cin >> n >> m;
  for (int i = 1; i < 101; i++) {
    int ok = n - m * i;
    if (ok <= 0) continue;
    int check = __builtin_popcount(ok);
    if (i >= check and i <= n) res = min(res, i);
  }
  if (res == 101) res = -1;
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
