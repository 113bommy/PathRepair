#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vc;
const int N = 1e5 + 5;
int dpL[N], dpR[N];
int dp[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vc.push_back(x);
  }
  if (n == 2) cout << 2 << endl, exit(0);
  for (int i = 0; i < n; i++) dpL[i] = 1, dpR[i] = 1, dp[i] = 1;
  for (int i = 1; i < n; i++)
    if (vc[i] > vc[i - 1]) dpL[i] = dpL[i - 1] + 1;
  for (int i = n - 2; i >= 0; i--)
    if (vc[i] < vc[i + 1]) dpR[i] = dpR[i + 1] + 1;
  for (int i = 0; i < n; i++) {
    int L = dpL[i - 1], R = dpR[i + 1];
    if (vc[i - 1] + 1 < vc[i + 1])
      dp[i] = max(dp[i], L + R + 1);
    else
      dp[i] = max(dp[i], max(L, R) + 1);
  }
  cout << *max_element(dp, dp + n) << endl;
  return 0;
}
