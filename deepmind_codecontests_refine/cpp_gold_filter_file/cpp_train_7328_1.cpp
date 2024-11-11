#include <bits/stdc++.h>
using namespace std;
bool a[10];
long long int i, j, k;
void prover(long long int n) {
  for (i = 0; i <= 9; i++) a[i] = false;
  while (n > 0) {
    a[n % 10] = true;
    n = n - (n % 10);
    n = n / 10;
  }
}
int main() {
  long long int n;
  cin >> n;
  if (n > 9) {
    long long int dp[n + 1];
    for (long long int i = 1; i <= 9; i++) dp[i] = 1;
    for (long long int i = 10; i <= n; i++) {
      dp[i] = 100000007;
      prover(i);
      for (long long int j = 1; j <= 9; j++) {
        if (a[j] == true) {
          if (dp[i] > dp[i - j]) dp[i] = dp[i - j];
        }
      }
      dp[i]++;
    }
    cout << dp[n];
  } else {
    if (n == 0)
      cout << 0;
    else
      cout << 1;
  }
  return 0;
}
