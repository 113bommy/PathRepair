#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long inf64 = 1e18;
const int N = 2e5 + 5;
struct Query {
  int t, x, y;
};
int n, m;
Query qs[N];
int color[N], used[N], cur_used = 10;
unordered_set<int> g[N];
unordered_multiset<int> h[N];
int qq[4 * N], ql, qr;
void read() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> qs[i].t >> qs[i].x >> qs[i].y;
  }
}
void gen() {
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
  n = 2e5;
  m = 2e5;
  for (int i = 0; i < m; i++) {
    qs[i].t = rnd() % 2 + 1;
    qs[i].x = rnd() % (n - 1) + 2;
    qs[i].y = rnd() % (qs[i].x - 1) + 1;
  }
}
vector<int> slow() {
  vector<unordered_set<int>> g(n + 1);
  vector<int> res;
  for (int last = 0, i = 0; i < m; i++) {
    int u = (qs[i].x + last - 1) % n + 1;
    int v = (qs[i].y + last - 1) % n + 1;
    if (qs[i].t == 1) {
      if (g[u].count(v)) {
        g[u].erase(v);
        g[v].erase(u);
      } else {
        g[u].insert(v);
        g[v].insert(u);
      }
    } else {
      vector<int> can(n + 1);
      can[u] = 1;
      queue<int> que;
      que.push(u);
      while (!que.empty()) {
        int w = que.front();
        que.pop();
        for (int to : g[w]) {
          if (!can[to]) {
            can[to] = 1;
            que.push(to);
          }
        }
      }
      last = can[v];
      res.push_back(last);
    }
  }
  return res;
}
vector<int> fast() {
  int bl = 4 * sqrt(m) + 2;
  int LAST = 0;
  vector<int> res;
  for (int v = 1; v <= n; v++) {
    g[v].clear();
    h[v].clear();
  }
  fill(used, used + n + 1, 0);
  cur_used = 10;
  for (int l = 0; l < m; l += bl) {
    int r = min(m - 1, l + bl - 1);
    memset(color, 0, sizeof(int) * (n + 1));
    unordered_set<long long> interesting_edges;
    for (int i = l; i <= r; i++) {
      if (qs[i].t == 2) continue;
      for (int last = 0; last < 2; last++) {
        int u = (qs[i].x + last - 1) % n + 1;
        int v = (qs[i].y + last - 1) % n + 1;
        if (u > v) swap(u, v);
        interesting_edges.insert(1ll * u * (n + 1) + v);
      }
    }
    int cur_color = 0;
    for (int v = 1; v <= n; v++) {
      if (color[v]) continue;
      ql = qr = 0;
      cur_color++;
      qq[qr++] = v;
      h[cur_color].clear();
      color[v] = cur_color;
      while (ql < qr) {
        int u = qq[ql++];
        for (int to : g[u]) {
          long long hash =
              u < to ? 1ll * u * (n + 1) + to : 1ll * to * (n + 1) + u;
          if (interesting_edges.count(hash)) continue;
          if (!color[to]) {
            color[to] = cur_color;
            qq[qr++] = to;
          }
        }
      }
    }
    for (int v = 1; v <= n; v++) {
      for (int to : g[v]) {
        long long hash =
            v < to ? 1ll * v * (n + 1) + to : 1ll * to * (n + 1) + v;
        if (interesting_edges.count(hash)) {
          h[color[v]].insert(color[to]);
        }
      }
    }
    for (int i = l; i <= r; i++) {
      int u = (qs[i].x + LAST - 1) % n + 1;
      int v = (qs[i].y + LAST - 1) % n + 1;
      int uu = u, vv = v;
      u = color[u];
      v = color[v];
      if (qs[i].t == 1) {
        if (g[uu].count(vv)) {
          g[uu].erase(vv);
          g[vv].erase(uu);
          h[u].erase(h[u].find(v));
          h[v].erase(h[v].find(u));
        } else {
          g[uu].insert(vv);
          g[vv].insert(uu);
          h[u].insert(v);
          h[v].insert(u);
        }
      } else {
        cur_used++;
        ql = qr = 0;
        qq[qr++] = u;
        LAST = 0;
        while (ql < qr) {
          int w = qq[ql++];
          if (w == v) {
            LAST = 1;
            break;
          }
          for (int to : h[w]) {
            if (used[to] != cur_used) {
              used[to] = cur_used;
              qq[qr++] = to;
            }
          }
        }
        res.push_back(LAST);
      }
    }
  }
  return res;
}
void WORK() {
  read();
  vector<int> res = fast();
  for (int x : res) {
    cout << x;
  }
  cout << "\n";
}
void TEST() {
  while (1) {
    gen();
    vector<int> sl = slow();
    vector<int> fs = fast();
    if (fs == sl) {
      cout << "OK ( ";
      for (int x : fs) cout << x << " ";
      cout << ")\n";
    } else {
      cout << "WA\n";
      cout << "exp = ";
      for (int x : sl) cout << x << " ";
      cout << ")\n";
      cout << "fnd = ";
      for (int x : fs) cout << x << " ";
      cout << ")\n";
      cout << "\n\n";
      cout << n << " " << m << "\n";
      for (int i = 0; i < m; i++) {
        cout << qs[i].t << " " << qs[i].x << " " << qs[i].y << "\n";
      }
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  WORK();
  return 0;
}
