#include <bits/stdc++.h>
using namespace std;
const int maxe = (1 << 20) + 3;
int a[(int)3e5 + 10];
int n;
long long dp[(int)3e5 + 10];
long long c[2][maxe];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0)
      dp[i] ^= a[i];
    else {
      dp[i] ^= (a[i] ^ dp[i - 1]);
    }
  }
  c[1][0] = 1;
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += c[i % 2][dp[i]];
    c[i % 2][dp[i]]++;
  }
  cout << res;
}
