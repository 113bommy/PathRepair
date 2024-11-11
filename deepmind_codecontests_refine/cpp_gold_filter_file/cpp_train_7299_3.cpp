#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000;
const int INF = 1e9 + 1;
int N, M, K;
vector<pair<int, int> > vt[MAX_N + 1];
bool sf(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
struct SEG {
  struct NODE {
    int l, r;
    vector<pair<int, int> > v;
  };
  int SZ;
  vector<NODE> seg;
  void add() { seg.push_back({-1, -1}); }
  void Init(int x) {
    SZ = x;
    add();
    init(0, 1, SZ);
  }
  void init(int idx, int s, int e) {
    if (s == e) {
      for (int j = 0; j < vt[s].size(); j++) {
        seg[idx].v.push_back(vt[s][j]);
      }
      return;
    }
    seg[idx].l = seg.size();
    add();
    seg[idx].r = seg.size();
    add();
    init(seg[idx].l, s, (s + e) / 2);
    init(seg[idx].r, (s + e) / 2 + 1, e);
    int i0 = 0, i1 = 0;
    while (i0 < seg[seg[idx].l].v.size() && i1 < seg[seg[idx].r].v.size()) {
      if (seg[seg[idx].l].v[i0].first < seg[seg[idx].r].v[i1].first) {
        seg[idx].v.push_back(
            {seg[seg[idx].l].v[i0].first,
             max(seg[seg[idx].l].v[i0].second, seg[seg[idx].r].v[i1].second)});
        i0++;
      } else if (seg[seg[idx].l].v[i0].first > seg[seg[idx].r].v[i1].first) {
        seg[idx].v.push_back(
            {seg[seg[idx].r].v[i1].first,
             max(seg[seg[idx].l].v[i0].second, seg[seg[idx].r].v[i1].second)});
        i1++;
      } else {
        seg[idx].v.push_back(
            {seg[seg[idx].l].v[i0].first,
             max(seg[seg[idx].l].v[i0].second, seg[seg[idx].r].v[i1].second)});
        i0++;
        i1++;
      }
    }
    sort(seg[idx].v.begin(), seg[idx].v.end(), sf);
    if (seg[idx].v.empty()) return;
    int mn = seg[idx].v.back().second;
    for (int i = seg[idx].v.size() - 2; i >= 0; i--) {
      if (mn <= seg[idx].v[i].second) {
        seg[idx].v[i] = {INF, INF};
      } else {
        mn = min(mn, seg[idx].v[i].second);
      }
    }
    sort(seg[idx].v.begin(), seg[idx].v.end(), sf);
    while (!seg[idx].v.empty() && seg[idx].v.back().first == INF)
      seg[idx].v.pop_back();
  }
  bool Query(int a, int b, int x, int y) { return query(0, 1, SZ, a, b, x, y); }
  bool query(int idx, int s, int e, int a, int b, int x, int y) {
    if (a > e || b < s) return true;
    if (a <= s && e <= b) {
      if (seg[idx].v.empty()) return false;
      if (seg[idx].v.back().first < x) return false;
      int ss = 0, ee = seg[idx].v.size() - 1, m;
      while (ss < ee) {
        m = (ss + ee) / 2;
        if (seg[idx].v[m].first >= x) {
          ee = m;
        } else {
          ss = m + 1;
        }
      }
      return (y >= seg[idx].v[ss].second);
    }
    return (query(seg[idx].l, s, (s + e) / 2, a, b, x, y) &
            query(seg[idx].r, (s + e) / 2 + 1, e, a, b, x, y));
  }
} Seg;
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= K; i++) {
    int l, r, p;
    scanf("%d%d%d", &l, &r, &p);
    vt[p].push_back({l, r});
  }
  for (int i = 1; i <= N; i++) {
    sort(vt[i].begin(), vt[i].end(), sf);
    if (vt[i].empty()) continue;
    int mn = vt[i].back().second;
    for (int j = vt[i].size() - 2; j >= 0; j--) {
      if (mn <= vt[i][j].second) {
        vt[i][j] = {INF, INF};
      } else {
        mn = min(vt[i][j].second, mn);
      }
    }
    sort(vt[i].begin(), vt[i].end(), sf);
    while (!vt[i].empty() && vt[i].back().first == INF) vt[i].pop_back();
  }
  Seg.Init(N);
  for (int i = 1; i <= M; i++) {
    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);
    if (Seg.Query(a, b, x, y)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
    fflush(stdout);
  }
}
