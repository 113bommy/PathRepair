#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, lsum = 0, rsum = 0;
  cin >> n;
  int l[n], r[n], dp[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    lsum += l[i];
    rsum += r[i];
    dp[i] = l[i] - r[i];
  }
  int diff = lsum - rsum;
  int b = abs(diff), c = 0;
  for (int i = 0; i < n; i++) {
    if (abs(2 * dp[i] - diff) > b) {
      b = abs(2 * dp[i] - diff);
      c = i + 1;
    }
  }
  cout << c << "\n";
  return 0;
}
