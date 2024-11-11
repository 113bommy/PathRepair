#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
long long dp[N], org[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int x;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++org[x];
  }
  for (int i = N - 1; i >= 1; --i) {
    dp[i] += org[i] + dp[i + 1];
    if (dp[i] >= k) {
      printf("%d\n", i);
      return 0;
    }
    int u = i / 2, v = i - u;
    org[u] += org[i];
    org[v] += org[i];
    dp[v] -= org[i];
  }
  printf("-1\n");
  return 0;
}
