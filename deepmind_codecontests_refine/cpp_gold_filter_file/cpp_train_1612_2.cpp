#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  long double p;
  cin >> n >> p >> t;
  long double prob[n + 1][t + 1];
  for (int i = 1; i <= n; i++) {
    prob[i][0] = 0;
  }
  prob[0][0] = 1;
  for (int i = 1; i <= t; i++) {
    prob[0][i] = pow((1 - p), i);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= t; j++) {
      prob[i][j] = p * prob[i - 1][j - 1] + (1 - p) * prob[i][j - 1];
    }
  }
  for (int j = 1; j <= t; j++) {
    prob[n][j] = p * prob[n - 1][j - 1] + prob[n][j - 1];
  }
  cout << setprecision(8);
  long double ans = 0;
  for (int i = 0; i <= n; i++) {
    long double j = i;
    ans += j * prob[i][t];
  }
  cout << ans;
}
