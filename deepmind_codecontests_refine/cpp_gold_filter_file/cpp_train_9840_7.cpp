#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
long long sum[2][N];
int n, fl;
void out(int l, int r, int ll, int rr) {
  if (fl) swap(l, ll), swap(r, rr);
  printf("%d\n", r - l + 1);
  for (int i = l; i <= r; i++) printf("%d ", i);
  puts("");
  printf("%d\n", rr - ll + 1);
  for (int i = ll; i <= rr; i++) printf("%d ", i);
  puts("");
}
long long pre[2][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &sum[0][i]), sum[0][i] += sum[0][i - 1];
  for (int i = 1; i <= n; i++)
    scanf("%lld", &sum[1][i]), sum[1][i] += sum[1][i - 1];
  if (sum[0][n] > sum[1][n]) swap(sum[0], sum[1]), fl = 1;
  int now = 1;
  for (int i = 1; i <= n; i++) {
    while (sum[1][now] < sum[0][i]) now++;
    if (sum[1][now] == sum[0][i]) {
      out(1, i, 1, now);
      return 0;
    }
    int tmp = sum[1][now] - sum[0][i];
    if (pre[0][tmp]) {
      out(pre[0][tmp] + 1, i, pre[1][tmp] + 1, now);
      return 0;
    }
    pre[0][tmp] = i;
    pre[1][tmp] = now;
  }
  puts("-1");
  return 0;
}
