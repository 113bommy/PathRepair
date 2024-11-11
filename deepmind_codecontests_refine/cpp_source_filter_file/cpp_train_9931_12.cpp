#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
const int INF = int(1e9);
const long long INF64 = long long(1e18);
const long double EPS = 1e-9, PI = 3.1415926535897932384626433832795;
const int N = 1600 + 13;
int n, m;
char f[N][N];
inline bool read() {
  if (scanf("%d%d", &n, &m) != 2) return false;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) {
      int tmp;
      assert(scanf("%d", &tmp) == 1);
      f[i][j] = char(tmp);
    }
  return true;
}
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool used[N][N];
pair<int, int> comp[N * N];
int szcomp;
int d[N][N];
int delps[N][N];
bool elps[N][N];
void dfs(int first, int second) {
  used[first][second] = true;
  comp[szcomp++] = make_pair((first), (second));
  for (int i = 0; i < int(8); i++) {
    int tx = first + dx[i], ty = second + dy[i];
    if (!(0 <= (tx) && (tx) < (n) && 0 <= (ty) && (ty) < (m)) || used[tx][ty] ||
        f[tx][ty] != 1)
      continue;
    dfs(tx, ty);
  }
}
inline bool bord(const pair<int, int>& a) {
  for (int i = 0; i < int(8); i++) {
    int tx = a.first + dx[i], ty = a.second + dy[i];
    if (!(0 <= (tx) && (tx) < (n) && 0 <= (ty) && (ty) < (m)) || f[tx][ty] == 0)
      return true;
  }
  return false;
}
const int M2 = 8;
void dfse(int first, int second) {
  elps[first][second] = true;
  for (int i = 0; i < int(8); i++) {
    int tx = first + dx[i], ty = second + dy[i];
    if (!(0 <= (tx) && (tx) < (n) && 0 <= (ty) && (ty) < (m)) ||
        f[tx][ty] == 0 || elps[tx][ty] || delps[tx][ty] <= M2)
      continue;
    dfse(tx, ty);
  }
}
void printEllipse() {
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(m); j++) cerr << (delps[i][j] <= M2);
    cerr << endl;
  }
  cerr << endl;
}
int calc(int sx, int sy) {
  szcomp = 0;
  dfs(sx, sy);
  queue<pair<int, int> > q;
  for (int i = 0; i < int(szcomp); i++)
    if (bord(comp[i])) {
      d[comp[i].first][comp[i].second] = 0;
      q.push(comp[i]);
    }
  while (!q.empty()) {
    int first = q.front().first, second = q.front().second;
    q.pop();
    for (int i = 0; i < int(8); i++) {
      int tx = first + dx[i], ty = second + dy[i];
      if (!(0 <= (tx) && (tx) < (n) && 0 <= (ty) && (ty) < (m)) ||
          f[tx][ty] == 0 || d[tx][ty] <= d[first][second] + 1)
        continue;
      d[tx][ty] = d[first][second] + 1;
      q.push(make_pair((tx), (ty)));
    }
  }
  const int M = 3;
  for (int i = 0; i < int(szcomp); i++)
    if (d[comp[i].first][comp[i].second] > M) {
      q.push(comp[i]);
      delps[comp[i].first][comp[i].second] = 0;
    }
  while (!q.empty()) {
    int first = q.front().first, second = q.front().second;
    q.pop();
    for (int i = 0; i < int(8); i++) {
      int tx = first + dx[i], ty = second + dy[i];
      if (!(0 <= (tx) && (tx) < (n) && 0 <= (ty) && (ty) < (m)) ||
          f[tx][ty] == 0 || delps[tx][ty] <= delps[first][second] + 1)
        continue;
      delps[tx][ty] = delps[first][second] + 1;
      q.push(make_pair((tx), (ty)));
    }
  }
  int ans = 0;
  for (int i = 0; i < int(szcomp); i++) {
    int first = comp[i].first, second = comp[i].second;
    if (elps[first][second] || delps[first][second] <= M2) continue;
    ans++;
    dfse(first, second);
  }
  return ans;
}
inline void solve() {
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++) d[i][j] = delps[i][j] = INF;
  vector<int> ans;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(m); j++)
      if (f[i][j] == 1 && !used[i][j]) ans.push_back(calc(i, j));
  sort((ans).begin(), (ans).end());
  cout << int((ans).size()) << endl;
  for (int i = 0; i < int(int((ans).size())); i++) printf("%d ", ans[i]);
  puts("");
}
int main() {
  cout << setprecision(10) << fixed;
  cerr << setprecision(5) << fixed;
  assert(read());
  solve();
  return 0;
}
