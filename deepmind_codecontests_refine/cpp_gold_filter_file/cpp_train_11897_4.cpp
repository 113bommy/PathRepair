#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int N;
pair<int, int> point[MAXN];
int cntx[MAXN], cnty[MAXN], cnt1, cnt2;
map<int, vector<pair<int, int> > > samex, samey;
int fa[MAXN];
int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }
void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u != v) fa[u] = v;
}
bool check(long long dis) {
  for (int i = 1; i <= N; i++) fa[i] = i;
  for (int i = 1; i <= cnt1; i++) {
    for (int j = 1; j < samex[cntx[i]].size(); j++) {
      int id1 = samex[cntx[i]][j - 1].second;
      int id2 = samex[cntx[i]][j].second;
      if (point[id2].second - point[id1].second <= dis) merge(id1, id2);
    }
  }
  for (int i = 1; i <= cnt2; i++) {
    for (int j = 1; j < samey[cnty[i]].size(); j++) {
      int id1 = samey[cnty[i]][j - 1].second;
      int id2 = samey[cnty[i]][j].second;
      if (point[id2].first - point[id1].first <= dis) merge(id1, id2);
    }
  }
  int num = 0;
  for (int i = 1; i <= N; i++) num += (i == find(i));
  if (num > 4) return false;
  if (num == 1) return true;
  if (num == 2) {
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++)
        if (fa[i] != fa[j]) {
          if (point[i].first == point[j].first &&
              abs(point[i].second - point[j].second) <= dis * 2)
            return true;
          if (point[i].second == point[j].second &&
              abs(point[i].first - point[j].first) <= dis * 2)
            return true;
          if (abs(point[i].first - point[j].first) <= dis &&
              abs(point[i].second - point[j].second) <= dis)
            return true;
        }
    }
  } else if (num == 3) {
    vector<pair<int, int> > seg;
    for (int i = 1; i <= cnt1; i++) {
      for (int j = 1; j < (int)samex[cntx[i]].size(); j++) {
        int id1 = samex[cntx[i]][j - 1].second;
        int id2 = samex[cntx[i]][j].second;
        if (fa[id1] != fa[id2]) {
          seg.push_back(make_pair(id1, id2));
        }
      }
    }
    for (int i = 1; i <= cnt2; i++) {
      for (int j = 1; j < (int)samey[cnty[i]].size(); j++) {
        int id1 = samey[cnty[i]][j - 1].second;
        int id2 = samey[cnty[i]][j].second;
        if (fa[id1] != fa[id2]) {
          seg.push_back(make_pair(id1, id2));
        }
      }
    }
    for (int i = 0; i < (int)seg.size(); i++) {
      int id1 = seg[i].first;
      int id2 = seg[i].second;
      for (int j = 1; j <= N; j++)
        if (fa[id1] != fa[j] && fa[id2] != fa[j]) {
          if (point[id1].first == point[id2].first) {
            if (min(point[id1].second, point[id2].second) >= point[j].second ||
                max(point[id1].second, point[id2].second) <= point[j].second)
              continue;
            if (abs(point[j].first - point[id1].first) <= dis &&
                abs(point[id1].second - point[j].second) <= dis &&
                abs(point[id2].second - point[j].second) <= dis)
              return true;
          } else {
            if (min(point[id1].first, point[id2].first) >= point[j].first ||
                max(point[id1].first, point[id2].first) <= point[j].first)
              continue;
            if (abs(point[j].first - point[id1].first) <= dis &&
                abs(point[id1].second - point[j].second) <= dis &&
                abs(point[j].first - point[id2].first) <= dis)
              return true;
          }
        }
    }
  } else {
    vector<pair<int, int> > segx, segy;
    for (int i = 1; i <= cnt1; i++) {
      for (int j = 1; j < (int)samex[cntx[i]].size(); j++) {
        int id1 = samex[cntx[i]][j - 1].second;
        int id2 = samex[cntx[i]][j].second;
        if (fa[id1] != fa[id2]) segx.push_back(make_pair(id1, id2));
      }
    }
    for (int i = 1; i <= cnt2; i++) {
      for (int j = 1; j < (int)samey[cnty[i]].size(); j++) {
        int id1 = samey[cnty[i]][j - 1].second;
        int id2 = samey[cnty[i]][j].second;
        if (fa[id1] != fa[id2]) segy.push_back(make_pair(id1, id2));
      }
    }
    for (int i = 0; i < (int)segx.size(); i++) {
      for (int j = 0; j < (int)segy.size(); j++) {
        int x1 = segx[i].first;
        int y1 = segx[i].second;
        int x2 = segy[j].first;
        int y2 = segy[j].second;
        if (fa[x1] == fa[x2] || fa[x1] == fa[y2] || fa[y1] == fa[x2] ||
            fa[y1] == fa[y2])
          continue;
        if (min(point[x2].first, point[y2].first) >= point[x1].first ||
            max(point[x2].first, point[y2].first) <= point[x1].first)
          continue;
        if (min(point[x1].second, point[y1].second) >= point[x2].second ||
            max(point[x1].second, point[y1].second) <= point[x2].second)
          continue;
        if (abs(point[x2].first - point[x1].first) <= dis &&
            abs(point[y2].first - point[x1].first) <= dis &&
            abs(point[x1].second - point[x2].second) <= dis &&
            abs(point[y1].second - point[x2].second) <= dis)
          return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d", &N);
  cnt1 = cnt2 = 0;
  for (int i = 1, x, y; i <= N; i++) {
    scanf("%d%d", &x, &y);
    point[i] = make_pair(x, y);
    cntx[++cnt1] = x;
    cnty[++cnt2] = y;
    samex[x].push_back(make_pair(y, i));
    samey[y].push_back(make_pair(x, i));
  }
  sort(cntx + 1, cntx + 1 + cnt1);
  sort(cnty + 1, cnty + 1 + cnt2);
  cnt1 = unique(cntx + 1, cntx + 1 + cnt1) - (cntx + 1);
  cnt2 = unique(cnty + 1, cnty + 1 + cnt2) - (cnty + 1);
  for (int i = 1; i <= cnt1; i++)
    sort(samex[cntx[i]].begin(), samex[cntx[i]].end());
  for (int i = 1; i <= cnt2; i++)
    sort(samey[cnty[i]].begin(), samey[cnty[i]].end());
  long long l = 0;
  long long r = 2e9;
  long long ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}
