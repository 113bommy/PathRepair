#include <bits/stdc++.h>
using namespace std;
const int seed = 131;
const int maxn = 1200;
int n, q, m;
int val[13];
int num[(1 << 12)];
int sum[(1 << 12)][maxn];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%d", &val[i]);
  for (int i = 1; i <= m; i++) {
    char s[15];
    scanf("%s", s);
    int tmp = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') tmp |= (1 << j);
    }
    num[tmp]++;
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (num[j] == 0) continue;
      int cnt = 0;
      for (int k = n - 1; k >= 0; k--) {
        if (((i >> k) & 1) == ((j >> k) & 1)) cnt += val[n - k - 1];
      }
      sum[i][cnt] += num[j];
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 1; j < maxn; j++) {
      sum[i][j] += sum[i][j - 1];
    }
  }
  while (q--) {
    int k;
    char s[15];
    scanf("%s%d", s, &k);
    int len = strlen(s);
    int tmp = 0;
    for (int j = 0; j < len; j++) {
      if (s[j] == '1') tmp |= (1 << j);
    }
    printf("%d\n", sum[tmp][k]);
  }
  return 0;
}
