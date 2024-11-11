#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int x[N], d[N], l[N], r[N];
vector<int> v[N];
int st[N][20];
int query(int l, int r) {
  int k = log(r - l + 1) / log(2);
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}
void init(int n) {
  for (int i = n; i >= 1; i--) {
    if (r[i] > 0)
      st[i][0] = x[i] - r[i];
    else
      st[i][0] = 2e9;
    for (int j = 1; i + (1 << j) - 1 <= n; j++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n + 1; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]), d[i] *= 2;
  set<int> s;
  s.insert(0);
  for (int i = 1; i <= n; i++) {
    int p = *s.rbegin();
    l[i] = d[i] - (x[i] - x[p]);
    if (l[i] > 0) {
      s.insert(i);
      p = upper_bound(x, x + n + 2, x[i] + l[i]) - x - 1;
      v[p].push_back(i);
    }
    for (int j : v[i]) s.erase(j);
    v[i].clear();
  }
  s.clear(), s.insert(n + 1);
  for (int i = n; i >= 1; i--) {
    int p = *s.begin();
    r[i] = d[i] - (x[p] - x[i]);
    if (r[i] > 0) {
      s.insert(i);
      p = lower_bound(x, x + n + 2, x[i] - r[i]) - x;
      v[p].push_back(i);
    }
    for (int j : v[i]) s.erase(j);
    v[i].clear();
  }
  for (int i = 1; i <= n; i++)
    if (x[i] + l[i] >= x[n + 1]) return 0 * printf("0\n");
  r[n + 1] = l[0] = 1e9, init(n + 1);
  int ans = x[n + 1];
  for (int i = 0; i <= n; i++)
    if (l[i] > 0) {
      int lef = i, rig = n + 1;
      while (rig - lef > 1) {
        int mid = (lef + rig) / 2;
        if (x[i] + l[i] >= query(i + 1, mid))
          rig = mid;
        else
          lef = mid;
      }
      ans = min(ans, x[rig] - x[i]);
    }
  printf("%.2f\n", ans / 2.0);
}
