#include <bits/stdc++.h>
using namespace std;
long double dp[8010][1010];
long double k, x;
int q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> q;
  dp[1][1] = 1;
  for (int a = 2; a <= 8000; a++) {
    dp[a][1] = 1;
    for (int b = 2; b <= min(int(k), a); b++) {
      dp[a][b] = dp[a - 1][b] +
                 ((dp[a - 1][b - 1] - dp[a - 1][b]) * ((k - b + 1) / k));
    }
  }
  for (int a = 1; a <= q; a++) {
    cin >> x;
    for (int b = 1; b <= 8000; b++) {
      if (dp[b][int(k)] >= x / 2000) {
        cout << b << '\n';
        break;
      }
    }
  }
  return 0;
}
