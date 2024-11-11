#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2e9;
const long long INFLL = 1e18;
const int MAX_N = 100000;
int mx, my, mz, N, M, Q;
struct S {
  int x, y, z;
};
pair<S, S> r;
struct Upd {
  int x;
  int y1, z1, y2, z2;
  int type;
  bool operator<(const Upd &a) const { return x < a.x; }
};
vector<Upd> upd;
struct Query {
  int x, y, z;
  int idx;
  bool operator<(const Query &a) const { return x < a.x; }
};
vector<Query> query;
int ans[MAX_N + 1];
struct SEG1 {
  struct NODE {
    int l, r;
    int sum;
  };
  vector<NODE> seg;
  int SZ;
  void add() { seg.push_back({-1, -1, 0}); }
  void Init(int x) {
    SZ = x;
    add();
  }
  void Update(int x, int y, int z) { update(0, 1, SZ, x, y, z); }
  void update(int idx, int s, int e, int x, int y, int z) {
    if (x <= s && e <= y) {
      seg[idx].sum += z;
      return;
    }
    if (x > e || y < s) return;
    if (seg[idx].l == -1) {
      seg[idx].l = seg.size();
      add();
    }
    if (seg[idx].r == -1) {
      seg[idx].r = seg.size();
      add();
    }
    update(seg[idx].l, s, (s + e) / 2, x, y, z);
    update(seg[idx].r, (s + e) / 2 + 1, e, x, y, z);
  }
  bool Calc(int x) { return calc(0, 1, SZ, x); }
  bool calc(int idx, int s, int e, int k) {
    if (idx == -1) return false;
    if (seg[idx].sum > 0) return true;
    if (s == e) return false;
    if (k <= (s + e) / 2) {
      return calc(seg[idx].l, s, (s + e) / 2, k);
    } else {
      return calc(seg[idx].r, (s + e) / 2 + 1, e, k);
    }
  }
} S1;
vector<SEG1> Seg1;
struct SEG2 {
  struct NODE2 {
    int l, r;
    int d;
  };
  vector<NODE2> seg;
  int SZ;
  void add() { seg.push_back({-1, -1, -1}); }
  void Init(int x) {
    SZ = x;
    add();
  }
  int y1, y2;
  void Update(int x1, int x2, int y11, int y12, int z) {
    y1 = y11;
    y2 = y12;
    update(0, 1, SZ, x1, x2, z);
  }
  void update(int idx, int s, int e, int x, int y, int z) {
    if (x <= s && e <= y) {
      if (seg[idx].d == -1) {
        seg[idx].d = Seg1.size();
        Seg1.push_back(S1);
        Seg1[seg[idx].d].Init(mz);
      }
      Seg1[seg[idx].d].Update(y1, y2, z);
      return;
    }
    if (x > e || y < s) return;
    if (seg[idx].l == -1) {
      seg[idx].l = seg.size();
      add();
    }
    if (seg[idx].r == -1) {
      seg[idx].r = seg.size();
      add();
    }
    update(seg[idx].l, s, (s + e) / 2, x, y, z);
    update(seg[idx].r, (s + e) / 2 + 1, e, x, y, z);
  }
  bool Calc(int x, int y) { return calc(0, 1, SZ, x, y); }
  bool calc(int idx, int s, int e, int x, int y) {
    if (idx == -1) return false;
    if (seg[idx].d != -1) {
      if (Seg1[seg[idx].d].Calc(y)) return true;
    }
    if (s == e) return false;
    if (x <= (s + e) / 2) {
      return calc(seg[idx].l, s, (s + e) / 2, x, y);
    } else {
      return calc(seg[idx].r, (s + e) / 2 + 1, e, x, y);
    }
  }
} Seg;
int main() {
  scanf("%d%d%d%d%d%d", &mx, &my, &mz, &N, &M, &Q);
  r.first = {mx, my, mz};
  r.second = {1, 1, 1};
  for (int i = 0; i < N; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    r.first.x = min(r.first.x, x);
    r.first.y = min(r.first.y, y);
    r.first.z = min(r.first.z, z);
    r.second.x = max(r.second.x, x);
    r.second.y = max(r.second.y, y);
    r.second.z = max(r.second.z, z);
  }
  for (int i = 0; i < M; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (r.first.x <= x && x <= r.second.x && r.first.y <= y &&
        y <= r.second.y && r.first.z <= z && z <= r.second.z) {
      printf("INCORRECT");
      return 0;
    }
    S s, e;
    if (x < r.first.x) {
      s.x = 1;
      e.x = x;
    } else if (x > r.second.x) {
      s.x = x;
      e.x = mx;
    } else {
      s.x = 1;
      e.x = mx;
    }
    if (y < r.first.y) {
      s.y = 1;
      e.y = y;
    } else if (y > r.second.y) {
      s.y = y;
      e.y = my;
    } else {
      s.y = 1;
      e.y = my;
    }
    if (z < r.first.z) {
      s.z = 1;
      e.z = z;
    } else if (z > r.second.z) {
      s.z = z;
      e.z = mz;
    } else {
      s.z = 1;
      e.z = mz;
    }
    upd.push_back({s.x, s.y, s.z, e.y, e.z, 1});
    upd.push_back({e.x + 1, s.y, s.z, e.y, e.z, -1});
  }
  Seg.Init(my);
  printf("CORRECT\n");
  for (int i = 0; i < Q; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (r.first.x <= x && x <= r.second.x && r.first.y <= y &&
        y <= r.second.y && r.first.z <= z && z <= r.second.z) {
      ans[i] = 1;
      continue;
    }
    query.push_back({x, y, z, i});
  }
  sort(query.begin(), query.end());
  sort(upd.begin(), upd.end());
  int idx = 0;
  for (int i = 0; i < query.size(); i++) {
    Query now = query[i];
    while (idx < upd.size() && upd[idx].x <= now.x) {
      Seg.Update(upd[idx].y1, upd[idx].y2, upd[idx].z1, upd[idx].z2,
                 upd[idx].type);
      idx++;
    }
    if (Seg.Calc(now.y, now.z)) {
      ans[now.idx] = 2;
    }
  }
  for (int i = 0; i < Q; i++) {
    if (ans[i] == 1) {
      printf("OPEN\n");
    } else if (ans[i] == 2) {
      printf("CLOSED\n");
    } else {
      printf("UNKNOWN\n");
    }
  }
  return 0;
}
