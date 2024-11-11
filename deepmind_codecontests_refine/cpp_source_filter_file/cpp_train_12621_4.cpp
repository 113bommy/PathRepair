#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
template <class T>
ostream &operator<<(ostream &str, vector<T> &a) {
  for (auto &i : a) {
    str << i << " ";
  }
  return str;
}
template <class T>
istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) {
    str >> i;
  }
  return str;
}
template <class T>
ostream &operator<<(ostream &str, pair<T, T> &a) {
  str << a.first << " " << a.second;
  return str;
}
template <class T>
istream &operator>>(istream &str, pair<T, T> &a) {
  str >> a.first >> a.second;
  return str;
}
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(9);
  solve();
  return 0;
}
const int MOD = 998244353, MAXN = 1e6 + 10, INF = 1e9 + 10, BASE = 37;
vector<int> cycle;
set<int> id;
int pr[MAXN];
vector<int> g[MAXN], rg[MAXN];
void dfs1(int v, int p, vector<int> &cl) {
  cl[v] = 1;
  for (auto u : g[v]) {
    if (cl[u] == 0) {
      pr[u] = v;
      dfs1(u, v, cl);
    } else if (cl[u] == 1) {
      int tmp = u, vv = v;
      while (vv != tmp) {
        cycle.push_back(vv);
        vv = pr[vv];
      }
      cycle.push_back(vv);
    }
  }
  cl[v] = 2;
}
int f(int i, int j, char c, int m) {
  if (c == 'U') {
    return (i - 1) * m + j;
  } else if (c == 'D') {
    return (i + 1) * m + j;
  } else if (c == 'L') {
    return i * m + j - 1;
  } else if (c == 'R') {
    return i * m + j + 1;
  }
  return 0;
}
void dfs2(int v, int p, int i, vector<vector<bool>> &c, int m, vector<int> &cl,
          int d = 1) {
  int k = (int)((cycle).size());
  int vertex = cycle[(i + d) % k];
  if (c[v / m][v % m] == 1 && c[vertex / m][vertex % m] == 1) {
    id.insert((i + d) % k);
  }
  cl[v] = 2;
  for (auto u : rg[v]) {
    if (u != p) {
      dfs2(u, v, i, c, m, cl, d + 1);
    }
  }
}
void query() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> c(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      cin >> ch;
      c[i][j] = ch - '0';
    }
  }
  vector<vector<char>> s(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> s[i][j];
    }
  }
  vector<vector<int>> used(n, vector<int>(m));
  for (int i = 0; i < n * m; ++i) {
    g[i].clear();
    rg[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      g[i * m + j].push_back(f(i, j, s[i][j], m));
      rg[f(i, j, s[i][j], m)].push_back(i * m + j);
    }
  }
  for (int i = 0; i < n * m; ++i) {
    pr[i] = -1;
  }
  int ans1 = 0, ans2 = 0;
  vector<int> cl(n * m);
  for (int v = 0; v < n * m; ++v) {
    if (cl[v] == 0) {
      cycle.clear();
      dfs1(v, -1, cl);
      if (cycle.empty()) continue;
      ans1 += (int)((cycle).size());
      id.clear();
      for (int i = 0; i < (int)((cycle).size()); ++i) {
        int v = cycle[i];
        if ((int)((rg[v]).size()) != 1) {
          for (auto u : rg[v]) {
            if (u != cycle[(i - 1 + (int)((cycle).size())) %
                           (int)((cycle).size())] &&
                u != cycle[(i + 1) % (int)((cycle).size())]) {
              dfs2(u, v, i, c, m, cl);
            }
          }
        }
      }
      ans2 += (int)((id).size());
      for (int i = 0; i < (int)((cycle).size()); ++i) {
        int v = cycle[i];
        if (c[v / m][v % m] == 0) {
          ans2++;
        }
      }
    }
  }
  cout << ans1 << " " << ans2 << '\n';
}
void solve() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    query();
  }
}
