#include <bits/stdc++.h>
using namespace std;
int n;
int cost[300][300];
int solve(int a, int b, int c) {
  long long ret = 0;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(i); j++)
      ret += cost[i][j] = cost[j][i] =
          min(cost[i][j],
              min(cost[j][a] + c + cost[b][i], cost[i][a] + c + cost[b][j]));
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) cin >> cost[i][j];
  int k;
  cin >> k;
  for (int i = 0; i < (int)(k); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a - 1, b - 1, c) << " ";
  }
  return 0;
}
