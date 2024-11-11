#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int Inf = 1e5 + 100;
stack<int> a;
int dp[N];
int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  dp[0] = Inf;
  a.push(0);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    while (a.size() && vec[i] > vec[a.top()]) {
      dp[i] = max(dp[i], dp[a.top()] + 1);
      a.pop();
    }
    a.push(i);
  }
  for (int i = 0; i < n; i++)
    if (dp[i] < Inf) ans = max(ans, dp[i]);
  cout << ans << endl;
}
