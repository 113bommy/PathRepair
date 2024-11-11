#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[300003];
int b[300003];
vector<pair<int, int> > g[300003];
int ans[300003];
int tr[(1 << 19) * 2];
inline void update(int pos) {
  for (int i = pos + (1 << 19); i >= 1; i /= 2) tr[i]++;
}
inline int get(int l, int r) {
  l += (1 << 19);
  r += (1 << 19);
  int res = 0;
  while (l <= r) {
    if (l & 1) {
      res += tr[l];
      ++l;
    }
    if (!(r & 1)) {
      res += tr[r];
      --r;
    }
    if (l > r) break;
    l /= 2;
    r /= 2;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b, b + n);
  m = unique(b, b + n) - b;
  for (int k = 1; k < n; ++k)
    for (int i = 0; i * k + 1 < n; ++i) {
      int left = i * k + 1;
      int right = min(i * k + k, n - 1);
      g[left - 1].push_back(make_pair(a[i], -k));
      g[right].push_back(make_pair(a[i], k));
    }
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(b, b + m, a[i]) - b;
    update(pos);
    for (int j = 0; j < (int(g[i].size())); ++j) {
      int ind = lower_bound(b, b + m, g[i][j].first) - b;
      int t = 0;
      if (ind) t = get(0, ind - 1);
      if (g[i][j].second < 0)
        ans[-g[i][j].second] -= t;
      else
        ans[g[i][j].second] += t;
    }
  }
  for (int i = 1; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}
