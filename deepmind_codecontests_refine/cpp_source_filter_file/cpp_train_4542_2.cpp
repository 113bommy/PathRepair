#include <bits/stdc++.h>
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
using namespace std;
template <class TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char* sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
const int N = 50, M = 50;
vector<pair<int, int> > nei[N + 1];
int n, m, s;
bool visited[N + 1];
long long dp[M + 1][N + 1];
int st_v, full_c;
int dfs(int v, int T) {
  visited[v] = true;
  if (v != st_v and (int)((nei[v]).size()) == 1) {
    for (long long i = (long long)1; i < (long long)full_c + 1; i++) {
      if (dp[full_c - i][v] <= T) {
        return i;
      }
    }
    return M + 1;
  } else {
    int sm = 0;
    for (auto& wp : nei[v]) {
      if (!visited[wp.first]) {
        int rec = dfs(wp.first, T - wp.second);
        if (!rec) {
          return 0;
        } else {
          sm += rec - 1;
        }
      }
    }
    return sm + 1;
  }
}
bool chk(int c, int c1, int u, int v, int T) {
  memset(visited, 0, (n + 1));
  visited[u] = true;
  if (u == 0) {
    st_v = v;
  } else {
    st_v = 0;
  }
  full_c = c;
  return dfs(v, T) <= c1;
}
int get_val(int c, int c1, int u, int v) {
  int start = 0, fin = N * N * N + 1;
  while (fin - start > 1) {
    int mid = (start + fin) / 2;
    if (chk(c, c1, u, v, mid)) {
      fin = mid;
    } else {
      start = mid;
    }
  }
  return fin;
}
int ter_cnt[N + 1];
void dfs_cnt(int v) {
  visited[v] = true;
  for (auto& wp : nei[v]) {
    if (!visited[wp.first]) {
      dfs_cnt(wp.first);
      ter_cnt[v] += ter_cnt[wp.first];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long _ = (long long)0; _ < (long long)n - 1; _++) {
    int u, v, w;
    cin >> u >> v >> w;
    nei[u].push_back({v, w});
    nei[v].push_back({u, w});
  }
  cin >> s;
  cin >> m;
  for (long long _ = (long long)0; _ < (long long)m; _++) {
    int t1;
    cin >> t1;
    ter_cnt[t1]++;
  }
  dfs_cnt(s);
  for (long long c = (long long)1; c < (long long)m + 1; c++) {
    for (long long v = (long long)1; v < (long long)n + 1; v++) {
      if ((int)((nei[v]).size()) == 1) {
        dp[c][v] = get_val(c, c, 0, v);
        (c, v, dp[c][v]);
      }
    }
  }
  int res = IINF;
  for (auto& wp : nei[s]) {
    res = min(res, wp.second + get_val(m, ter_cnt[wp.first], s, wp.first));
  }
  cout << res << "\n";
  return 0;
}
