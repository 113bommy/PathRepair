#include <bits/stdc++.h>
using namespace std;
int n, k;
struct Date {
  int l, r, n;
} a[800000];
bool cmp(const Date a, const Date b) { return a.l < b.l; }
int ans = 0;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].n = i;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    q.push(pair<int, int>(a[i].r, a[i].n));
    while (q.size() > k) q.pop();
    if (q.size() == k) ans = max(q.top().first - a[i].l + 1, ans);
  }
  while (!q.empty()) q.pop();
  printf("%d\n", ans);
  if (ans)
    for (int i = 1; i <= n; i++) {
      q.push(pair<int, int>(a[i].r, i));
      while (q.size() > k) q.pop();
      if (q.size() == k && q.top().first - a[i].l + 1 == ans) {
        while (!q.empty()) printf("%d ", q.top().second), q.pop();
        break;
      }
    }
  else {
    for (int i = 1; i <= k; i++) printf("%d ", i);
  }
  printf("\n");
  return 0;
}
