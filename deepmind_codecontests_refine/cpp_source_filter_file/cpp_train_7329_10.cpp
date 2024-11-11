#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int MOD = 1000000007;
int bit[100009];
int mx[100009];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n - 1; ++i) cin >> bit[i];
  string m;
  cin >> m;
  int ans = 0;
  for (int i = 0; i <= n - 1; ++i)
    if (m[i] == '1') ans += bit[i];
  mx[0] = max(0, bit[0]);
  for (int i = 1; i <= n - 1; ++i) {
    mx[i] = max(0, bit[i]) + mx[i - 1];
  }
  int have = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (m[i] == '1') {
      ans = max(ans, (i == 0 ? 0 : mx[i - 1]));
      have += bit[i];
    }
  }
  cout << ans << endl;
  return 0;
}
