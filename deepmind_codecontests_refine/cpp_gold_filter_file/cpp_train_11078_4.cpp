#include <bits/stdc++.h>
using namespace std;
const int INF = 1061109567;
const int MAXN = 510005;
int dp[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  int n, d;
  cin >> n >> d;
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  int items[n];
  for (int i = 0; i < n; i++) cin >> items[i];
  for (int j = 0; j < n; j++) {
    for (int i = MAXN - items[j]; i >= 0; i--)
      if (dp[i]) dp[i + items[j]] = 1;
  }
  int itCount = 0;
  int i = 0;
  while (i < 500000) {
    bool flag = false;
    for (int j = i + d; j >= i + 1; j--) {
      if (dp[j]) {
        itCount++;
        i = j;
        flag = true;
        break;
      }
    }
    if (!flag) break;
  }
  cout << i << " " << itCount << endl;
}
