#include <bits/stdc++.h>
using namespace std;
int freq[100005], val[100005];
int n;
vector<int> kola;
long long dp[100005];
int ponk = 0;
long long go(int num) {
  if (num > ponk) return 0;
  if (freq[num] == 0) return go(num + 1);
  if (dp[num] != -1) return dp[num];
  return dp[num] = max(1LL * num * freq[num] + go(num + 2), go(num + 1));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    freq[x]++;
    ponk = max(ponk, x);
  }
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", go(1));
}
