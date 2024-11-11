#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, faz[MAXN], cnt, son[MAXN], head[MAXN], nex[MAXN];
long long T, q[MAXN], t[MAXN], sum[10 * MAXN][2], num[10 * MAXN], d[MAXN],
    ans[MAXN], ans2[MAXN], ans3[MAXN];
void adde(int x, int y, long long z) {
  son[++cnt] = y;
  d[cnt] = z;
  nex[cnt] = head[x];
  head[x] = cnt;
}
int lowbit(int x) { return x & (-x); }
void add(int x, long long val, int sign) {
  while (x <= 1e6) {
    sum[x][sign] += val;
    x += lowbit(x);
  }
}
long long query(int x, int sign) {
  long long ans = 0;
  while (x) {
    ans += sum[x][sign];
    x -= lowbit(x);
  }
  return ans;
}
void dfs(int x, int fa) {
  add(t[x], t[x] * q[x], 0);
  add(t[x], q[x], 1);
  int L = 0, R = 1e6;
  while (L <= R) {
    int mid = (L + R) / 2;
    long long summ = query(mid, 0);
    if (T >= summ) {
      L = mid + 1;
      ans[x] = min((T - summ) / L + query(mid, 1), query(mid + 1, 1));
    } else {
      R = mid - 1;
    }
  }
  for (int i = head[x]; i; i = nex[i]) {
    int u = son[i];
    T -= 2 * d[i];
    dfs(u, x);
    T += 2 * d[i];
    if (ans[u] > ans2[x]) {
      ans3[x] = ans2[x];
      ans2[x] = ans[u];
    } else if (ans[u] > ans3[x]) {
      ans3[x] = ans[u];
    }
  }
  ans[x] = max(ans[x], ans3[x]);
  add(t[x], -t[x] * q[x], 0);
  add(t[x], -q[x], 1);
}
int main() {
  scanf("%d%lld", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%lld", &q[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &t[i]);
  for (int i = 2; i <= n; i++) {
    long long z;
    scanf("%d%lld", &faz[i], &z);
    adde(faz[i], i, z);
  }
  dfs(1, 0);
  printf("%lld\n", max(ans[1], ans2[1]));
  return 0;
}
