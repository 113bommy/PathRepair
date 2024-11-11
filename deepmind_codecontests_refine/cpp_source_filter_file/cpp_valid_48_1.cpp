#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
long long a[N], b[N], c[N];
long long dpa[N][50], dpi[N][50];
void rmq_init() {
  for (int i = 1; i <= n; i++) {
    dpi[i][0] = c[i];
    dpa[i][0] = c[i];
  }
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dpi[i][j] = min(dpi[i][j - 1], dpi[i + (1 << j - 1)][j - 1]);
      dpa[i][j] = max(dpa[i][j - 1], dpa[i + (1 << j - 1)][j - 1]);
    }
}
long long rmq_min(int l, int r) {
  int k = 0;
  while ((1 << (k + 1)) <= r - l + 1) k++;
  return min(dpi[l][k], dpi[r - (1 << k) + 1][k]);
}
long long rmq_max(int l, int r) {
  int k = 0;
  while ((1 << (k + 1)) <= r - l + 1) k++;
  return max(dpa[l][k], dpa[r - (1 << k) + 1][k]);
}
void add(int pos, int x) {
  for (; pos <= n; pos += (pos & -pos)) {
    c[pos] += x;
  }
}
long long get(int pos) {
  long long ans = 0;
  while (pos > 0) {
    ans += c[pos];
    pos -= (pos & -pos);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", b + i);
    c[i] = c[i - 1] + a[i] - b[i];
  }
  rmq_init();
  int l, r;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &l, &r);
    long long tmp = c[l - 1];
    if (c[r] != tmp && rmq_max(l, r) > tmp) {
      printf("-1\n");
    } else {
      printf("%lld\n", tmp - rmq_min(l, r));
    }
  }
}
