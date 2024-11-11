#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
int n;
struct Undo_Dsu {
  stack<pair<int, int> > st;
  int fa[N], siz[N];
  void init() {
    while (!st.empty()) st.pop();
    for (int i = 1; i <= 2 * n + 1; i++) fa[i] = i, siz[i] = 1;
  }
  int findroot(int x) { return x == fa[x] ? x : findroot(fa[x]); }
  bool merge(int u, int v) {
    int fax = findroot(u), fay = findroot(v);
    if (fax == fay) return false;
    if (siz[fax] > siz[fay]) swap(fax, fay), swap(u, v);
    fa[fax] = fay, siz[fay] += siz[fax];
    st.push({fax, fay});
    return true;
  }
  void undo() {
    pair<int, int> no = st.top();
    fa[no.first] = no.first;
    siz[no.second] -= siz[no.first];
    st.pop();
  }
} dsu;
int c[N], a[N], b[N], f[N];
map<pair<int, int>, int> mp;
vector<int> vec[N];
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int m, k;
  cin >> n >> m >> k;
  dsu.init();
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
  for (int i = 1; i <= m; i++) {
    if (c[a[i]] == c[b[i]]) {
      int u = dsu.findroot(a[i]), v = dsu.findroot(b[i]);
      if (u == v)
        f[c[a[i]]] = 1;
      else
        dsu.merge(a[i], b[i] + n), dsu.merge(b[i], a[i] + n);
    }
  }
  int type = 0;
  for (int i = 1; i <= m; i++) {
    if (c[a[i]] != c[b[i]] && !f[c[a[i]]] && !f[c[b[i]]] && !f[c[b[i]]]) {
      int lc = c[a[i]], rc = c[b[i]];
      if (lc > rc) swap(lc, rc);
      int id = mp[{lc, rc}];
      if (!id) mp[{lc, rc}] = ++type;
      vec[id].push_back(i);
    }
  }
  long long ans = 0;
  for (auto it : mp) {
    int w = it.second, now = (int)dsu.st.size();
    for (auto x : vec[w]) {
      int uid = a[x], vid = b[x];
      int fau = dsu.findroot(uid), fav = dsu.findroot(vid);
      if (fau == fav) {
        --ans;
        break;
      }
      dsu.merge(uid, vid + n), dsu.merge(vid, uid + n);
    }
    while ((int)dsu.st.size() > now) dsu.undo();
  }
  int cnt = 0;
  for (int i = 1; i <= k; i++)
    if (!f[i]) cnt++;
  ans += 1LL * cnt * (cnt - 1) / 2;
  cout << ans << '\n';
  return 0;
}
