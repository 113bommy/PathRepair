#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
int sign(T a) {
  if (a == 0) return 0;
  return (a > 0 ? 1 : -1);
}
template <typename T1, typename T2>
T2 sum_mod(T1 x, T2 MOD) {
  if (x < 0) x += MOD;
  if (x >= MOD) x -= MOD;
  return x;
}
template <typename T1, typename T2>
T2 mul_mod(T1 x, T2 MOD) {
  if (x < 0) return (abs(x) % MOD == 0 ? 0 : MOD - abs(x) % MOD);
  return x % MOD;
}
template <typename T>
bool uax(T& a, const T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool uin(T& a, const T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << ' ' << p.second;
  return out;
}
mt19937_64 rnd(0);
const int LOG = 21;
const int N = (int)1e6 + 7;
const int MAXN = (int)2e6 + 7;
const int MOD = (int)998244353;
const int INF = (int)1e9 + 7;
const int CONST = 450;
const long long LINF = (int64_t)1e17;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1;
int n, m, rob, bl;
vector<vector<char>> col, fld;
vector<pair<int, int>> st, cyc;
vector<vector<int>> used, vc, dist;
pair<int, int> nxt(int x, int y, char c) {
  if (c == 'L') return make_pair(x, y - 1);
  if (c == 'R') return make_pair(x, y + 1);
  if (c == 'U') return make_pair(x - 1, y);
  if (c == 'D') return make_pair(x + 1, y);
}
int blacked[N], up[LOG][N];
int get_prev(int u, int x) {
  int res = u;
  for (int i = LOG - 1; i >= 0; i--) {
    if (x >= (1 << i)) {
      u = up[i][u];
      x -= 1 << i;
    }
  }
  return u;
}
pair<int, int> get_pair(char c) {
  if (c == 'L') return make_pair(0, 1);
  if (c == 'R') return make_pair(0, -1);
  if (c == 'U') return make_pair(1, 0);
  if (c == 'D') return make_pair(-1, 0);
}
void proc_cyc() {
  int ver = (int)cyc.size();
  for (int i = 0; i < ver; i++) up[0][i] = (i + 1) % ver;
  for (int i = 1; i < LOG; i++) {
    for (int j = 0; j < ver; j++) up[i][j] = up[i - 1][up[i - 1][j]];
  }
  fill(blacked, blacked + ver, 0);
  queue<pair<int, int>> q;
  for (int i = 0; i < ver; i++) {
    q.push(cyc[i]);
    int x, y;
    tie(x, y) = cyc[i];
    vc[x][y] = i;
    dist[x][y] = 0;
  }
  rob += ver;
  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    int v = get_prev(vc[x][y], dist[x][y]);
    if (col[x][y] == '0' && blacked[v] == 0) {
      bl++;
      blacked[v] = 1;
    }
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i * j != 0) continue;
        int nx = x + i, ny = y + j;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != INF)
          continue;
        if (make_pair(i, j) != get_pair(fld[nx][ny])) continue;
        q.push(make_pair(nx, ny));
        vc[nx][ny] = vc[x][y];
        dist[nx][ny] = dist[x][y] + 1;
      }
    }
  }
}
void dfs(int x, int y) {
  used[x][y] = 1;
  st.push_back(make_pair(x, y));
  int nx, ny;
  tie(nx, ny) = nxt(x, y, fld[x][y]);
  if (used[nx][ny] == 2) {
    used[x][y] = 2;
    return;
  }
  if (used[nx][ny] == 1) {
    cyc.clear();
    while (st.back() != make_pair(nx, ny)) {
      cyc.push_back(st.back());
      st.pop_back();
    }
    cyc.push_back(st.back());
    proc_cyc();
    used[x][y] = 2;
    return;
  }
  dfs(nx, ny);
  used[x][y] = 2;
}
int main() {
  double start = clock();
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  rnd.seed(time(0));
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vc.assign(n, vector<int>(m));
    col.assign(n, vector<char>(m));
    fld.assign(n, vector<char>(m));
    used.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, INF));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> col[i][j];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> fld[i][j];
    }
    rob = 0, bl = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!used[i][j]) {
          st.clear();
          dfs(i, j);
        }
      }
    }
    cout << rob << ' ' << bl << "\n";
  }
}
