#include <bits/stdc++.h>
using namespace std;
namespace p245CGamewithCoins {
int coins[111];
void solve(int test_num) {
  int len;
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) scanf("%d", &coins[i]);
  if (len % 2 == 0 || len < 3) {
    puts("-1");
    return;
  }
  int ans = 0;
  for (int i = len; i >= 1; i--) {
    while (coins[i] > 0) {
      coins[i]--;
      coins[i ^ 1]--;
      coins[i >> 1]--;
      ans++;
    }
  }
  printf("%d\n", ans);
}
void solve() { solve(1); }
}  // namespace p245CGamewithCoins
int main() {
  p245CGamewithCoins::solve();
  return 0;
}
