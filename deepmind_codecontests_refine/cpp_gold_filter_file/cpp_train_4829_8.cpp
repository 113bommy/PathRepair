#include <bits/stdc++.h>
using namespace std;
bool d[400005];
int s[400005];
int Query(int k, int l, int r, int x, int y) {
  if (x > y) return 0;
  if (l == x && r == y) return s[k];
  int m = l + r >> 1;
  if (d[k]) {
    d[k << 1] ^= 1;
    d[(k << 1) ^ 1] ^= 1;
    s[k << 1] = m - l + 1 - s[k << 1];
    s[(k << 1) ^ 1] = r - m - s[(k << 1) ^ 1];
    d[k] = 0;
  }
  if (y <= m) return Query(k << 1, l, m, x, y);
  if (x > m) return Query((k << 1) ^ 1, m + 1, r, x, y);
  return Query(k << 1, l, m, x, m) + Query((k << 1) ^ 1, m + 1, r, m + 1, y);
}
void Change(int k, int l, int r, int x, int y) {
  if (x > y) return;
  if (l == x && r == y) {
    d[k] ^= 1;
    s[k] = r - l + 1 - s[k];
    return;
  }
  int m = l + r >> 1;
  if (d[k]) {
    d[k << 1] ^= 1;
    d[(k << 1) ^ 1] ^= 1;
    s[k << 1] = m - l + 1 - s[k << 1];
    s[(k << 1) ^ 1] = r - m - s[(k << 1) ^ 1];
    d[k] = 0;
  }
  if (y <= m)
    Change(k << 1, l, m, x, y);
  else if (x > m)
    Change((k << 1) ^ 1, m + 1, r, x, y);
  else {
    Change(k << 1, l, m, x, m);
    Change((k << 1) ^ 1, m + 1, r, m + 1, y);
  }
  s[k] = s[k << 1] + s[(k << 1) ^ 1];
}
int a[100005];
vector<int> v[100005], e[100005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    x = lower_bound(a + 1, a + 1 + n, x) - a;
    y = upper_bound(a + 1, a + 1 + n, y) - a - 1;
    v[x].push_back(y);
    e[y].push_back(x);
  }
  long long ans = (long long)n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < v[i].size(); j++) Change(1, 1, n, i, v[i][j]);
    int t = Query(1, 1, n, 1, i - 1) + (n - i) - Query(1, 1, n, i + 1, n);
    ans -= (long long)t * (t - 1) >> 1;
    for (int j = 0; j < e[i].size(); j++) Change(1, 1, n, e[i][j], i);
  }
  printf("%I64d\n", ans);
}
