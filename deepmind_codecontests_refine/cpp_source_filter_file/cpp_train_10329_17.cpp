#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1000 * 100 + 20;
long long dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cout.tie(0);
  long long n, m, cnt = 0;
  cin >> n >> m;
  dp[0] = 1;
  for (int i = 1; i < N; i++) dp[i] = (dp[i - 1] * i) % m;
  for (int i = 1; i <= n; i++)
    cnt =
        (cnt + (dp[i] % m * dp[n - i] % m * (n - i + 1) % m * (n - i + 1))) % m;
  cout << (cnt + m) % m << endl;
  return 0;
}
