#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxm = 505;
const int maxe = 200005;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int n, m, k;
int num[maxn];
int dp[maxn], lef[maxn], rig[maxn];
void cal(int arr[maxn]) {
  memset(dp, 0, sizeof(dp));
  int ans = 1;
  dp[0] = num[1];
  arr[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (num[i] >= dp[ans - 1])
      dp[ans++] = num[i];
    else {
      int pos = upper_bound(dp, dp + ans, num[i]) - dp;
      dp[pos] = num[i];
    }
    arr[i] = ans;
  }
}
int a, b;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    num[a]++;
    num[b + 1]--;
  }
  for (int i = 1; i <= m; i++) {
    num[i] += num[i - 1];
  }
  cal(lef);
  reverse(num + 1, num + m + 1);
  cal(rig);
  reverse(rig + 1, rig + m + 1);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = max(ans, lef[i] + rig[i] - 1);
  }
  printf("%d\n", ans);
  return 0;
}
