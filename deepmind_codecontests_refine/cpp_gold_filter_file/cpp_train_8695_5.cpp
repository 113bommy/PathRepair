#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
const int maxn = 2005;
int n, m;
int a[maxn][maxn];
long long k;
vector<pair<int, pair<int, int> > > b;
void ReadData() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      b.push_back(make_pair(a[i][j], pair<int, int>(i, j)));
    }
  }
  sort(b.begin(), b.end());
}
int lab[maxn * maxn];
int Code(int i, int j) { return i * (m + 2) + j; }
int fin(int u) { return lab[u] < 0 ? u : lab[u] = fin(lab[u]); }
void Join(int u, int v) {
  if (lab[u] > lab[v]) swap(u, v);
  lab[u] += lab[v];
  lab[v] = u;
}
bool was[maxn][maxn];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool inside(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
bool is_res[maxn][maxn];
void Process() {
  memset(lab, -1, sizeof(lab));
  for (int i = ((int)b.size()) - 1; i >= 0; i--) {
    int x = b[i].second.first, y = b[i].second.second;
    for (int dir = 0; dir < 4; dir++) {
      int u = x + dx[dir], v = y + dy[dir];
      if (inside(u, v) && was[u][v]) {
        int i = Code(x, y), j = Code(u, v);
        i = fin(i);
        j = fin(j);
        if (i != j) Join(i, j);
      }
    }
    int z = Code(x, y), val = b[i].first;
    if (val && k % val == 0) {
      int sz = -lab[fin(z)];
      if (1LL * sz * val >= k) {
        cout << "YES" << endl;
        int need = k / val;
        queue<pair<int, int> > qu;
        is_res[x][y] = true;
        qu.push(pair<int, int>(x, y));
        --need;
        while (((int)qu.size()) && need) {
          int u = qu.front().first, v = qu.front().second;
          qu.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nu = u + dx[dir], nv = v + dy[dir];
            if (inside(nu, nv) && fin(Code(nu, nv)) == fin(Code(x, y)) &&
                !is_res[nu][nv] && need) {
              is_res[nu][nv] = true;
              --need;
              qu.push(pair<int, int>(nu, nv));
            }
          }
        }
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++)
            if (is_res[i][j])
              cout << val << " ";
            else
              cout << 0 << " ";
          cout << endl;
        }
        return;
      }
    }
    was[x][y] = true;
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ReadData();
  Process();
}
