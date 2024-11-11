#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
using namespace std;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int maxn = 2000 * 100 + 5;
const long long inf = 9223372036854775807;
const long long mod = 1e9 + 7;
const int lg = 20;
const int sig = 27;
int n, m, c[maxn][sig], f[maxn], fen[maxn * sig], st[maxn * sig],
    ft[maxn * sig], cnt, ts, ans[maxn * 3], q[maxn * sig], L, R, on[maxn * 3],
    node[maxn];
vector<int> adj[maxn * sig], t;
vector<pair<int, int> > Q[maxn * 3];
string s[maxn];
void addtrie(string S, int x) {
  int v = 0;
  for (char ch : S) {
    if (!c[v][ch - 'a']) c[v][ch - 'a'] = ++ts;
    v = c[v][ch - 'a'];
  }
  node[x] = v;
}
void BuildAho() {
  for (int i = 0; i < sig; i++)
    if (c[0][i]) q[R++] = c[0][i];
  while (L < R) {
    int v = q[L++];
    for (int i = 0; i < sig; i++) {
      if (!c[v][i])
        c[v][i] = c[f[v]][i];
      else {
        q[R++] = c[v][i];
        f[c[v][i]] = c[f[v]][i];
      }
    }
  }
}
void dfs(int v) {
  st[v] = cnt;
  cnt++;
  for (auto u : adj[v]) dfs(u);
  ft[v] = cnt;
}
void add(int i, int v) {
  for (i++; i < maxn; i += i & -i) {
    fen[i] += v;
  }
}
int get(int i) {
  int res = 0;
  for (i++; i > 0; i -= i & -i) res += fen[i];
  return res;
}
int get(int l, int r) { return get(r) - get(l - 1); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    addtrie(s[i], i);
  }
  BuildAho();
  for (int i = 1; i <= ts; i++) {
    adj[f[i]].push_back(i);
  }
  dfs(0);
  int l, r, k;
  for (int i = 1; i <= m; i++) {
    cin >> l >> r >> k;
    if (l - 1) {
      Q[l - 1].push_back({k, i});
    } else
      on[i] = 1;
    Q[r].push_back({k, i});
  }
  int cur;
  for (int i = 1; i <= n; i++) {
    cur = 0;
    for (char ch : s[i]) {
      cur = c[cur][ch - 'a'];
      add(st[cur], 1);
    }
    for (auto u : Q[i]) {
      if (on[u.second]) {
        ans[u.second] += get(st[node[u.first]], ft[node[u.first]] - 1);
      } else {
        ans[u.second] -= get(st[node[u.first]], ft[node[u.first]] - 1);
        on[u.second] = 1;
      }
    }
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}
