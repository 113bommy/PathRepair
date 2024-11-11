#include <bits/stdc++.h>
using namespace std;
long long modulo = 1e9 + 7;
template <class X>
void printarr(X arr[], int n) {
  for (int i = 0; i < n; ++i) cout << arr[i] << " ";
  cout << endl;
}
long long fpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % modulo;
    a = (a * a) % modulo;
    n = n >> 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x[n];
  char y[] = {'R', 'B', 'G'};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (y[j] == s[i]) x[i] = j;
    }
  }
  int dp[n][3], dp2[n][3];
  for (int i = 0; i < 3; ++i) {
    if (x[0] == i)
      dp[0][i] = 0;
    else
      dp[0][i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    if (dp[i - 1][1] > dp[i - 1][2]) {
      dp[i][0] = dp[i - 1][2];
      dp2[i][0] = 2;
    } else {
      dp[i][0] = dp[i - 1][1];
      dp2[i][0] = 1;
    }
    if (x[i] != 0) ++dp[i][0];
    if (dp[i - 1][0] > dp[i - 1][2]) {
      dp[i][1] = dp[i - 1][2];
      dp2[i][1] = 2;
    } else {
      dp[i][1] = dp[i - 1][0];
      dp2[i][1] = 0;
    }
    if (x[i] != 1) ++dp[i][1];
    if (dp[i - 1][0] > dp[i - 1][1]) {
      dp[i][2] = dp[i - 1][1];
      dp2[i][2] = 1;
    } else {
      dp[i][2] = dp[i - 1][0];
      dp2[i][2] = 0;
    }
    if (x[i] != 2) ++dp[i][2];
  }
  int ans = INT_MAX;
  int finalletter;
  for (int i = 0; i < 3; ++i) {
    if (ans > dp[n - 1][i]) {
      finalletter = i;
      ans = dp[n - 1][i];
    }
  }
  char final[n];
  final[n - 1] = y[finalletter];
  for (int i = n - 1; i > 0; --i) {
    final[i - 1] = y[dp2[i][finalletter]];
    finalletter = dp2[i][finalletter];
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) cout << final[i];
  return 0;
}
