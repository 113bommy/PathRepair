#include <bits/stdc++.h>
using namespace std;
int dp[5000100];
int main() {
  int i, j, n, d;
  int cnt = 0, sum = 0, c = 0;
  dp[0] = 1;
  cin >> n >> d;
  int p;
  for (i = 0; i < n; i++) {
    cin >> p;
    for (j = (sum += p); j >= p; j--)
      if (dp[j - p] == 1) dp[j] = 1;
  }
  while (1) {
    j = d + c;
    while (!dp[j] && j > c) j--;
    if (j == c) break;
    c = j;
    cnt++;
  }
  cout << c << ' ' << cnt << endl;
  return 0;
}
