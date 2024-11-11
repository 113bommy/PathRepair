#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long second, x;
  cin >> second >> x;
  if (x > second) {
    cout << 0;
    return;
  }
  long long cnt = __builtin_popcountll(x), cur = x, flag = 0;
  for (long long i = 40; i >= 0; i--) {
    if (!(x & (1LL << i)) && cur + (1LL << (i + 1)) <= second)
      cur += 1LL << (i + 1), flag = 1;
    if (cur == second) break;
  }
  if (cur == second) {
    long long ans = 1;
    for (int i = 1; i <= cnt; i++) ans *= 2;
    if (!flag) ans -= 2;
    cout << ans;
  } else
    cout << 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
