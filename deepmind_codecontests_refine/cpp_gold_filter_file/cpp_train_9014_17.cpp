#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" PRId64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <typename T, typename... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <typename T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%" PRId64, x); }
template <typename T>
void _W(const vector<T> &x) {
  for (auto i = x.cbegin(); i != x.cend(); i++) {
    if (i != x.cbegin()) putchar(' ');
    _W(*i);
  }
}
void W() {}
template <typename T, typename... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
template <typename T, typename F>
inline void sort_uniq(vector<T> &v, F f) {
  sort(begin(v), end(v), f);
  v.resize(unique(begin(v), end(v)) - v.begin());
}
template <typename T>
using MaxHeap = priority_queue<T>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
const int N = 1e5 + 10;
int n, m, deg[N];
vector<int> e[N];
int cc, grp[N], vis[N], fa[N], dep[N], sol[N];
void cyc(int p, int q) {
  for (int i = p; i != q; i = fa[i]) sol[i] = 1;
  sol[q] = 1;
}
bool dfs(int p, int f, int lv) {
  grp[p] = cc;
  fa[p] = f;
  dep[p] = lv;
  vis[p] = 1;
  for (int i : e[p])
    if (i != f) {
      if (vis[i] == 0) {
        if (dfs(i, p, lv + 1)) return 1;
      } else if (vis[i] == 1) {
        cyc(p, i);
        return 1;
      }
    }
  vis[p] = 2;
  return 0;
}
void path(int a, int b) {
  while (a != b) {
    sol[a] = sol[b] = 2;
    if (dep[a] > dep[b])
      a = fa[a];
    else
      b = fa[b];
  }
  sol[a] = 2;
}
bool cmp_deg(int a, int b) { return deg[a] > deg[b]; }
bool cmp_sz(const vector<int> &a, const vector<int> &b) {
  return ((int)(a).size()) > ((int)(b).size());
}
vector<int> cd[N];
bool solve() {
  for (int i = (1); i <= int(n); i++) deg[i] = ((int)(e[i]).size());
  for (int i = (1); i <= int(n); i++) sort(begin(e[i]), end(e[i]), cmp_deg);
  for (int i = (1); i <= int(n); i++) vis[i] = sol[i] = 0;
  cc = 0;
  for (int i = (1); i <= int(n); i++)
    if (!vis[i]) {
      cc++;
      if (dfs(i, 0, 1)) return 1;
    }
  for (int i = (1); i <= int(n); i++)
    if (deg[i] >= 4) {
      sol[i] = 2;
      for (int j = 0; j < int(4); j++) sol[e[i][j]] = 1;
      return 1;
    }
  for (int i = (1); i <= int(cc); i++) cd[i].clear();
  for (int i = (1); i <= int(n); i++) cd[grp[i]].push_back(i);
  for (int i = (1); i <= int(cc); i++) {
    auto &v = cd[i];
    sort(begin(v), end(v), cmp_deg);
    if (((int)(v).size()) < 2 || deg[v[1]] < 3) continue;
    for (int j : e[v[0]]) sol[j] = 1;
    for (int j : e[v[1]]) sol[j] = 1;
    path(v[0], v[1]);
    return 1;
  }
  for (int i = (1); i <= int(n); i++)
    if (deg[i] >= 3) {
      vector<vector<int>> chs;
      for (int j : e[i]) {
        vector<int> ch;
        int pre = i, pos = j;
        while (deg[pos] == 2) {
          ch.push_back(pos);
          int npos = pre ^ e[pos][0] ^ e[pos][1];
          pre = pos;
          pos = npos;
        }
        ch.push_back(pos);
        chs.push_back(ch);
      }
      sort(begin(chs), end(chs), cmp_sz);
      ;
      if (((int)(chs[0]).size()) >= 5 && ((int)(chs[1]).size()) >= 2) {
        sol[i] = 6;
        for (int j = 0; j < int(5); j++) sol[chs[0][j]] = 5 - j;
        for (int j = 0; j < int(2); j++) sol[chs[1][j]] = 4 - 2 * j;
        sol[chs[2][0]] = 3;
        return 1;
      }
      if (((int)(chs[0]).size()) >= 3 && ((int)(chs[1]).size()) >= 3) {
        sol[i] = 4;
        for (int j = 0; j < int(3); j++)
          sol[chs[0][j]] = sol[chs[1][j]] = 3 - j;
        sol[chs[2][0]] = 2;
        return 1;
      }
      if (((int)(chs[2]).size()) >= 2) {
        sol[i] = 3;
        for (int j = 0; j < int(3); j++)
          for (int k = 0; k < int(2); k++) sol[chs[j][k]] = 2 - k;
        return 1;
      }
    }
  return 0;
}
int main() {
  int t;
  R(t);
  while (t--) {
    R(n, m);
    for (int i = (1); i <= int(n); i++) e[i].clear();
    for (int i = 0; i < int(m); i++) {
      int a, b;
      R(a, b);
      e[a].push_back(b);
      e[b].push_back(a);
    }
    if (solve()) {
      int s = 0;
      for (int i = (1); i <= int(n); i++) s += sol[i];
      assert(s != 0);
      W("YES");
      W(vector<int>(sol + 1, sol + n + 1));
    } else {
      W("NO");
    }
  }
  return 0;
}
