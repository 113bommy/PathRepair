#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int w[15];
int mp[(1 << 12) + 5];
int cnt[(1 << 12) + 5];
int ans[(1 << 12) + 5][105];
void init() {
  int sum, p;
  int x;
  for (int i = 0; i < (1 << n); i++) {
    x = i;
    sum = 0;
    p = n;
    while (x) {
      sum += w[p--] * (x & 1);
      x >>= 1;
    }
    mp[i] = sum;
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = i; j < (1 << n); j++) {
      if (mp[(i ^ j) ^ ((1 << n) - 1)] > 100) continue;
      ans[i][mp[(i ^ j) ^ ((1 << n) - 1)]] += cnt[j];
      if (i != j) ans[j][mp[(i ^ j) ^ ((1 << n) - 1)]] += cnt[i];
    }
    for (int j = 1; j <= 100; j++) ans[i][j] += ans[i][j - 1];
  }
  return;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  int x;
  char c;
  for (int i = 1; i <= m; i++) {
    x = 0;
    for (int j = 1; j <= n; j++) {
      scanf(" %c", &c);
      x <<= 1;
      x += c - '0';
    }
    cnt[x]++;
  }
  init();
  int k;
  while (q--) {
    x = 0;
    for (int i = 1; i <= n; i++) {
      scanf(" %c", &c);
      x <<= 1;
      x += c - '0';
    }
    scanf("%d", &k);
    printf("%d\n", ans[x][k]);
  }
  return 0;
}
