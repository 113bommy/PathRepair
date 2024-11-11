#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k;
template <class T>
struct Dinic {
  const static int N = 2020, M = N * 10;
  int s, t, n, h[N], cur[N], lv[N], q[N], e, ne[M], to[M];
  T cap[M], flow;
  void liu(int u, int v, T w) {
    to[e] = v, ne[e] = h[u];
    cap[e] = w;
    h[u] = e++;
  }
  void link(int u, int v, T w) { liu(u, v, w), liu(v, u, 0); }
  void ini(int _n = N) {
    fill(h, h + (n = _n), -1);
    e = 0;
  }
  bool bfs() {
    int L = 0, R = 0;
    fill(lv, lv + n, -1);
    lv[q[R++] = s] = 0;
    while (L < R && !~lv[t]) {
      int c = q[L++];
      for (int k = h[c]; ~k; k = ne[k])
        if (cap[k] > 0 && !~lv[to[k]]) lv[q[R++] = to[k]] = lv[c] + 1;
    }
    return ~lv[t];
  }
  T dfs(int c, T mx) {
    if (c == t) return mx;
    T ret = 0;
    for (int &k = cur[c]; ~k; k = ne[k]) {
      if (lv[to[k]] == lv[c] + 1 && cap[k] > 0) {
        T flow = dfs(to[k], min(mx, cap[k]));
        ret += flow;
        cap[k] -= flow, cap[k ^ 1] += flow;
        mx -= flow;
        if (!mx) return ret;
      }
    }
    lv[c] = -1;
    return ret;
  }
  T run(int _s, int _t) {
    s = _s, t = _t;
    flow = 0;
    while (bfs()) {
      copy(h, h + n, cur);
      flow += dfs(s, ~0U >> 1);
    }
    return flow;
  }
};
Dinic<int> flow;
int in[N], u[N], v[N], c[N];
vector<int> ans[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    for (int i = (1); i < (n + 1); i++) in[i] = 0, ans[i].clear();
    for (int i = (1); i < (m + 1); i++) c[i] = 0;
    flow.ini(n + m + 10);
    int s = n + m + 2, t = n + m + 3;
    for (int i = (1); i < (m + 1); i++) {
      cin >> u[i] >> v[i];
      in[u[i]]++, in[v[i]]++;
    }
    int ct = 0, le = 0, sum = 0;
    for (int i = (1); i < (n + 1); i++) {
      int c = 2 * (in[i] - k);
      if (in[i] > k) le++;
      if (c > in[i]) {
        ct++;
        break;
      }
      c = max(c, 0);
      sum += c;
      flow.link(m + i, t, c);
    }
    if (ct) {
      for (int i = (1); i < (m + 1); i++) cout << 0 << " ";
      cout << "\n";
      continue;
    }
    if (!le) {
      for (int i = (1); i < (m + 1); i++) cout << i << " ";
      cout << "\n";
      continue;
    }
    for (int i = (1); i < (m + 1); i++) {
      flow.link(i, u[i] + m, 1);
      flow.link(i, v[i] + m, 1);
      flow.link(s, i, 1);
    }
    int res = flow.run(s, t);
    if (res == sum) {
      int tot = 0;
      for (int i = (1); i < (m + 1); i++) {
        for (int k = flow.h[i]; ~k; k = flow.ne[k]) {
          if (flow.to[k] != s && flow.cap[k] == 0) {
            ans[flow.to[k] - m].push_back(i);
            break;
          }
        }
      }
      for (int i = (1); i < (n + 1); i++) {
        for (int j = 0; j < (int)ans[i].size(); j += 2) {
          c[ans[i][j]] = c[ans[i][j + 1]] = ++tot;
        }
      }
      for (int i = (1); i < (m + 1); i++) {
        if (!c[i]) c[i] = ++tot;
        cout << c[i] << " ";
      }
      cout << "\n";
    } else {
      for (int i = (1); i < (m + 1); i++) cout << 0 << " ";
      cout << "\n";
    }
  }
  return 0;
}
