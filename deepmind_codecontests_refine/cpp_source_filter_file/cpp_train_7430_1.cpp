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
const int maxn = 153, mod = 1000000007;
long long f[maxn][maxn][maxn][4], S[4][maxn][maxn];
int sum(int s, int li, int ri, int lj, int rj) {
  --li, --lj;
  if (li < 0) li = 0;
  if (lj < 0) lj = 0;
  return S[s][ri][rj] - S[s][ri][lj] - S[s][li][rj] + S[s][li][lj];
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  long long ans = 0;
  cin >> n >> m;
  for (int L = 1; L <= m; ++L) {
    for (int s = 0; s < 4; ++s) {
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
          S[s][i][j] = S[s][i - 1][j] + S[s][i][j - 1] - S[s][i - 1][j - 1] +
                       f[L - 1][i][j][s];
    }
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; ++j) {
        for (int s = 0; s < 4; ++s) {
          auto &v = f[L][i][j][s];
          if (L == 2 && i == 1 && j == 2 && s == 0) {
            cerr << 1 << endl;
          }
          if (s == 0) {
            v = sum(0, i, j, i, j) + 1;
          } else if (s == 1) {
            v = sum(0, 1, i - 1, i, j) + sum(1, 1, i, i, j);
          } else if (s == 2) {
            v = sum(0, i, j, j + 1, n) + sum(2, i, j, j, n);
          } else if (s == 3) {
            v = sum(0, 1, i - 1, j + 1, n) + sum(1, 1, i, j + 1, n) +
                sum(2, 1, i - 1, j, n) + sum(3, 1, i, j, n);
          }
          v %= mod;
          ans += v;
        }
      }
  }
  cout << ans % mod << endl;
  return 0;
}
