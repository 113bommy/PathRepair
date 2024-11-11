#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int k[N], d[N], c[N], t[N], lst[N];
vector<int> E[N];
bool check(int x) {
  for (int i = 1; i <= n; i++) lst[i] = c[i] = 0;
  for (int i = 1; i <= m; i++)
    if (d[i] <= x) lst[t[i]] = max(lst[t[i]], d[i]);
  for (int i = 1; i <= x; i++) E[i].clear();
  for (int i = 1; i <= n; i++) E[lst[i]].push_back(i);
  int bonus = 0;
  for (int i = 1; i <= x; i++) {
    bonus++;
    for (int v : E[i]) {
      int d = min(k[v], bonus);
      c[v] += d;
      bonus -= d;
    }
  }
  for (int i = 1; i <= n; i++) {
    int d = k[i] - c[i];
    bonus -= 2 * d;
    if (bonus < 0) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
  for (int i = 1; i <= m; i++) scanf("%d%d", &d[i], &t[i]);
  int low = 0, high = 4e5 + 5;
  while (low < high) {
    int mid = (high + low) >> 1;
    if (check(mid))
      high = mid;
    else
      low = mid + 1;
  }
  printf("%d\n", low);
}
