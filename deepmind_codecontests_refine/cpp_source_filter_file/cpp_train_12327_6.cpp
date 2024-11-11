#include <bits/stdc++.h>
using namespace std;
int A[3007];
double dp[10000007];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (A[i] > A[j]) {
        cnt++;
      }
    }
  }
  dp[0] = 0.0000000;
  dp[1] = 1.00;
  dp[2] = 5.00;
  for (int i = 3; i <= cnt; i++) {
    dp[i] = 4 + dp[i - 2];
  }
  cout.precision(8);
  cout.setf(ios::fixed | ios::showpoint);
  cout << dp[cnt] << endl;
}
