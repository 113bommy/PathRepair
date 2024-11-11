#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long mo = (long long)1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 1e5 + 100;
int dep[MAXN], st, ed, vis[MAXN];
int n, k, x, y, val;
struct node {
  int t, val;
} fa[MAXN];
vector<node> v[MAXN];
int bfs(int pos) {
  fa[pos].t = pos;
  dep[pos] = 1;
  queue<node> qwq;
  qwq.push({pos, 0});
  vis[pos] = 1;
  node cur, nt, res;
  res.val = 0, res.t = pos;
  while (!qwq.empty()) {
    cur = qwq.front();
    qwq.pop();
    for (int i = 0; i < v[cur.t].size(); i++) {
      nt = v[cur.t][i];
      nt.val += cur.val;
      if (!vis[nt.t]) {
        vis[nt.t] = 1;
        dep[nt.t] = dep[cur.t] + 1;
        fa[nt.t] = {cur.t, v[cur.t][i].val};
        qwq.push(nt);
        if (nt.val > res.val) {
          res = nt;
        }
      }
    }
  }
  return res.t;
}
int has[MAXN];
struct Q {
  int pos, val;
  bool operator<(const Q xx) const { return val > xx.val; }
};
void bfss(vector<int> p, int maxdis) {
  priority_queue<Q> qwq;
  for (int i = 0; i < p.size(); i++) {
    qwq.push({p[i], 0});
    has[p[i]] = 1;
  }
  Q cur, nt;
  while (!qwq.empty()) {
    cur = qwq.top();
    qwq.pop();
    for (int i = 0; i < v[cur.pos].size(); i++) {
      nt.pos = v[cur.pos][i].t;
      nt.val = cur.val + v[cur.pos][i].val;
      if (!has[nt.pos] && nt.val <= maxdis) {
        has[nt.pos] = 1;
        qwq.push(nt);
      }
    }
  }
}
bool check(int maxdis) {
  for (int i = 1; i <= n; i++) vis[i] = 0;
  int curpos = bfs(1);
  int tmp = maxdis;
  while (tmp >= fa[curpos].val && fa[curpos].t != curpos) {
    tmp -= fa[curpos].val;
    curpos = fa[curpos].t;
  }
  st = curpos;
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 0; i < v[st].size(); i++) {
    if (dep[v[st][i].t] > dep[st]) {
      vis[v[st][i].t] = 1;
    }
  }
  curpos = bfs(st);
  tmp = maxdis;
  while (tmp >= fa[curpos].val && fa[curpos].t != curpos) {
    tmp -= fa[curpos].val;
    curpos = fa[curpos].t;
  }
  ed = curpos;
  if (dep[ed] - dep[st] + 1 <= k) {
    for (int i = 1; i <= n; i++) {
      has[i] = 0;
    }
    int cur = ed;
    vector<int> qwq;
    while (true) {
      qwq.push_back(cur);
      if (cur == st) break;
      cur = fa[cur].t;
    }
    bfss(qwq, maxdis);
    for (int i = 1; i <= n; i++) {
      if (!has[i]) {
        return false;
      }
    }
    return true;
  } else
    return false;
}
void work() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    cin >> x >> y >> val;
    v[x].push_back({y, val});
    v[y].push_back({x, val});
  }
  int l = 0, r = 1e9, ans = -1, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (ans == -1) {
    while (true)
      ;
    cout << "error!\n";
  } else {
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  work();
  return 0;
}
