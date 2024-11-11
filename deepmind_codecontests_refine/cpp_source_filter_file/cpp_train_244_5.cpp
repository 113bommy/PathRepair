#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 10;
int dp[MAX_N];
long long a[MAX_N];
long long a2[MAX_N];
int pw[MAX_N];
int n;
bool check(int i, int j) {
  if (a2[i] % a2[j] != 0) return false;
  return pw[j] <= j - i - 1 || pw[j] == pw[i] + 2;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a2[i] = a[i];
    while (a2[i] % 2 == 0) {
      a2[i] /= 2;
      ++pw[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[i] = max(dp[i], 1);
    for (int j = i + 1; j < n; ++j) {
      if (check(i, j)) dp[j] = max(dp[j], dp[i] + 1);
    }
  }
  cout << n - *max_element(dp, dp + n) << endl;
  return 0;
}
