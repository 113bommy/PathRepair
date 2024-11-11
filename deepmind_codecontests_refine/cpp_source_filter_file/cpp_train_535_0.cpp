#include <bits/stdc++.h>
using namespace std;
template <typename T>
string to_string(const pair<T, T>& pr) {
  return "(" + to_string(pr.first) + "," + to_string(pr.second) + ")";
}
template <typename T>
string to_string(const vector<T>& vc, int w) {
  if (vc.empty()) return "";
  if (w + 1 == vc.size()) return to_string(vc[w]);
  return to_string(vc[w]) + "," + to_string(vc, w + 1);
}
template <typename T>
string to_string(const vector<T>& vc) {
  return "{" + to_string(vc, 0) + "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
class DebugStream {
} LOG;
template <typename T>
DebugStream& operator<<(DebugStream& s, const T&) {
  return s;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 5.5e3 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20,
          bs = 29;
int cap[maxN][maxN], ff[maxN][maxN], n, m, k, c, d, taim;
vector<int> adj[maxN];
int id(int t, int nd) { return t * n + nd + 1; }
void addEdge(int a, int b, int cp) {
  if (!ff[a][b]) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a][b] = cp;
  }
  ff[a][b]++;
  ff[b][a]++;
}
inline bool hasCap(int a, int b) {
  if (!a || !b || a % n == b % n) return cap[a][b] > 0;
  if (a > b) return cap[b][a] < 0;
  return true;
}
int cln(int a, int b) { return (a + b - 1) / b; }
inline int getCost(int a, int b) {
  if (!a || !b) return 0;
  if (a % n == b % n) {
    if ((a - 1) % n == 0) return 0;
    return (a < b ? c : -c);
  }
  if (a > b) return (-cln(abs(cap[b][a]), ff[b][a]) * 2 + 1) * d - c;
  return (abs(cap[a][b]) / ff[a][b] * 2 + 1) * d + c;
}
const int INF = 1e9;
void shortest_paths(vector<int>& d, vector<int>& p) {
  d.assign(taim * n + 1, INF);
  d[0] = 0;
  vector<bool> inq(taim * n + 1, false);
  queue<int> q;
  q.push(0);
  p.assign(taim * n + 1, -1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (int v : adj[u]) {
      if (hasCap(u, v) && d[v] > d[u] + getCost(u, v)) {
        d[v] = d[u] + getCost(u, v);
        p[v] = u;
        if (!inq[v]) {
          inq[v] = true;
          q.push(v);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> c >> d;
  taim = n * 2 + 1;
  vector<int> frq(n);
  for (int i = 0, inp; i < k; i++) {
    cin >> inp;
    inp--;
    frq[inp]++;
  }
  for (int i = 0; i < n; i++)
    if (frq[i]) addEdge(0, id(0, i), frq[i]);
  for (int t = 0; t + 1 < taim; t++)
    for (int j = 0; j < n; j++) addEdge(id(t, j), id(t + 1, j), k);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    for (int t = 0; t + 1 < taim; t++) {
      addEdge(id(t, u), id(t + 1, v), 0);
      addEdge(id(t, v), id(t + 1, u), 0);
    }
  }
  vector<int> d, p;
  int ans = 0, trg = id(taim - 1, 0);
  42;
  for (int u = 0; u < k; u++) {
    shortest_paths(d, p);
    assert(d[trg] != INF);
    ans += d[trg];
    for (int cur = trg; cur != 0; cur = p[cur]) {
      cap[p[cur]][cur]--;
      cap[cur][p[cur]]++;
    }
  }
  cout << ans << '\n';
}
