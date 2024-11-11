#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int MOD = int(1e9 + 7);
vector<int> p;
int n, arr[N], dp[1 << 11][2], Amask[N], contBP[100];
bool bs[100], blocked[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
  }
  bs[0] = bs[1] = 1;
  for (int i = 2; i <= 35; i++) {
    if (!bs[i]) {
      for (int j = i * i; j <= 35; j += i) bs[j] = 1;
      p.push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)p.size(); j++) {
      while (arr[i] % p[j] == 0) Amask[i] ^= 1 << j, arr[i] /= p[j];
    }
    if (arr[i] != 1) contBP[arr[i]]++, blocked[i] = 1;
  }
  int p2 = 1;
  for (int i = 35; i <= 70; i++) {
    for (int j = 0; j < contBP[i] - 1; j++) p2 = (p2 * 2) % MOD;
  }
  int ans = 0, f = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (blocked[i]) continue;
    for (int j = 0; j < 1 << 11; j++) {
      dp[j][f ^ 1] = (dp[j][f] + dp[j ^ Amask[i]][f]) % MOD;
    }
    f ^= 1;
  }
  ans = dp[0][f];
  printf("%d\n", ((1LL * p2 * ans - 1 + MOD) % MOD));
  return 0;
}
