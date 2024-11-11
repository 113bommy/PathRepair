#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const long long mod = 1e9 + 7;
int n, a[maxn];
int q[maxn], c = 0;
long long pre[maxn], sum[maxn];
long long f(int x) { return x * sum[x] - pre[x]; }
int now;
bool judge(int x) {
  if (x == 0) return 1;
  return f(q[x]) - f(q[x - 1]) > sum[now] * (q[x] - q[x - 1]);
}
int BS(int l, int r) {
  if (r - l <= 1) {
    if (judge(r)) return r;
    return l;
  }
  int m = (l + r) / 2;
  if (judge(m)) return BS(m, r);
  return BS(l, m - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = a[i] + sum[i - 1];
    pre[i] = i * 1LL * a[i] + pre[i - 1];
  }
  q[c++] = 0;
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    now = i;
    while (c >= 2 && (f(q[c - 1]) - f(q[c - 2])) * (i - q[c - 1]) <
                         (f(i) - f(q[c - 1])) * (q[c - 1] - q[c - 2]))
      c--;
    q[c++] = i;
    int u = q[BS(0, c - 1)];
    ret = max(ret, pre[i] - pre[u] - u * (sum[i] - sum[u]));
  }
  printf("%I64d\n", ret);
  return 0;
}
