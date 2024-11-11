#include <bits/stdc++.h>
using namespace std;
int dp[1 << 22];
int c[1000001];
void solve(int k, int idx, int src) {
  dp[k] = src;
  for (int i = idx; i < 22; i++) {
    if (!(k & (1 << i)) && dp[k | (1 << i)] == 0)
      solve(k | (1 << i), i + 1, src);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n; i++) {
    solve(c[i], 0, c[i]);
  }
  for (int i = 0; i < n; i++) {
    int ivt = (1 << 22) - 1 - c[i];
    if (dp[ivt])
      printf("%d ", dp[ivt]);
    else
      printf("-1 ");
  }
  printf("\n");
}
