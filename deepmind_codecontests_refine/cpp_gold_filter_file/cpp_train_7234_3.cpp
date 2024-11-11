#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 19;
int h[MAXN], dp[MAXN], tmp, n;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> h[i];
  for (int i = 1; i <= n; i++) tmp = min(tmp, h[i] - i), dp[i] = tmp + i;
  tmp = n + 1;
  for (int i = n; i; i--) tmp = min(tmp, h[i] + i), dp[i] = min(dp[i], tmp - i);
  cout << *max_element(dp + 1, dp + n + 1);
  return (0);
}
