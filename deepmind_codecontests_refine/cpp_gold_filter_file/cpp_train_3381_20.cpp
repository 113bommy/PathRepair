#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequenceDP(int a[], int n) {
  int dp[n], ans = 0;
  for (int k = 0; k < n; k++) {
    dp[k] = 1;
    for (int i = 0; i < k; i++) {
      if (a[i] <= a[k]) {
        dp[k] = max(dp[k], dp[i] + 1);
        ans = max(dp[k], ans);
      }
    }
  }
  return ans;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
void scanArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
int highestFromThree(int n1, int n2, int n3) { return max(max(n1, n2), n3); }
int highestFromFour(int n1, int n2, int n3, int n4) {
  return max(max(n1, n2), max(n3, n4));
}
int result[1000] = {0};
int factDP(int n) {
  if (n >= 0) {
    result[0] = 1;
    for (int i = 1; i <= n; ++i) {
      result[i] = i * result[i - 1];
    }
    return result[n];
  }
}
int main() {
  long long a, b, s;
  cin >> a >> b >> s;
  if ((s < abs(a) + abs(b)) || (((s - (abs(a) + abs(b))) % 2 == 1))) {
    cout << "No"
         << "\n";
  } else {
    cout << "Yes"
         << "\n";
  }
  return 0;
}
