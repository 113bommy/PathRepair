#include <bits/stdc++.h>
using namespace std;
int n;
int a[2005][2005];
int b[2005][2005];
int magic[2005];
string s;
vector<int> adj[100005], rev_adj[100005];
int scc[100005];
vector<int> scc_adj[100005];
stack<int> stk;
bool vis[100005];
int in[100005];
int tim[100005];
vector<int> topo;
vector<pair<int, int> > ans;
struct TwoSat {
  int N;
  vector<vector<int> > gr;
  vector<int> values;
  TwoSat(int n = 0) : N(n), gr(2 * n) {}
  int add_var() {
    gr.emplace_back();
    gr.emplace_back();
    return N++;
  }
  void add_edge(int a, int b) {
    a = max(2 * a, -1 - 2 * a);
    b = max(2 * b, -1 - 2 * b);
    gr[a].push_back(b);
  }
  void OR(int a, int b) {
    add_edge(~a, b);
    add_edge(~b, a);
  }
  vector<int> val, comp, z;
  int time = 0;
  int dfs(int i) {
    int low = val[i] = ++time, x;
    z.push_back(i);
    for (auto e : gr[i])
      if (!comp[e]) low = min(low, val[e] ?: dfs(e));
    if (low == val[i]) do {
        x = z.back();
        z.pop_back();
        comp[x] = low;
        if (values[x >> 1] == -1) values[x >> 1] = x & 1;
      } while (x != i);
    return val[i] = low;
  }
  bool solve() {
    values.assign(N, -1);
    val.assign(2 * N, 0);
    comp = val;
    for (int i = 0; i < 2 * N; i++)
      if (!comp[i]) dfs(i);
    for (int i = 0; i < N; i++)
      if (comp[2 * i] == comp[2 * i + 1]) return 0;
    return 1;
  }
};
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 1; j <= n; j++) a[i][j] = s[j - 1] - '0';
  }
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 1; j <= n; j++) b[i][j] = s[j - 1] - '0';
  }
  cin >> s;
  for (int i = 1; i <= n; i++) magic[i] = s[i - 1] - '0';
  TwoSat sat(2 * n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != b[i][j]) {
        if (magic[i] == 0 && magic[j] == 0) return cout << "-1" << '\n', 0;
        if (magic[j] && !magic[i])
          sat.add_edge(~i, i);
        else if (magic[i] && !magic[j])
          sat.add_edge(~(j + n), j + n);
        else {
          sat.add_edge(i, ~(j + n));
          sat.add_edge(~i, j + n);
          sat.add_edge(j + n, ~i);
          sat.add_edge(~(j + n), i);
        }
      } else {
        if (magic[j] && !magic[i]) {
          sat.add_edge(i, ~i);
        } else if (magic[i] && !magic[j]) {
          sat.add_edge(j + n, ~(j + n));
        } else if (magic[i] && magic[j]) {
          sat.add_edge(i, (j + n));
          sat.add_edge(j + n, i);
          sat.add_edge(~i, ~(j + n));
          sat.add_edge(~(j + n), ~i);
        }
      }
    }
  }
  if (!sat.solve()) {
    cout << -1;
    return 0;
  }
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n; i++) {
    if (sat.values[i]) ans.push_back(make_pair(0, i));
  }
  for (int i = n + 1; i <= 2 * n; i++)
    if (sat.values[i]) ans.push_back(make_pair(1, i - n));
  cout << ans.size() << '\n';
  for (auto j : ans)
    if (j.first == 0)
      cout << "row " << j.second - 1 << '\n';
    else
      cout << "col " << j.second - 1 << '\n';
  return 0;
}
