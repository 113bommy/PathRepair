#include <bits/stdc++.h>
static const long long int mod = 1000000007LL;
struct matrix {
  int val[208][208];
  matrix() { memset(val, 0, sizeof(val)); }
  matrix operator*(const matrix &v) const {
    matrix ans;
    for (int i = 0; i < 208; ++i) {
      for (int j = 0; j < 208; ++j) {
        long long int a = 0;
        for (int k = 0; k < 208; ++k) {
          a += (long long int)val[i][k] * v.val[k][j] % mod;
        }
        ans.val[i][j] = a % mod;
      }
    }
    return ans;
  }
};
int n, m, k;
int cnt[16];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i < 16; ++i) cnt[i] = (cnt[i ^ (i & -i)] + 1);
  int b = (1 << m) - 1;
  matrix base;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= b; ++j) {
      base.val[((j) * (k + 1) + (i))][(((j << 1) & b) * (k + 1) + (i))] += 1;
      if (i != k)
        base.val[((j) * (k + 1) + (i))]
                [((((j << 1) & b) + 1) * (k + 1) + (i + 1))] += cnt[j] + 1;
    }
  }
  matrix cur;
  for (int i = 0; i < ((k + 1) << m); ++i) cur.val[i][i] = 1;
  for (int i = 0; n != 0; ++i) {
    if ((n & (1 << i)) != 0) {
      n ^= (1 << i);
      cur = cur * base;
    }
    base = base * base;
  }
  long long int ans = 0;
  for (int i = 0; i <= b; ++i)
    ans += cur.val[((0) * (k + 1) + (0))][((i) * (k + 1) + (k))];
  printf("%d\n", (int)(ans % mod));
}
