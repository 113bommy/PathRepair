#include <bits/stdc++.h>
const int maxn = 1e5 + 100;
const int NUM = 23;
const int MOD = 1e9 + 7;
int pw[maxn], n, q;
int a[maxn];
void init() {
  pw[0] = 1;
  for (int i = 1; i < maxn; i++) pw[i] = 2ll * pw[i - 1] % MOD;
}
struct node {
  int cnt;
  int a[NUM], p[NUM];
  void ins(int x) {
    for (int i = NUM - 1; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (a[i])
          x ^= a[i];
        else {
          a[i] = x;
          return;
        }
      }
    }
  }
  void rebuild() {
    for (int i = NUM - 1; i >= 0; i--)
      for (int j = i - 1; j >= 0; j--)
        if ((a[i] >> j) & 1) a[i] ^= a[j];
    for (int i = 0; i < NUM; i++)
      if (a[i]) p[cnt++] = a[i];
  }
} sum[maxn];
int main() {
  init();
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    sum[i].ins(a[i]);
  }
  for (int i = 1; i <= n; i++) sum[i].rebuild();
  while (q--) {
    int l, x;
    scanf("%d %d", &l, &x);
    for (int i = NUM - 1; i >= 0; i--)
      if ((x >> i) & 1) x ^= sum[l].p[i];
    if (x)
      puts("0");
    else
      printf("%d\n", pw[l - sum[l].cnt]);
  }
  return 0;
}
