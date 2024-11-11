#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
string s;
int n, cnts;
struct Edge {
  int u, v, cap, cost;
};
struct MCMF {
  int trace[maxn], inq[maxn], s, t, dist[maxn], ans;
  vector<Edge> e;
  vector<int> vt[maxn];
  void AddEdge(int u, int v, int cap, int cost) {
    vt[u].push_back(e.size());
    e.push_back({u, v, cap, cost});
    vt[v].push_back(e.size());
    e.push_back({v, u, 0, -cost});
  }
  bool SPFA() {
    for (int i = s; i <= t; i++) trace[i] = -1, dist[i] = 1e9, inq[i] = 0;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
      int gau = q.front();
      q.pop();
      inq[gau] = false;
      for (auto i : vt[gau]) {
        if (e[i].cap > 0 && dist[e[i].v] > dist[gau] + e[i].cost) {
          dist[e[i].v] = dist[gau] + e[i].cost;
          trace[e[i].v] = i;
          if (!inq[e[i].v]) {
            inq[e[i].v] = 1;
            q.push(e[i].v);
          }
        }
      }
    }
    return (trace[t] != -1);
  }
  void Update() {
    int Min = 1e9, cc = t;
    while (cc != s) {
      int x = trace[cc];
      Min = min(Min, e[x].cap);
      cc = e[x].u;
    }
    cc = t;
    while (cc != s) {
      int x = trace[cc];
      e[x].cap -= Min;
      e[x ^ 1].cap += Min;
      ans += Min * e[x].cost;
      cc = e[x].u;
    }
  }
  int FindMCMF() {
    while (SPFA()) {
      Update();
    }
    return ans;
  }
} flow;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("test.inp", "r"))
    freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  cin >> n >> s >> cnts;
  for (int i = 1; i <= cnts; i++) {
    string s1;
    int x;
    cin >> s1 >> x;
    for (int j = 0; j < (int)s.length() - s1.length() + 1; j++) {
      bool chk = true;
      for (int k = 0; k < s1.length(); k++) {
        if (s[j + k] != s1[k]) {
          chk = false;
          break;
        }
      }
      if (chk) {
        flow.AddEdge(j + 1, j + 1 + s1.length(), 1, -x);
      }
    }
  }
  for (int i = 1; i <= s.length(); i++) {
    flow.AddEdge(i, i + 1, 1e8, 0);
  }
  int x;
  cin >> x;
  flow.AddEdge(0, 1, x, 0);
  flow.s = 0;
  flow.t = s.length() + 1;
  cout << -flow.FindMCMF();
}
