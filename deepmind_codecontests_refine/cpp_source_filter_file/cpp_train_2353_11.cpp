#include <bits/stdc++.h>
using namespace std;
int ep[200005];
int dp[200005];
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  while (n--) {
    int a, b;
    scanf("%d%d", &a, &b);
    ep[a]++;
    ep[b + 1]--;
  }
  for (int i = 1; i <= 200000; ++i) {
    ep[i] += ep[i - 1];
    if (ep[i] == k) dp[i]++;
    dp[i] += dp[i - 1];
  }
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", dp[b] - dp[a - 1]);
  }
}
