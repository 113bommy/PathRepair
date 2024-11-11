#include <bits/stdc++.h>
using namespace std;
int *flowers(int n, int k) {
  int *dp = new int[100005];
  int *sum = new int[100005];
  dp[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    dp[i] = dp[i - 1];
    if (i >= k) dp[i] = ((dp[i - 1]) + (dp[i - k])) % 1000000007;
  }
  for (int i = 1; i <= 100000; i++) {
    sum[i] = ((dp[i]) + (sum[i - 1])) % 1000000007;
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  int *dp = flowers(n, k);
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << (dp[b] - dp[a - 1] + 1000000007) % 1000000007 << endl;
  }
  return 0;
}
