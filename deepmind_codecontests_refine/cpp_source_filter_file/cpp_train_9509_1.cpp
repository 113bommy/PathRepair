#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10, MOD = 1000 * 1000 * 1000 + 7;
char a[MAXN], b[MAXN], temp[MAXN];
int dp[1000 * 100 + 10][2], k, n;
vector<int> start;
bool check() {
  for (int i = 0; i < n; i++)
    if (temp[i] != b[i]) return 0;
  return 1;
}
int main() {
  cin >> a;
  cin >> b;
  cin >> k;
  n = strlen(a);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) temp[j] = a[(i + j) % n];
    if (i == 0) {
      if (check())
        dp[0][0] = 1;
      else
        dp[0][1] = 1;
    }
    if (check()) start.push_back(i);
  }
  int tmp = start.size();
  if (start.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    dp[i][0] = dp[i - 1][1] * tmp + dp[i - 1][0] * (tmp - 1);
    dp[i][1] = dp[i - 1][0] * (n - tmp) + dp[i - 1][1] * (n - tmp - 1);
    dp[i][0] %= MOD;
    dp[i][1] %= MOD;
  }
  cout << dp[k][0] << endl;
  return 0;
}
