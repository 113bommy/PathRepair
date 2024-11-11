#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(3e6 + 7);
int n, m, a[MAXN], c[MAXN];
pair<int, int> b[MAXN];
long long cnt[MAXN], ans[MAXN], res;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    c[a[i]]++;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i].first);
    b[i].second = i;
  }
  sort(a, a + n);
  int sz = unique(a, a + n) - a;
  for (int i = 0; i < sz; i++) {
    for (int j = i; j < sz && a[i] * 1ll * a[j] < MAXN; j++) {
      if (j == i)
        cnt[(a[i]) * (a[i])] += c[a[i]] * 1ll * (c[a[i]] - 1);
      else
        cnt[a[i] * a[j]] += c[a[i]] * 1ll * c[a[j]] * 2;
    }
  }
  b[m] = make_pair(1, -1);
  sort(b, b + m + 1);
  res = n * 1ll * (n - 1);
  for (int i = 1; i <= m; i++) {
    for (int j = b[i - 1].first; j < b[i].first; j++) {
      res -= cnt[j];
    }
    ans[b[i].second] = res;
  }
  for (int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
  return 0;
}
