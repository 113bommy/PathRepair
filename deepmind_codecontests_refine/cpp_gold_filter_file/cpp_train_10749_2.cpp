#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";
template <class T0, class T1>
inline ostream &operator<<(ostream &out, pair<T0, T1> &a) {
  return out << "{" << a.first << ", " << a.second << "}";
}
template <class T0, class T1>
inline istream &operator>>(istream &in, pair<T0, T1> &a) {
  return in >> a.first >> a.second;
}
template <class T0, class T1, class T2>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2> &a) {
  return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a)
             << "}";
}
template <class T0, class T1, class T2, class T3>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2, T3> &a) {
  return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a)
             << ", " << get<3>(a) << "}";
}
template <class T>
inline ostream &operator<<(ostream &out, vector<T> &a) {
  out << "[";
  for (int i = 0; i < int(a.size()); ++i)
    out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
  return out;
}
void smain();
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12) << fixed;
  smain();
  return 0;
}
const int L = 20;
vector<int> ts;
int used[L];
int comp[L];
vector<int> verts[L];
set<int> g[L];
vector<int> rg[L];
void top_sort(int v) {
  used[v] = 1;
  for (int to : g[v]) {
    if (used[to] == 0) {
      top_sort(to);
    }
  }
  ts.push_back(v);
  used[v] = 2;
}
void inv_dfs(int v, int c) {
  used[v] = 1;
  comp[v] = c;
  verts[c].push_back(v);
  for (int to : rg[v]) {
    if (used[to] == 0) {
      inv_dfs(to, c);
    }
  }
  used[v] = 2;
}
const int N = 20;
int mat[N][N];
int dp[1 << N];
int mg[N];
const int oo = 1e9 + 10;
int solve(set<int> &vr) {
  int edges = 0;
  for (int i = 0; i < int(N); ++i) {
    mg[i] = 0;
    for (int j = 0; j < int(N); ++j) {
      edges += mat[i][j];
      if (mat[i][j]) mg[i] += 1 << j;
    }
  }
  for (int mask = 0; mask < int(1 << N); ++mask) {
    dp[mask] = oo;
  }
  dp[0] = 0;
  for (int mask = 0; mask < int(1 << N); ++mask) {
    for (int i = 0; i < int(N); ++i)
      if (!((mask >> i) & 1)) {
        int nmask = mask + (1 << i);
        int anti = ((1 << N) - 1) ^ nmask;
        int ed = __builtin_popcount(mask & mg[i]);
        dp[nmask] = min(dp[nmask], (dp[mask] + (ed != 0 && vr.count(i))));
      }
  }
  return dp[(1 << N) - 1];
}
void smain() {
  int t;
  cin >> t;
  while (t--) {
    ts.clear();
    for (int i = 0; i < int(L); ++i) {
      comp[i] = 0;
      verts[i].clear();
      used[i] = 0;
      rg[i].clear();
      g[i].clear();
    }
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < int(n); ++i)
      if (a[i] != b[i]) {
        g[a[i] - 'a'].insert(b[i] - 'a');
      }
    vector<set<int>> t(L);
    for (int i = 0; i < int(L); ++i) {
      if (used[i]) continue;
      top_sort(i);
    }
    reverse(ts.begin(), ts.end());
    for (int v = 0; v < int(L); ++v) {
      for (int to : g[v]) {
        rg[to].push_back(v);
      }
      used[v] = 0;
    }
    int cnt = 0;
    int ans = 0;
    for (auto v : ts) {
      if (used[v]) continue;
      inv_dfs(v, cnt++);
      if (verts[comp[v]].size() != 1) {
        for (int i = 0; i < int(N); ++i) {
          for (int j = 0; j < int(N); ++j) {
            mat[i][j] = 0;
          }
        }
        set<int> vr(verts[comp[v]].begin(), verts[comp[v]].end());
        for (int v = 0; v < int(L); ++v) {
          for (int to : g[v]) {
            if (vr.count(v) && vr.count(to)) {
              mat[v][to] = 1;
            }
          }
        }
        ans += verts[comp[v]].size() - 1;
        ans += solve(vr);
      }
    }
    for (int v = 0; v < int(L); ++v) {
      for (int to : g[v]) {
        if (comp[v] != comp[to]) {
          t[comp[v]].insert(comp[to]);
        }
      }
    }
    for (int i = 0; i < int(cnt); ++i) {
      t[i].erase(i);
      if (t[i].empty()) continue;
      ans++;
      t[*t[i].begin()].insert(t[i].begin(), t[i].end());
    }
    cout << ans << '\n';
  }
}
