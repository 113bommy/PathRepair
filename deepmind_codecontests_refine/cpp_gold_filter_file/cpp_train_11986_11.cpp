#include <bits/stdc++.h>
const int N = 1e5;
using namespace std;
int n, T, a[N + 5], k, sm, ans, vis[N + 5], f[N + 5], len, p[N + 5], g[N + 5];
vector<int> d[N + 5];
vector<int>::iterator it;
set<pair<int, int> > s;
set<pair<int, int> >::iterator itt;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) d[i].clear();
    ans = 0;
    k = 0;
    while (k * (k + 1) / 2 < n) k++;
    sm = n;
    len = 0;
    f[++len] = a[1];
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i] > f[len])
        f[++len] = a[i], g[i] = len;
      else {
        int pos = lower_bound(f + 1, f + len + 1, a[i]) - f;
        f[pos] = a[i];
        g[i] = pos;
      }
    }
    while (len >= k && sm) {
      ans++;
      k--;
      sm -= len;
      for (int i = n; i >= 1 && len; i--) {
        if (vis[i]) continue;
        if (g[i] == len) vis[i] = 1, d[ans].push_back(a[i]), len--;
      }
      reverse(d[ans].begin(), d[ans].end());
      len = 0;
      int st = 1;
      while (vis[st]) st++;
      f[++len] = a[st];
      g[st] = 1;
      for (int i = st + 1; i <= n; i++) {
        if (vis[i]) continue;
        if (a[i] > f[len])
          f[++len] = a[i], g[i] = len;
        else {
          int pos = lower_bound(f + 1, f + len + 1, a[i]) - f;
          f[pos] = a[i];
          g[i] = pos;
        }
      }
    }
    s.clear();
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      itt = s.lower_bound(make_pair(a[i], 0));
      if (itt == s.end()) {
        ans++;
        s.insert(make_pair(a[i], ans));
        d[ans].push_back(a[i]);
      } else {
        pair<int, int> t = *(itt);
        s.erase(t);
        d[t.second].push_back(a[i]);
        s.insert(make_pair(a[i], t.second));
      }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++) {
      printf("%d ", d[i].size());
      for (it = d[i].begin(); it != d[i].end(); it++) {
        int v = *it;
        printf("%d ", v);
      }
      printf("\n");
    }
  }
  return 0;
}
