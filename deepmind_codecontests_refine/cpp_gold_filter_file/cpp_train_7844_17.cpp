#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, ans = 0;
  cin >> n;
  int *coins = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
    if (2 * i + 1 <= n) x = i;
  }
  for (; x > 0; x--) {
    int temp = 0;
    temp = max(0, coins[2 * x]);
    temp = max(temp, coins[2 * x - 1]);
    ans += temp;
    coins[2 * x] = max(0, coins[2 * x] - temp);
    coins[2 * x - 1] = max(0, coins[2 * x - 1] - temp);
    coins[x - 1] = max(0, coins[x - 1] - temp);
  }
  ans += coins[0];
  if (n < 3 || ((n % 2) == 0)) ans = -1;
  cout << ans;
}
