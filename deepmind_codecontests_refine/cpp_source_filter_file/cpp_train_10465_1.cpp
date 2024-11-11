#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 3005;
long long ans;
int num, r, flag[N], c, n, m, x, y, ne[N][11], cnt[N];
vector<int> v[N];
set<int> S;
int cmp(int x, int y) { return x > y; }
void update(int x, int t, int z) {
  for (int i = z; i <= m; i++)
    if (i <= cnt[x])
      ne[x][i] = r - x + 1;
    else
      ne[x][i] = ne[t][i - cnt[x]];
}
int main() {
  scanf("%d%d%d%d", &r, &c, &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= c; i++) sort(v[i].begin(), v[i].end(), cmp);
  for (int i = 1; i <= c; i++) {
    memset(cnt, 0, sizeof cnt);
    memset(ne, 0, sizeof ne);
    memset(flag, 0, sizeof flag);
    num = 0;
    S.clear();
    S.insert(0);
    S.insert(r + 1);
    for (int j = i; j <= c; j++) {
      for (int k = 0; k < v[j].size(); k++) {
        int now = v[j][k];
        cnt[now]++;
        if (cnt[now] > m) continue;
        int vv = 0;
        if (!flag[now]) S.insert(now);
        set<int>::iterator iter = S.lower_bound(now);
        int vvv = now, nxt = *S.upper_bound(now);
        while (vv < m && vv != 0) {
          int delta1 = -ne[vvv][m], delta2 = vvv;
          if (cnt[vvv] == 1 && now == vvv) delta1 = -ne[nxt][m];
          update(vvv, nxt, vv + 1);
          delta1 += ne[vvv][m];
          nxt = vvv;
          iter--;
          vvv = *iter;
          delta2 -= vvv;
          num += delta2 * delta1;
          vv += cnt[vvv];
        }
      }
      ans += num;
    }
  }
  printf("%lld\n", ans);
}
