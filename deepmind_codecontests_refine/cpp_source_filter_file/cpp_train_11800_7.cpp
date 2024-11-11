#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 2200;
string S[maxn];
int f[maxn][maxn], h[maxn], tms;
int calc(int L, int R) {
  if (L >= R) return 0;
  int t = ++tms, x = min_element(h + L, h + R) - h;
  int p = calc(L, x), q = calc(x + 1, R);
  for (int i = 0; i <= x - L + 1; ++i)
    for (int j = 0; j <= R - x; ++j)
      chkmax(f[t][i + j], f[p][i] + f[q][j] + i * j * h[x]);
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> S[i];
  sort(S + 1, S + n + 1);
  for (int i = 1; i < n; ++i)
    for (; h[i] < (int)((S[i]).size()) && h[i] < (int)((S[i + 1]).size()) &&
           S[i][h[i]] == S[i + 1][h[i]];
         ++h[i])
      ;
  cout << f[calc(1, n)][k - 1] << endl;
  return 0;
}
