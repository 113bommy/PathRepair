#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int N = 5E4 + 5;
const int M = 5E3 + 5;
const int LEN = 1E6 + 5;
int sum[LEN];
int a[N];
int mx[N];
pair<int, int> lr[M];
int res[M];
int main() {
  for (int i = 1; i < LEN; i++) {
    sum[i] = sum[i - 1] ^ i;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &lr[i].first, &lr[i].second);
  }
  for (int i = 1; i <= n; i++) {
    mx[i - 1] = 0;
    for (int j = i; j <= n; j++) {
      mx[j] = max(sum[a[i]] ^ sum[a[j]] ^ min(a[i], a[j]), mx[j - 1]);
    }
    for (int j = 1; j <= m; j++) {
      if (i >= lr[j].first && i <= lr[j].second) {
        res[j] = max(res[j], mx[lr[j].second]);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}
