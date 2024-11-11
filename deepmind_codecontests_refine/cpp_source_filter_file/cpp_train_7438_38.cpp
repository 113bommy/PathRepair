#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
pair<int, int> q[maxn], p[maxn], res[maxn];
int n, r, cnt, now, ans;
int dist2(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first * a.first + a.second * a.second >
         b.first * b.first + b.second * b.second;
}
void dfs(int k) {
  if (k >= 3 &&
      (p[k - 1].first < p[k - 2].first ||
       p[k - 1].first == p[k - 2].first && p[k - 1].second < p[k - 2].second))
    return;
  if (now + ((n - k + 1) * (n - 1) - (n - k + 1) * (n - k) / 2) * 4 * r * r <=
      ans)
    return;
  if (k == n + 1) {
    ans = now;
    for (int j = (1); j <= k; j++) res[j] = p[j];
    return;
  }
  for (int i = (1); i <= cnt; i++) {
    p[k] = make_pair(q[i].first, q[i].second);
    for (int j = (1); j <= k - 1; j++) now += dist2(p[j], p[k]);
    dfs(k + 1);
    for (int j = (1); j <= k - 1; j++) now -= dist2(p[j], p[k]);
    p[k] = make_pair(q[i].second, -q[i].first);
    for (int j = (1); j <= k - 1; j++) now += dist2(p[j], p[k]);
    dfs(k + 1);
    for (int j = (1); j <= k - 1; j++) now -= dist2(p[j], p[k]);
    p[k] = make_pair(-q[i].first, -q[i].second);
    for (int j = (1); j <= k - 1; j++) now += dist2(p[j], p[k]);
    dfs(k + 1);
    for (int j = (1); j <= k - 1; j++) now -= dist2(p[j], p[k]);
    p[k] = make_pair(-q[i].second, q[i].first);
    for (int j = (1); j <= k - 1; j++) now += dist2(p[j], p[k]);
    dfs(k + 1);
    for (int j = (1); j <= k - 1; j++) now -= dist2(p[j], p[k]);
  }
}
int main() {
  scanf("%d%d", &n, &r);
  for (int a = (0); a <= r - 1; a++) {
    int b = 0;
    while (a * a + (b + 1) * (b + 1) <= r * r) b++;
    if (b != q[cnt].second)
      q[++cnt] = make_pair(a, b);
    else
      q[cnt].first = a;
  }
  sort(q + 1, q + cnt + 1, cmp);
  while (cnt >= 5) cnt--;
  now = 0;
  dfs(1);
  printf("%d\n", ans);
  for (int i = (1); i <= n; i++) printf("%d %d\n", res[i].first, res[i].second);
  return 0;
}
