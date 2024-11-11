#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > pere[1111], e[1111 * 2];
int tsize[1111 * 2], fa[1111 * 2], n, mmap[1111 * 2], tmp;
void rebuild(int now, int p) {
  vector<pair<int, int> > son;
  for (int i = 0; i < pere[now].size(); i++) {
    pair<int, int> k = pere[now][i];
    if (k.first != p) rebuild(k.first, now), son.push_back(k);
  }
  for (int i = 0, t = now; i < son.size(); i++) {
    if (i && i + 1 < son.size()) {
      e[n + 1].push_back({t, -1});
      e[t].push_back({n + 1, -1});
      t = ++n;
      mmap[t] = now;
    }
    e[t].push_back({son[i].first, son[i].second});
    e[son[i].first].push_back({t, son[i].second});
  }
}
void dfs(int now, int p) {
  tsize[now] = now <= tmp, fa[now] = p;
  for (pair<int, int> k : e[now])
    if (k.first != p) dfs(k.first, now), tsize[now] += tsize[k.first];
}
int cnt = 1;
void dfs2(int now, int p, int add, int type) {
  for (pair<int, int> &k : e[now])
    if (k.first != p) {
      if (k.second != -1) k.second = (cnt - add) * type, cnt++;
      dfs2(k.first, now, add + max(0, k.second / type), type);
    }
}
int main() {
  int a, b;
  scanf("%d", &n);
  tmp = n;
  for (int i = 1; i < n; i++)
    scanf("%d%d", &a, &b), pere[a].push_back({b, 0}), pere[b].push_back({a, 0});
  rebuild(1, 0);
  dfs(1, 0);
  int maxnum = 0, maxpos = 0;
  for (int i = 1; i < n + 1; i++)
    if (min(tsize[i], tmp - tsize[i]) > maxnum)
      maxnum = min(tsize[i], tmp - tsize[i]), maxpos = i;
  if (tsize[maxpos] < tmp - tsize[maxpos])
    tsize[fa[maxpos]] = tmp - tsize[maxpos], fa[fa[maxpos]] = maxpos,
    maxpos = fa[maxpos];
  dfs2(maxpos, fa[maxpos], 0, 1);
  cnt = 1;
  for (pair<int, int> &k : e[maxpos])
    if (k.first == fa[maxpos] && k.second != -1)
      k.second = tsize[maxpos], cnt++;
  dfs2(fa[maxpos], maxpos, cnt - 1, tsize[maxpos]);
  for (int i = 1; i < tmp + 1; i++) mmap[i] = i;
  for (int i = 1; i < n + 1; i++)
    for (pair<int, int> k : e[i])
      if (k.second > 0) printf("%d %d %d\n", mmap[i], mmap[k.first], k.second);
}
