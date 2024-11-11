#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e3 + 5;
int t[MAX], d[MAX], memo[MAX][MAX];
int n, k;
int roll(int idx, int left) {
  if (idx == 0) {
    return 0;
  }
  int &ans = memo[idx][left];
  if (~ans) {
    return ans;
  }
  ans = max(roll(idx - 1, left) + d[idx], t[idx] + d[idx] - 1);
  if (left > 0) {
    ans = min(ans, roll(idx - 1, left - 1));
  }
  ans = min(ans, 86400);
  return ans;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = int(1); i < int(n + 1); i++) {
    scanf("%d %d", t + i, d + i);
  }
  memset(memo, -1, sizeof memo);
  int ans = 86400 - roll(n, k);
  for (int i = int(1); i < int(n + 1); i++) {
    ans = max(ans, t[i] - roll(i - 1, k) - 1);
  }
  printf("%d\n", ans);
  return 0;
}
