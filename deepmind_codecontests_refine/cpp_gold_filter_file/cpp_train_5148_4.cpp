#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 50005, SZ = 300, inf = 1e9 + 7;
int n, q;
int f[N][5], ans[N << 1], pp[N << 1], l[N * 11];
map<pair<int, int>, int> pre;
vector<int> g[N * 11];
vector<pair<int, int> > vis[N];
vector<pair<pair<int, int>, int> > V[N * 11];
char s[N];
int calc(char s[], int len) {
  int r = 0;
  for (int i = (0); i < (len); i++) r = r * 27 + s[i] - 'a' + 1;
  return r;
}
int solve(int u, int v, int l1, int l2) {
  int r = inf;
  for (int i = 0, j = 0; i < (int)g[u].size(); ++i) {
    while (j < (int)g[v].size() && g[v][j] < g[u][i]) ++j;
    if (j == (int)g[v].size()) break;
    if (g[u][i] <= g[v][j])
      r = min(r, max(g[u][i] + l1, g[v][j] + l2) - g[u][i]);
  }
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> s;
  n = strlen(s);
  for (int i = (0); i < (n); i++)
    for (int j = 1; i + j - 1 < n && j <= 4; ++j) {
      int t = f[i][j] = calc(s + i, j);
      l[t] = j;
      g[t].push_back(i);
    }
  cin >> q;
  fill_n(ans + 1, q, inf);
  for (int i = (1); i < (q + 1); i++) {
    char s1[11], s2[11];
    cin >> s1 >> s2;
    int l1 = strlen(s1), l2 = strlen(s2);
    int u = calc(s1, l1), v = calc(s2, l2);
    if (pre.count(make_pair(u, v))) {
      pp[i] = pre[make_pair(u, v)];
      continue;
    }
    if (!(int)g[u].size() || !(int)g[v].size()) {
      ans[i] = -1;
      continue;
    }
    if ((int)g[u].size() < SZ && (int)g[v].size() < SZ) {
      ans[i] = min(solve(u, v, l1, l2), solve(v, u, l2, l1));
    } else {
      if ((int)g[v].size() >= SZ) swap(u, v), swap(l1, l2);
      V[u].push_back(make_pair(make_pair(v, l2), i));
    }
    pre[make_pair(u, v)] = pre[make_pair(v, u)] = i;
  }
  for (int i = (0); i < (N * 11); i++)
    if ((int)V[i].size()) {
      for (int j = (0); j < (n); j++) vis[j].clear();
      for (auto c : V[i]) {
        int u = c.first.first;
        for (auto t : g[u]) {
          vis[t].push_back(make_pair(c.first.second, c.second));
        }
      }
      for (int j = 0, k = 0; j < n; ++j)
        if ((int)vis[j].size()) {
          while (k + 1 < (int)g[i].size() && g[i][k + 1] <= j) ++k;
          if (g[i][k] <= j)
            for (auto c : vis[j]) {
              ans[c.second] = min(ans[c.second],
                                  max(g[i][k] + l[i], j + c.first) - g[i][k]);
            }
        }
      for (int j = 0, k = 0; j < n; ++j)
        if ((int)vis[j].size()) {
          while (k < (int)g[i].size() && g[i][k] < j) ++k;
          if (g[i][k] >= j)
            for (auto c : vis[j]) {
              ans[c.second] =
                  min(ans[c.second], max(g[i][k] + l[i], j + c.first) - j);
            }
        }
    }
  for (int i = (1); i < (q + 1); i++) {
    if (ans[i] == inf) ans[i] = ans[pp[i]];
    cout << ans[i] << "\n";
  }
  return 0;
}
