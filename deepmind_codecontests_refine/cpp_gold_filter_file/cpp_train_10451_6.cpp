#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
struct fat {
  int l, r, id;
} a[MAXN];
inline bool cmp(const fat &a, const fat &b) { return a.r < b.r; }
int n;
int v[MAXN];
int last[MAXN], sum[MAXN];
bool use[MAXN];
inline bool jiao(const int &x, const int &y) {
  return max(a[x].l, a[y].l) <= min(a[x].r, a[y].r);
}
inline bool check(int dis) {
  for (int i = (1); i <= (int)n; i++) last[i] = n;
  int now = 1;
  memset(use, 0, sizeof use);
  for (int i = (1); i <= (int)n; i++) {
    v[i] = now;
    last[now] = i;
    use[now] = 1;
    for (int j = (1); j <= (int)n; j++)
      if (jiao(now, j)) last[j] = min(last[j], last[now] + dis);
    memset(sum, 0, sizeof sum);
    for (int j = (1); j <= (int)n; j++) sum[last[j]]++;
    for (int j = (1); j <= (int)n; j++) sum[j] += sum[j - 1];
    for (int j = (1); j <= (int)n; j++)
      if (sum[j] > j) return 0;
    int first = 0;
    for (int j = (i + 1); j <= (int)n; j++)
      if (sum[j] == j) {
        first = j;
        break;
      }
    for (int j = (1); j <= (int)n; j++)
      if (!use[j] && last[j] <= first) {
        now = j;
        break;
      }
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (int)n; i++) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  int l, r, rp;
  l = 0;
  r = n;
  rp = n + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid, rp = mid;
    else
      l = mid + 1;
  }
  if (check(l)) rp = l;
  check(rp);
  for (int i = (1); i <= (int)n; i++) printf("%d ", a[v[i]].id);
  return 0;
}
