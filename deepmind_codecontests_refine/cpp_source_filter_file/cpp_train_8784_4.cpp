#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
using ll = long long;
int n, m, k;
ll h;
ll a[N];
int c[N];
ll dist[10005];
bool vis[N];
vector<ll> vp;
void dij() {
  memset(dist, 63, sizeof dist);
  set<pair<ll, int>> st;
  dist[0] = 0;
  st.emplace(0, 0);
  while (st.size()) {
    auto cur = st.begin()->second;
    st.erase(st.begin());
    for (auto x : vp) {
      if (dist[(cur + x) % k] > dist[cur] + x) {
        st.erase({dist[(cur + x) % k], (cur + x) % k});
        dist[(cur + x) % k] = dist[cur] + x;
        st.insert({dist[(cur + x) % k], (cur + x) % k});
      }
    }
  }
}
set<pair<int, int>> cur;
void updSet() {
  cur.clear();
  for (int i = 0; i < n; i++) {
    if (!vis[i] && dist[a[i] % k] <= a[i]) cur.insert({c[i], -i});
  }
}
void upd(int x, int y) {
  if (cur.count({c[x], -x})) {
    cur.erase({c[x], -x});
    c[x] -= y;
    cur.insert({c[x], -x});
  } else
    c[x] -= y;
}
int main() {
  scanf("%lld%d%d%d", &h, &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld%d", a + i, c + i);
    a[i]--;
  }
  vp.push_back(k);
  dij();
  updSet();
  while (m--) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      ll x;
      scanf("%lld", &x);
      vp.push_back(x);
      dij();
      updSet();
    } else if (tp == 2) {
      int x, y;
      scanf("%d%d", &x, &y);
      upd(--x, y);
    } else {
      if (cur.empty())
        puts("0");
      else {
        printf("%lld\n", cur.rbegin()->first);
        vis[-cur.rbegin()->second] = 1;
        cur.erase(*cur.rbegin());
      }
    }
  }
  return 0;
}
