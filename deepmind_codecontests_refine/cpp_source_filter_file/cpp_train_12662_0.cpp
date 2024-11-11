#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int MOD = int(1e9 + 7);
vector<int> p;
int n, arr[N], dp[1 << 11][2], Amask[100], cont[100], f2[100];
bool bs[100], blocked[N];
int main() {
  f2[0] = 1;
  for (int i = 1; i <= 70; i++) f2[i] = (f2[i - 1] * 2) % MOD;
  for (int i = 2; i <= 35; i++) {
    if (!bs[i]) {
      for (int j = i * i; j <= 35; j += i) bs[j] = 1;
      p.push_back(i);
    }
  }
  for (int i = 1; i <= 70; i++) {
    int val = i;
    for (int j = 0; j < (int)p.size(); j++) {
      while (val % p[j] == 0) Amask[i] ^= 1 << j, val /= p[j];
    }
    if (val != 1) blocked[i] = 1;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    cont[arr[i]]++;
  }
  int p2 = 1;
  for (int i = 35; i <= 70; i++) {
    if (!blocked[i] || !cont[i]) continue;
    p2 = (1LL * p2 * f2[cont[i] - 1]) % MOD;
  }
  int f = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= 70; i++) {
    if (blocked[i] || !cont[i]) continue;
    for (int j = 0; j < 1 << 11; j++) {
      dp[j][f ^ 1] =
          (1LL * f2[cont[i] - 1] * (dp[j][f] + dp[j ^ Amask[i]][f])) % MOD;
    }
    f ^= 1;
  }
  printf("%lld\n", ((1LL * p2 * dp[0][f] - 1 + MOD) % MOD));
  return 0;
}
