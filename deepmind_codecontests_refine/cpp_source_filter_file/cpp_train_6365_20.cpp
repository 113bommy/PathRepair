#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200051;
struct Edge {
  int id;
  long long re;
  int nxt;
} g[MAXN];
int n, k, gsz;
int fte[MAXN];
long long a[MAXN], b[MAXN];
void addedge(int t, int id, long long re) {
  g[++gsz] = (Edge){id, re, fte[t]};
  fte[t] = gsz;
}
bool check(long long x) {
  gsz = 0;
  memset(fte, 0, sizeof(fte));
  for (int i = 1; i <= n; i++) {
    if (a[i] < b[i] * k) {
      if (gsz >= k + 1) return false;
      addedge(a[i] / b[i] + 1, i, a[i] % b[i]);
    }
  }
  if (x == 0) return gsz == 0;
  long long cnt = 0;
  for (int i = 1; i < k; i++) {
    cnt++;
    for (int j = fte[i]; j; j = g[j].nxt) {
      long long nm = (b[g[j].id] - g[j].re + x - 1) / x;
      if (cnt < nm) return false;
      cnt -= nm;
      if ((g[j].re + nm * x) / b[g[j].id] + i < k) {
        if (gsz >= k + 1) return false;
        addedge((g[j].re + nm * x) / b[g[j].id] + i, g[j].id,
                (g[j].re + nm * x) % b[g[j].id]);
      }
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = 1; i <= n; i++) scanf("%lld", b + i);
  long long lft = 0, rgt = 5e17, ans = -1;
  while (lft <= rgt) {
    long long mid = (lft + rgt) >> 1;
    if (check(mid)) {
      ans = mid;
      rgt = mid - 1;
    } else
      lft = mid + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
