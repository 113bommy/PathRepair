#include <bits/stdc++.h>
using namespace std;
int n, L, data[200010];
int que[200010], g, h;
long long sum[200010];
int ansL = -1, ansR = -1;
void check(int l, int r) {
  if (ansL == -1 || sum[l] + sum[r] > sum[ansL] + sum[ansR] ||
      sum[l] + sum[r] == sum[ansL] + sum[ansR] && l < ansL ||
      sum[l] + sum[r] == sum[ansL] + sum[ansR] && l == ansL && r < ansR)
    ansL = l, ansR = r;
}
int main() {
  scanf("%d%d", &n, &L);
  for (int i = 0; i < n; i++) scanf("%d", &data[i]);
  for (int i = 0; i < L; i++) sum[0] += data[i];
  for (int i = 1; i + L <= n; i++)
    sum[i] = sum[i - 1] - data[i - 1] + data[i + L - 1];
  for (int i = 0; i + L <= n; i++) {
    while (h && sum[i] > sum[que[h - 1]]) h--;
    que[h++] = i;
  }
  for (int i = 0; i + L <= n; i++) {
    while (g < h && que[g] - i < L) g++;
    if (g < h) check(i, que[g]);
  }
  printf("%d %d\n", ansL + 1, ansR + 1);
  return 0;
}
