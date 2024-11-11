#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
int const mod = 1e9 + 7;
inline void safe_add(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int safe_mul(int x, int y) { return x * 1LL * y % mod; }
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int lastOnes = 1;
  int lastVal = 0;
  int lastH = 1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int curH;
    cin >> curH;
    int curVal = 1;
    safe_add(curVal, safe_mul(lastVal, min(lastOnes - 1, curH - 1)));
    safe_add(curVal, min(lastH - lastOnes, max(0, curH - lastOnes)));
    int curOnes = min(curH, lastH);
    safe_add(ans, safe_mul(curVal, curOnes - 1));
    safe_add(ans, curH - curOnes);
    tie(lastH, lastOnes, lastVal) = make_tuple(curH, curOnes, curVal);
  }
  cout << ans << endl;
}
