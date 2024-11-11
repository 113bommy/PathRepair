#include <bits/stdc++.h>
using namespace std;
int g[100005];
int v[100005];
int b[100005];
int u[100005];
int lastpos[100005];
int lastcnt[100005];
int inquery[100005], qcs = 0;
const int INF = 100000001;
int go(int a, int L) {
  int ret = 0;
  if (L <= 0) return 0;
  if (inquery[a] == qcs) {
    lastpos[a] = a;
    lastcnt[a] = INF;
    return 0;
  }
  inquery[a] = qcs;
  if (!u[a]) {
    ++ret;
    u[a] = 1;
    lastpos[a] = g[a];
    lastcnt[a] = 1;
  }
  if (lastcnt[a] >= L) {
    return ret;
  }
  int val = L - lastcnt[a];
  ret += go(lastpos[a], val);
  lastcnt[a] = min(lastcnt[a] + lastcnt[lastpos[a]], INF);
  lastpos[a] = lastpos[lastpos[a]];
  return ret;
}
int query(int a, int L) {
  ++qcs;
  return go(a, L);
}
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    lastpos[i] = i;
    scanf("%d", &g[i]);
  }
  for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) {
    int a = (v[i] + res - 1) % n + 1;
    res = query(a, b[i]);
    printf("%d\n", res);
  }
  return 0;
}
