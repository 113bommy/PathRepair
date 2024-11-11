#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
long long frq[MM], dp[MM];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    frq[x]++;
  }
  dp[1] = frq[1];
  for (long long i = 2; i <= MM; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + frq[i] * i);
  }
  cout << dp[n];
}
