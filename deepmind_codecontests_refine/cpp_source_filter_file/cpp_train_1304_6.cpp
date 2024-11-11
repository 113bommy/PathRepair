#include <bits/stdc++.h>
using namespace std;
int n, m;
int pre[300010], nxt[300010], pos[300010], jup[300010];
pair<int, int> f[300010];
set<pair<int, int> > s;
set<pair<int, int> >::iterator it;
int calc(int x, int y) {
  if (x == y) return 0x3f3f3f3f;
  int p1 = pos[x], p2 = pos[y];
  if (x > y) p2 = (p2 + jup[y]) % m;
  int dis = (p2 - p1 + m) % m;
  if (dis <= jup[x]) return 1;
  if (jup[x] <= jup[y]) return 0x3f3f3f3f;
  int s = jup[x] - jup[y];
  return (dis - jup[x] + s - 1) / s;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &pos[i], &jup[i]);
    pos[i]--;
    f[i] = make_pair(pos[i], i);
  }
  sort(f, f + n);
  f[n] = f[0];
  for (int i = 0; i < n; ++i) {
    nxt[f[i].second] = f[i + 1].second;
    pre[f[i + 1].second] = f[i].second;
  }
  for (int i = 0; i < n; ++i) s.insert(make_pair(calc(i, nxt[i]), i));
  while (!s.empty()) {
    pair<int, int> tmp = *s.begin();
    int t = tmp.first, id = tmp.second, nid = nxt[id];
    if (t == 0x3f3f3f3f) break;
    s.erase(tmp);
    s.erase(make_pair(calc(nid, nxt[nid]), nid));
    s.erase(make_pair(calc(pre[id], id), pre[id]));
    pos[id] += t, jup[id]--;
    nxt[id] = nxt[nid], pre[nxt[nid]] = id;
    s.insert(make_pair(calc(pre[id], id), pre[id]));
    s.insert(make_pair(calc(id, nxt[id]), id));
  }
  printf("%d\n", (int)s.size());
  for (it = s.begin(); it != s.end(); ++it) printf("%d ", (*it).second + 1);
  puts("");
  return 0;
}
