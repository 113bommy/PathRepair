#include <bits/stdc++.h>
using namespace std;
const int dr[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[]{0, 1, 1, 1, 0, -1, -1, -1};
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  run();
  int n;
  cin >> n;
  vector<int> v(n), pos(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    pos[v[i]] = i;
  }
  vector<int> dp(n);
  for (int val = 1; val <= n; val++) {
    int i = pos[val];
    for (int j = i + val; j < n; j += val)
      if (v[j] > val) dp[i] |= (1 ^ dp[j]);
    for (int j = i - val; j >= 0; j -= val)
      if (v[j] > val) dp[i] |= (1 ^ dp[j]);
  }
  for (int i = 0; i < n; i++) cout << (dp[i] ? "A" : "B");
}
