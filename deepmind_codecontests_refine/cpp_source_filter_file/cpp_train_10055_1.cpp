#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int mod = 1000000007;
const double PI = acos(-1.0);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int l[200007], r[200007];
int belong[200007];
int num;
int a[200007];
vector<int> b[200007 >> 1];
int n, q, x, y;
long long ans;
void init() {
  int block = sqrt(n);
  int num = n / block;
  if (n % block != 0) num++;
  for (int i = 1; i <= num; i++) {
    l[i] = (i - 1) * block + 1;
    r[i] = i * block;
    for (int j = l[i]; j <= r[i]; j++) {
      belong[j] = i;
      b[i].push_back(j);
    }
  }
}
int query(int u, int v, int w) {
  if (u > v) return 0;
  int cnt = 0;
  if (belong[u] == belong[v]) {
    for (int i = u; i <= v; i++)
      if (a[i] < w) cnt++;
    return cnt;
  }
  for (int i = u; i <= r[belong[u]]; i++) {
    if (a[i] < w) cnt++;
  }
  for (int i = belong[u] + 1; i < belong[v]; i++) {
    cnt += (lower_bound(b[i].begin(), b[i].end(), w) - b[i].begin());
  }
  for (int i = l[belong[v]]; i <= v; i++) {
    if (a[i] < w) cnt++;
  }
  return cnt;
}
void update(int u, int v) {
  int i = belong[u], j = belong[v];
  b[i].erase(lower_bound(b[i].begin(), b[i].end(), a[u]));
  b[i].insert(lower_bound(b[i].begin(), b[i].end(), a[v]), a[v]);
  b[j].erase(lower_bound(b[j].begin(), b[j].end(), a[v]));
  b[j].insert(lower_bound(b[j].begin(), b[j].end(), a[u]), a[u]);
  swap(a[u], a[v]);
}
int main() {
  scanf("%d%d", &n, &q);
  init();
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    if (x == y) {
      printf("%I64d\n", ans);
      continue;
    }
    if (x > y) swap(x, y);
    int t1 = query(x + 1, y - 1, a[x]);
    int t2 = y - x - 1 - t1;
    ans += (t2 - t1);
    t1 = query(x + 1, y - 1, a[y]);
    t2 = y - x - 1 - t1;
    ans += (t1 - t2);
    if (a[x] < a[y])
      ans++;
    else
      ans--;
    printf("%I64d\n", ans);
    update(x, y);
  }
  return 0;
}
