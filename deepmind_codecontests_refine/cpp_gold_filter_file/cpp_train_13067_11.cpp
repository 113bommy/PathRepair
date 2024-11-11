#include <bits/stdc++.h>
using namespace std;
int d, n, m;
long long ans;
int k[1000006];
int T[4 * 1000006];
int ind[1000006];
pair<int, int> p[1000006];
void upd(int x, int y, int l, int r, int node) {
  if (l == r) {
    T[node] = y;
    return;
  }
  if (x <= (l + r) / 2)
    upd(x, y, l, (l + r) / 2, node * 2);
  else
    upd(x, y, (l + r) / 2 + 1, r, node * 2 + 1);
  T[node] = min(T[node * 2], T[node * 2 + 1]);
}
int get(int x, int l, int r, int node) {
  if (x < l) return m + 1;
  if (x >= r) return T[node];
  return min(get(x, l, (l + r) / 2, node * 2),
             get(x, (l + r) / 2 + 1, r, node * 2 + 1));
}
int main() {
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p + 1, p + 1 + m);
  for (int i = 0; i < 4 * 1000006; i++) T[i] = m + 1;
  for (int i = m; i > 0; i--)
    k[i] = get(p[i].second, 1, 1000006, 1), upd(p[i].second, i, 1, 1000006, 1);
  p[m + 1] = {d, 0};
  int pr = 0, j = n;
  for (int i = 1; i <= m; i++) {
    n -= p[i].first - pr;
    if (n < 0) {
      printf("-1");
      return 0;
    }
    pr = p[i].first;
    ans +=
        min(j - n, max(0, p[k[i]].first - p[i].first - n)) * 1LL * p[i].second;
    n += min(j - n, max(0, p[k[i]].first - p[i].first - n));
  }
  n -= d - pr;
  if (n < 0) ans = -1;
  printf("%lld\n", ans);
}
