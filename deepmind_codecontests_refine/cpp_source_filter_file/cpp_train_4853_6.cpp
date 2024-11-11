#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10, INF = 0x3f3f3f3f;
long long num[maxn], sum[maxn];
long long solve(int l, int r, int &p) {
  long long res = -INF;
  for (int i = l; i <= r; i += 2) {
    int u = sum[i] - sum[l] - (sum[r] - sum[i]);
    if (u > res) {
      p = i;
      res = u;
    }
  }
  return res;
}
int main() {
  long long res = -INF;
  int n, a1, a2, a3;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &num[2 * i + 1]);
  for (int i = 0; i <= n; i++) num[2 * i] = 0;
  sum[0] = 0;
  for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + num[i];
  for (int i = 0; i <= 2 * n; i += 2) {
    int p1, p2;
    long long temp1 = solve(0, i, p1);
    long long temp2 = solve(i, 2 * n, p2);
    if (temp1 + temp2 > res) {
      res = temp1 + temp2;
      a1 = p1;
      a2 = i;
      a3 = p2;
    }
  }
  printf("%d %d %d\n", a1 / 2, a2 / 2, a3 / 2);
  return 0;
}
