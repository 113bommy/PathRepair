#include <bits/stdc++.h>
using namespace std;
const int N = 100010, MOD = 1e9 + 7;
const long long Inf = 1000000000000000LL;
int n, Q, top, a[N], st[N], ans[N];
long long power[N], inv[N], mul[N], sum[N], sum2[N];
struct node {
  int l, r, id;
} ask[N];
bool cmp(node x, node y) { return x.r < y.r; }
int main() {
  scanf("%d%d", &n, &Q);
  power[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    power[i] = power[i - 1] * 2 % MOD;
    inv[i] = inv[i - 1] * 500000004 % MOD;
    mul[i] = (mul[i - 1] + power[i] * a[i]) % MOD;
  }
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d", &ask[i].l, &ask[i].r);
    ask[i].id = i;
  }
  sort(ask + 1, ask + 1 + Q, cmp);
  for (int i = 1, j = 1; i <= Q; i++) {
    int l = ask[i].l, r = ask[i].r;
    for (; j <= r; j++) {
      st[++top] = j;
      sum[top] = a[j];
      while (top > 1 && sum[top] > 0) {
        if (st[top] - st[top - 1] >= 50 ||
            (1LL << st[top] - st[top - 1]) > (Inf - sum[top - 1]) / sum[top])
          sum[top - 1] = Inf;
        else
          sum[top - 1] += (1LL << st[top] - st[top - 1]) * sum[top];
        top--;
      }
      if (sum[top] < Inf)
        sum2[top] = (sum2[top - 1] + sum[top]) % MOD;
      else
        sum2[top] = mul[j];
    }
    st[top + 1] = r + 1;
    int p = upper_bound(st + 1, st + 2 + top, l) - st;
    ans[ask[i].id] = ((sum2[top] - sum2[p - 1]) * 2 +
                      (mul[st[p] - 1] - mul[l - 1]) * inv[l]) %
                     MOD;
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", (ans[i] % MOD + MOD) % MOD);
  return 0;
}
