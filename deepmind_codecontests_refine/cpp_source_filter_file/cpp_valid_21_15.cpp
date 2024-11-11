#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
int amount;
int portal_pos[200005], tele[200005], state[200005];
int cost[200005], sums[200005];
void solve() {
  for (int i = 1; i <= amount; i++) {
    int fir = lower_bound(portal_pos + 1, portal_pos + amount + 1, tele[i]) -
              portal_pos;
    cost[i] = ((long long)portal_pos[i] - tele[i] + sums[i - 1] -
               sums[fir - 1] + 2 * mod) %
              mod;
    sums[i] = (sums[i - 1] + cost[i]) % mod;
  }
  int res = portal_pos[amount] + 1;
  for (int i = 1; i <= amount; i++)
    if (state[i]) res = (res + cost[i]) % mod;
  printf("%d", res);
}
int main() {
  scanf("%d", &amount);
  for (int i = 1; i <= amount; i++)
    scanf("%d %d %d", &portal_pos[i], &tele[i], &state[i]);
  solve();
}
