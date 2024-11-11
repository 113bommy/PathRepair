#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int maxi = 2 * 1e5 + 100;
vector<int> g[maxn];
int st[maxi];
set<int> s1;
set<int>::iterator it;
int fu(int start, int end, int ind, int val) {
  if (end >= start) {
    int mid = start + (end - start) / 2;
    if (g[ind][mid] >= val and (mid == start or g[ind][mid - 1] < val))
      return mid;
    if (g[ind][mid] >= val) return fu(start, mid - 1, ind, val);
    return fu(mid + 1, end, ind, val);
  }
  return 0;
}
void update(int ss, int se, int ind, int si) {
  if (ind < ss or ind > se) return;
  st[si] += 1;
  if (ss != se) {
    int mid = ss + (se - ss) / 2;
    update(ss, mid, ind, 2 * si + 1);
    update(mid + 1, se, ind, 2 * si + 2);
  }
  return;
}
int getsum(int ss, int se, int qs, int qe, int si) {
  if (qs > se or qe < ss) return 0;
  if (ss >= qs and se <= qe) return st[si];
  int mid = ss + (se - ss) / 2;
  return getsum(ss, mid, qs, qe, 2 * si + 1) +
         getsum(mid + 1, se, qs, qe, 2 * si + 2);
}
void solve() {
  int n, p, m, k, z, y, x;
  memset(st, 0, sizeof(st));
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; i++) {
    scanf("%d", &x);
    g[x].push_back(i);
    s1.insert(x);
  }
  int cur = 0;
  z = 0;
  long long int sum = 0, ans = 1;
  for (it = s1.begin(); it != s1.end(); ++it) {
    int i = (*it);
    if (g[i][(int)g[i].size() - 1] < cur) {
      int prev = g[i][(int)g[i].size() - 1];
      ans += (n - cur + prev - sum + getsum(0, n - 1, prev, cur, 0));
      cur = prev;
      for (int j = 0; j <= (int)g[i].size() - 1; j++)
        update(0, n - 1, g[i][j], 0);
      sum += (int)g[i].size();
      continue;
    }
    int j = fu(0, (int)g[i].size() - 1, i, cur);
    if (j == 0) {
      int prev = g[i][(int)g[i].size() - 1];
      ans += (prev - cur - getsum(0, n - 1, cur + 1, prev, 0));
      cur = prev;
      sum += (int)g[i].size();
      for (int j = 0; j <= (int)g[i].size() - 1; j++)
        update(0, n - 1, g[i][j], 0);
      continue;
    }
    int prev = g[i][j - 1];
    ans += (n - cur + prev - sum + getsum(0, n - 1, prev, cur, 0));
    cur = prev;
    for (int j = 0; j <= (int)g[i].size() - 1; j++)
      update(0, n - 1, g[i][j], 0);
    sum += (int)g[i].size();
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
