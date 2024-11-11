#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int C = 26;
void add(int &x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
}
int fix(int x) {
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
int pw(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % MOD;
    b >>= 1;
    a = 1ll * a * a % MOD;
  }
  return ret;
}
const int MAXN = 100 + 10;
int n, a[MAXN << 1], ans;
void solve() {
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int x = a[i];
    for (int j = i + 1; j < n; j++) {
      if (a[j] == x) {
        while (j > i + 1) {
          swap(a[j], a[j - 1]);
          ans += 1;
          --j;
        }
        assert(a[i] == a[i + 1]);
        break;
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int te = 1;
  for (int w = 1; w <= te; w++) {
    solve();
  }
  return 0;
}
