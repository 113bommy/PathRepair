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
  vector<vector<edge>> adj;
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
int T[maxn][maxn];
long double aux[maxn][maxn];
pair<int, int> ans;
int n;
void gauss_blur(int n) {
  const long double sigma = 0.8, pi = acos(-1);
  long double total = 0, w[3][3] = {{0}};
  for (int i = -1; i <= 1; ++i)
    for (int j = -1; j <= 1; ++j) {
      w[i + 1][j + 1] = exp(-(i * i + j * j) / (2 * sigma * sigma)) /
                        (2 * pi * sigma * sigma);
      total += w[i + 1][j + 1];
    }
  memset(aux, 0, sizeof(aux));
  for (int x = 1; x <= n; ++x)
    for (int y = 1; y <= n; ++y)
      for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
          int a = x + i <= 0 || x + i > n ? (x - i) : (x + i),
              b = (y + j) <= 0 || y + j > n ? (y - j) : (y + j);
          aux[x][y] += T[a][b] * w[i + 1][j + 1];
        }
  for (int x = 1; x <= n; ++x)
    for (int y = 1; y <= n; ++y) T[x][y] = aux[x][y] <= total * 0.5 ? 0 : 1;
}
vector<pair<int, int>> Q;
bool o[maxn][maxn];
int enter;
void enque(int x, int y) {
  if (1 <= x && x <= n && 1 <= y && y <= n && !o[x][y])
    o[x][y] = 1, Q.push_back(make_pair(x, y));
}
void check(pair<int, int> p, bool solve) {
  Q.clear();
  enter = 0, enque(p.first, p.second);
  int head = 0;
  for (; head != (int)((Q).size()); ++head)
    for (int i = -1; i <= 1; ++i)
      for (int j = -1; j <= 1; ++j)
        if (abs(i) + abs(j) == 1 &&
            T[Q[head].first][Q[head].second] ==
                T[Q[head].first + i][Q[head].second + j])
          enque(Q[head].first + i, Q[head].second + j);
  if ((int)((Q).size()) < 200) {
    for (auto &p : Q) T[p.first][p.second] ^= 1;
    return;
  }
  if (!solve) return;
  long double cx = 0, cy = 0;
  int n = (int)((Q).size());
  long double R = 0;
  for (auto &p : Q) cx += p.first, cy += p.second;
  cx /= n, cy /= n;
  for (auto &p : Q) chkmax(R, hypot(cx - p.first, cy - p.second));
  cerr << n << " " << R << endl;
  if (n < 2.5 * R * R)
    ++ans.second;
  else
    ++ans.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> T[i][j];
  for (int i = 1; i <= 10; ++i) gauss_blur(n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!o[i][j]) check(make_pair(i, j), 0);
  memset(o, 0, sizeof(o));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (T[i][j] && !o[i][j]) check(make_pair(i, j), 1);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
