#include <bits/stdc++.h>
using namespace std;
int dp[1004];
long long ncr[1004][1004];
int ones(int n) {
  int cnt = 0;
  while (n) {
    if (n % 2 == 1) {
      cnt++;
    }
    n /= 2;
  }
  return cnt;
}
void calcncr() {
  for (int i = 0; i <= 1000; i++) {
    ncr[i][0] = 1;
  }
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % 1000000007;
    }
  }
}
int main() {
  string n;
  int k;
  calcncr();
  dp[1] = 0;
  for (int i = 2; i <= 1000; i++) {
    dp[i] = ones(i);
  }
  cin >> n >> k;
  if (k == 0) {
    cout << "1\n";
    return 0;
  }
  long long nones = 0, ans = 0;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '0') {
      continue;
    }
    for (int j = max(nones, 1LL); j < 1000; j++) {
      if (dp[j] == k - 1) {
        ans = (ans + ncr[n.size() - i - 1][j - nones]) % 1000000007;
        if (i == 0 && k == 1) {
          ans = (ans + 1000000007 - 1) % 1000000007;
        }
      }
    }
    nones++;
  }
  int cnt = 0;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '1') {
      cnt++;
    }
  }
  if (dp[cnt] == k - 1) {
    ans = (ans + 1) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
