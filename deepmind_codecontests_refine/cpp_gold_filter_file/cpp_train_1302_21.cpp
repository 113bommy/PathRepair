#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int use[1000010], num[1000010], a[1000010], sum[1000010];
int main() {
  int p, K;
  scanf("%d%d", &p, &K);
  if (K == 0) {
    int res = 1;
    for (int i = 0; i < p - 1; i++) {
      res = (long long)res * p % MOD;
    }
    printf("%d\n", res);
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < p; i++) {
    int cur = i % p, len = 0;
    if (!use[cur]) {
      while (!use[cur]) {
        use[cur] = 1;
        len++;
        cur = (long long)cur * K % p;
      }
      num[len] += len;
      if (num[len] >= MOD) {
        num[len] -= MOD;
      }
      a[cnt++] = len;
    }
  }
  for (int i = 1; i <= p; i++) {
    for (int j = i; j <= p; j += i) {
      sum[j] += num[i];
      if (sum[j] >= MOD) {
        sum[j] -= MOD;
      }
    }
  }
  int res = 1;
  for (int i = 0; i < cnt; i++) {
    res = (long long)res * sum[a[i]] % MOD;
  }
  printf("%d\n", res);
  return 0;
}
