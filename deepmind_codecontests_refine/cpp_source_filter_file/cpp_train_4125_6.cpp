#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int N, L, M;
int st[100010], gl[100010], ct[100010];
long long num[110];
long long dp[110], res[110], nx[110];
long long ans[110];
int main() {
  scanf("%d %d %d", &N, &L, &M);
  for (int i = 0; i < (N); i++) {
    scanf("%d", &gl[i]);
    ++ans[gl[i]];
  }
  for (int i = 0; i < (N); i++) {
    scanf("%d", &ct[i]);
    ++num[ct[i]];
  }
  for (int i = 0; i < (N); i++) scanf("%d", &gl[i]);
  int k = L - 2;
  dp[0] = 1;
  for (int i = 0; i < (M); i++) res[i] = num[i];
  while (k > 0) {
    if (k & 1) {
      memset(nx, 0, sizeof(nx));
      for (int i = 0; i < (M); i++) {
        for (int j = 0; j < (M); j++) {
          (nx[(i + j) % M] += dp[i] * res[j]) %= MOD;
        }
      }
      for (int i = 0; i < (M); i++) dp[i] = nx[i];
    }
    memset(nx, 0, sizeof(nx));
    for (int i = 0; i < (M); i++) {
      for (int j = 0; j < (M); j++) {
        (nx[(i + j) % M] += res[i] * res[j]) %= MOD;
      }
    }
    for (int i = 0; i < (M); i++) res[i] = nx[i];
    k /= 2;
  }
  memset(nx, 0, sizeof(nx));
  for (int i = 0; i < (M); i++) {
    for (int j = 0; j < (M); j++) {
      (nx[(i + j) % M] += ans[i] * dp[j]) %= MOD;
    }
  }
  for (int i = 0; i < (M); i++) ans[i] = nx[i];
  memset(nx, 0, sizeof(nx));
  long long ret = 0;
  for (int i = 0; i < (N); i++) {
    int mm = (M + M - gl[i] - ct[i]) % M;
    ret = (ret + ans[mm]) % MOD;
  }
  cout << ret << endl;
  return 0;
}
