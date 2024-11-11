#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int dp[100000];
  long long int x = 19;
  dp[0] = 19;
  int k = 1;
  for (int i = 2; i <= 1000000; i++) {
    x += 9;
    long long int temp = x;
    int sum = 0;
    while (temp > 0) {
      sum += (temp % 10);
      temp /= 10;
    }
    if (sum == 10) {
      dp[k] = x;
      k++;
    }
  }
  cout << dp[n - 1] << "\n";
}
