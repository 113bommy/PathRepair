#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100000 + 10;
struct Datas {
  int id, val;
  bool operator<(const Datas &b) const { return val > b.val; }
};
struct Datab {
  int id, val;
  bool operator<(const Datab &b) const { return val < b.val; }
};
priority_queue<Datas> qs;
priority_queue<Datab> qb;
bool vis[MaxN];
int n, dgree[MaxN];
struct Pos {
  int x, y, val;
  Pos(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const Pos &b) const {
    return x < b.x || (x == b.x && y < b.y);
  }
} cbs[MaxN];
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &cbs[i].x, &cbs[i].y);
    cbs[i].val = i - 1;
  }
  sort(cbs + 1, cbs + n + 1);
}
int find(const Pos a) {
  int st = 0, en = n, mid;
  while (st + 1 < en) {
    mid = (st + en) >> 1;
    if (a < cbs[mid])
      en = mid;
    else
      st = mid;
  }
  if (st == 0 || a < cbs[st] || cbs[st] < a) return 0;
  return st;
}
int rbk[MaxN], as[MaxN];
void help(int id) {
  int v1 = find(Pos(cbs[id].x - 1, cbs[id].y - 1)),
      v2 = find(Pos(cbs[id].x, cbs[id].y - 1)),
      v3 = find(Pos(cbs[id].x + 1, cbs[id].y - 1));
  ++rbk[v1 * (!vis[v1]) + v2 * (!vis[v2]) + v3 * (!vis[v3])];
}
void add(int id) {
  int v1 = find(Pos(cbs[id].x - 1, cbs[id].y - 1)),
      v2 = find(Pos(cbs[id].x, cbs[id].y - 1)),
      v3 = find(Pos(cbs[id].x + 1, cbs[id].y - 1));
  v1 = v1 * (!vis[v1]) + v2 * (!vis[v2]) + v3 * (!vis[v3]);
  --rbk[v1];
  if (!rbk[v1]) {
    qs.push((Datas){v1, cbs[v1].val});
    qb.push((Datab){v1, cbs[v1].val});
  }
}
void del(int id) {
  vis[id] = true;
  int v;
  if ((v = find(Pos(cbs[id].x - 1, cbs[id].y + 1))) && !vis[v]) {
    --dgree[v];
    if (dgree[v] == 1) help(v);
  }
  if ((v = find(Pos(cbs[id].x, cbs[id].y + 1))) && !vis[v]) {
    --dgree[v];
    if (dgree[v] == 1) help(v);
  }
  if ((v = find(Pos(cbs[id].x + 1, cbs[id].y + 1))) && !vis[v]) {
    --dgree[v];
    if (dgree[v] == 1) help(v);
  }
  if (dgree[id] == 1) add(id);
}
void solve() {
  Datas s;
  Datab b;
  bool out = false;
  while (!out) {
    do {
      if (qb.empty()) {
        out = true;
        break;
      }
      b = qb.top();
      qb.pop();
    } while (rbk[b.id] || vis[b.id]);
    if (out) break;
    as[++as[0]] = b.val;
    del(b.id);
    do {
      if (qs.empty()) {
        out = true;
        break;
      }
      s = qs.top();
      qs.pop();
    } while (rbk[s.id] || vis[s.id]);
    if (out) break;
    as[++as[0]] = s.val;
    del(s.id);
  }
}
long long ans = 0;
const int Mod = 1e9 + 9;
int main() {
  init();
  int v1, v2, v3;
  for (int i = 1; i <= n; ++i)
    if (cbs[i].y > 0) {
      if (v1 = find(Pos(cbs[i].x - 1, cbs[i].y - 1))) ++dgree[i];
      if (v2 = find(Pos(cbs[i].x, cbs[i].y - 1))) ++dgree[i];
      if (v3 = find(Pos(cbs[i].x + 1, cbs[i].y - 1))) ++dgree[i];
      if (dgree[i] == 1) ++rbk[v1 ^ v2 ^ v3];
    } else
      dgree[i] = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i)
    if (!rbk[i]) {
      qs.push((Datas){i, cbs[i].val});
      qb.push((Datab){i, cbs[i].val});
    }
  solve();
  for (int i = 1; i <= as[0]; ++i)
    ans = ((long long)ans * (long long)n + (long long)as[i]) % (long long)Mod;
  cout << ans;
  return 0;
}
