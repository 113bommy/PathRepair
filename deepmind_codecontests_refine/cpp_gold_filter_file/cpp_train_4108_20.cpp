#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 10;
int Hash[Maxn];
long long dp[Maxn];
long long process(int l, int r) {
  long long sum1 = 0, sum2 = 0;
  for (int i = l; i < r; i++) {
    long long v = (long long)Hash[i] * i;
    if (i - 2 >= l) v += dp[i - 2];
    dp[i] = max(v, dp[i - 1]);
  }
  return dp[r - 1];
}
int main() {
  memset(Hash, 0, sizeof(Hash));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    Hash[v]++;
  }
  long long ret = 0;
  int l = -1, r = -1;
  for (int i = 0; i < Maxn; i++) {
    if (Hash[i] != 0 && l == -1) {
      l = i;
    } else if (Hash[i] == 0 && l != -1) {
      r = i;
      ret += process(l, r);
      l = r = -1;
    }
  }
  cout << ret << endl;
  return 0;
}
