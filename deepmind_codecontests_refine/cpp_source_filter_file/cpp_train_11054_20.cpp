#include <bits/stdc++.h>
using namespace std;
int n;
long long pre[20][20];
int a[400005];
void fpre() {
  vector<int> c(20, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20; j++) pre[j][a[i]] += c[j];
    c[a[i]]++;
  }
}
long long dp[1 << 20];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x - 1;
  }
  fpre();
  memset(dp, 63, sizeof(dp));
  dp[0] = 0;
  for (int mask = 0; mask < (1 << 20); mask++) {
    for (int i = 0; i < 20; i++) {
      if (mask & (1 << i)) continue;
      int c = 0;
      for (int j = 0; j < 20; j++) {
        if (!(mask & (1 << j)) && j != i) {
          c += pre[j][i];
        }
      }
      dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + c);
    }
  }
  cout << dp[0xfffff] << '\n';
}
