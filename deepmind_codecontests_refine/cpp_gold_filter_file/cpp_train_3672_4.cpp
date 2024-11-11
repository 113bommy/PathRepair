#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 100;
int T, n, k;
int A[maxn];
int dp[maxn];
stack<int> s1, s2;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) dp[i] = INT_MAX;
  dp[1] = 0;
  s1.push(1);
  s2.push(1);
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    int type = 1;
    if (A[i] > A[i - 1]) type = -1;
    if (A[i] == A[i - 1]) type = 0;
    while (!s1.empty() && A[s1.top()] >= A[i]) {
      int x = s1.top();
      s1.pop();
      if (type == 1) dp[i] = min(dp[i], dp[x] + 1);
    }
    if (!s1.empty() && type == 1) dp[i] = min(dp[i], dp[s1.top()] + 1);
    s1.push(i);
    while (!s2.empty() && A[s2.top()] <= A[i]) {
      int x = s2.top();
      s2.pop();
      if (type == -1) dp[i] = min(dp[i], dp[x] + 1);
    }
    if (!s2.empty() && type == -1) dp[i] = min(dp[i], dp[s2.top()] + 1);
    s2.push(i);
  }
  cout << dp[n] << endl;
}
