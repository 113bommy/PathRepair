#include <bits/stdc++.h>
using namespace std;
long long dp[2010][2010];
long long fact[4010];
long long solve(int n, int k) {
  if (k < 0 or n < 0)
    return 0;
  else if (k == 0)
    return fact[n];
  else if (dp[n][k] != -1)
    return dp[n][k];
  long long ret = 0;
  ret += n * solve(n, k - 1);
  ret += (k - 1) * solve(n + 1, k - 2);
  ret %= 1000000007;
  return (dp[n][k] = ret);
}
int main() {
  memset(dp, -1, sizeof(dp));
  fact[0] = 1;
  for (int i = 1; i < 4000; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
  int N;
  cin >> N;
  set<int> used;
  int a = 0, b = 0;
  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
    if (x != -1) used.insert(i);
  }
  for (int i = 0; i < N; i++) {
    if (used.find(i) != used.end()) continue;
    if (arr[i] == -1)
      b += 1;
    else
      a += 1;
  }
  cout << solve(a, b) << endl;
  return 0;
}
