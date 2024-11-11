#include <bits/stdc++.h>
using namespace std;
map<int, int> pr;
map<int, int> dp;
int dfs(int x) {
  if (dp.find(x) != dp.end()) return dp[x];
  int dpp[32] = {0};
  for (int i = 1; i <= x; i <<= 1) {
    dpp[dfs((x % i) | ((x / i) >> 1))] = 1;
  }
  for (int i = 0; i < 32; i++) {
    if (dpp[i] == 0) {
      dp[x] = i;
      return i;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int aa;
    scanf("%d", &aa);
    for (int j = 2; j * j <= aa; j++) {
      int cnt = 0;
      if (aa % j == 0) {
        while (aa % j == 0) {
          aa /= j;
          cnt++;
        }
        pr[j] |= (1 << (cnt - 1));
      }
    }
    if (aa > 1) {
      pr[aa] |= 1;
    }
  }
  int ans = 0;
  for (auto &target : pr) {
    dp.clear();
    dp[0] = 0;
    ans ^= dfs(target.second);
  }
  if (ans == 0)
    printf("Arpa\n");
  else
    printf("Mojtaba\n");
}
