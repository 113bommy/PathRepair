#include <bits/stdc++.h>
using namespace std;
int data[1000010], n;
int Log[1000010], mi[1000010][23];
long long sum[1000010];
void build_rmq() {
  Log[1] = 0;
  for (int i = 2; i <= n; i++)
    Log[i] = ((1 << (Log[i - 1] + 1)) > i) ? Log[i - 1] : (Log[i - 1] + 1);
  for (int i = 0; i < n; i++) mi[i][0] = data[i];
  for (int j = 1, l = 2; l <= n; j++, l <<= 1)
    for (int i = 0; i + l - 1 < n; i++)
      mi[i][j] = min(mi[i][j - 1], mi[i + (l >> 1)][j - 1]);
}
inline int ask(int l, int r) {
  int k = Log[r - l + 1];
  return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &data[i]);
  build_rmq();
  for (int i = 0; i < n; i++) {
    int l = i, r = i;
    int g = 0, h = i - 1;
    while (g <= h) {
      int mid = (g + h) / 2;
      if (ask(mid, i - 1) < data[i])
        g = mid + 1;
      else
        l = mid, h = mid - 1;
    }
    g = i + 1, h = n - 1;
    while (g <= h) {
      int mid = (g + h) / 2;
      if (ask(i + 1, mid) <= data[i])
        h = mid - 1;
      else
        r = mid, g = mid + 1;
    }
    l = i - l + 1, r = r - i + 1;
    sum[1] += data[i];
    sum[1 + r] -= data[i];
    sum[1 + l] -= data[i];
    sum[1 + l + r] += data[i];
  }
  for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
  for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
  int m, x;
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &x);
    printf("%.12f\n", sum[x] * 1.0 / (n - x + 1));
  }
  return 0;
}
