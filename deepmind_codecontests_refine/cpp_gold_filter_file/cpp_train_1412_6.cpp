#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
vector<pair<int, int> > mp[10035];
int lev[10035], N;
int cutid[10035], bcc[10035], ccnt, bcnt;
vector<int> vb[10035];
stack<int> s;
int tarjan(int x, int f, int l) {
  int low;
  lev[x] = low = l;
  s.push(x);
  int iscut = 0, son = 0;
  for (auto z : mp[x])
    if (z.first != f) {
      int i = z.first;
      if (lev[i] != -1) {
        low = min(low, lev[i]);
        continue;
      }
      son++;
      int tmp = tarjan(i, x, l + 1);
      low = min(low, tmp);
      if (tmp >= l) {
        iscut = 1;
        bcnt++;
        int top;
        do {
          bcc[top = s.top()] = bcnt;
          vb[bcnt].push_back(top);
          s.pop();
        } while (top != i);
        bcc[x] = bcnt;
        vb[bcnt].push_back(x);
      }
    }
  if ((x != f && iscut) || (x == f && son > 1)) cutid[x] = ++ccnt;
  return low;
}
map<pair<int, int>, int> mpc;
map<int, int> cid;
int cnt;
int gc(int u, int v) { return mpc[{min(u, v), max(u, v)}]; }
class MaxFlow {
 public:
  int cap[100000], flow[100000];
  int to[100000], prev[100000], last[30000], used[30000], level[30000];
  int V, E;
  MaxFlow(int n) {
    V = n;
    E = 0;
    for (int(i) = 0; (i) < (int)(V); (i)++) last[i] = -1;
  }
  void add_edge(int x, int y, int f) {
    cap[E] = f;
    flow[E] = 0;
    to[E] = y;
    prev[E] = last[x];
    last[x] = E;
    E++;
    cap[E] = 0;
    flow[E] = 0;
    to[E] = x;
    prev[E] = last[y];
    last[y] = E;
    E++;
  }
  bool bfs(int s, int t) {
    int i;
    for (int(i) = 0; (i) < (int)(V); (i)++) level[i] = -1;
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (i = last[x]; i >= 0; i = prev[i])
        if (level[to[i]] == -1 && cap[i] > flow[i]) {
          q.push(to[i]);
          level[to[i]] = level[x] + 1;
        }
    }
    return (level[t] != -1);
  }
  int dfs(int v, int t, int f) {
    int i;
    if (v == t) return f;
    for (i = used[v]; i >= 0; used[v] = i = prev[i])
      if (level[to[i]] > level[v] && cap[i] > flow[i]) {
        int tmp = dfs(to[i], t, min(f, cap[i] - flow[i]));
        if (tmp > 0) {
          flow[i] += tmp;
          flow[i ^ 1] -= tmp;
          return tmp;
        }
      }
    return 0;
  }
  vector<pair<int, int> > positive_edges() {
    vector<pair<int, int> > ans;
    for (int(i) = 0; (i) < (int)(V); (i)++)
      for (int j = last[i]; j >= 0; j = prev[j])
        if (cap[j] - flow[j] > 0) ans.push_back(make_pair(i, to[j]));
    return ans;
  }
  int maxflow(int s, int t) {
    while (bfs(s, t)) {
      for (int(i) = 0; (i) < (int)(V); (i)++) used[i] = last[i];
      while (dfs(s, t, (1 << 29)) != 0)
        ;
    }
    int ans = 0;
    for (int i = last[s]; i >= 0; i = prev[i]) ans += flow[i];
    return ans;
  }
};
void fmain() {
  scanf("%d%d", &n, &m);
  for (int i = 0, u, v, c; i < m; i++) {
    scanf("%d%d%d", &u, &v, &c);
    mp[u].push_back({v, c});
    mp[v].push_back({u, c});
    cid[c];
    mpc[{min(u, v), max(u, v)}] = c;
  }
  for (auto &p : cid) p.second = ++cnt;
  memset(lev, -1, sizeof lev);
  tarjan(1, 0, 0);
  MaxFlow mf = MaxFlow(2 + cnt + bcnt);
  int S = 0, T = 2 + cnt + bcnt - 1;
  for (int(i) = 1; (i) <= (int)(bcnt); (i)++)
    if (vb[i].size() > 2) {
      int N = vb[i].size();
      for (int(j) = 0; (j) < (int)(N); (j)++) {
        int z = gc(vb[i][j], vb[i][(j + 1) % N]);
        mf.add_edge(i, bcnt + cid[z], 1);
      }
      mf.add_edge(S, i, N - 1);
    } else {
      int z = gc(vb[i][0], vb[i][1]);
      mf.add_edge(S, i, 1);
      mf.add_edge(i, bcnt + cid[z], 1);
    }
  for (int(i) = 1; (i) <= (int)(cnt); (i)++) {
    mf.add_edge(bcnt + i, T, 1);
  }
  printf("%d\n", mf.maxflow(S, T));
}
int main() {
  fmain();
  return 0;
}
