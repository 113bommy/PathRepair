#include <bits/stdc++.h>
const int MAX = 2000;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
const long double PI = acos(-1.0);
using namespace std;
const int K = 100;
int logv[MAX + 1];
int st[MAX][K];
vector<vector<int> > grafo(1010, vector<int>());
void make() {
  logv[1] = 0;
  for (int i = 2; i <= MAX; i++) logv[i] = logv[i / 2] + 1;
}
void precompute(int N, int array[]) {
  for (int i = 0; i < N; i++) st[i][0] = array[i];
  int k = logv[N];
  for (int j = 1; j <= k; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int query(int L, int R) {
  int j = logv[R - L + 1];
  int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
  return minimum;
}
int start[MAX + 1], dfs_time;
int tour[2 * MAX + 1], id[2 * MAX + 1];
void dfs(int u, int pai = -1) {
  start[u] = dfs_time;
  id[dfs_time] = u;
  tour[dfs_time++] = start[u];
  for (int v : grafo[u]) {
    if (v == pai) continue;
    dfs(v, u);
    id[dfs_time] = u;
    tour[dfs_time++] = start[u];
  }
}
int LCA(int u, int v) {
  if (start[u] > start[v]) swap(u, v);
  return id[query(start[u], start[v])];
}
struct circle {
  long long r, x, y;
};
bool comp(circle a, circle b) { return a.r < b.r; }
long long sq(long long a) { return a * a; }
bool inter(circle k, circle c) {
  return (sq(k.x - c.x) + sq(k.y - c.y) <= sq(k.r - c.r));
}
int altura[1010];
void dfsh(int u, int pai, int h) {
  altura[u] = h;
  for (auto v : grafo[u]) {
    if (v == pai) continue;
    dfsh(v, u, h + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k, r, x, y, a, b;
  vector<circle> vet, K;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    K.push_back({0, x, y});
  }
  for (int i = 0; i < m; i++) {
    cin >> r >> x >> y;
    vet.push_back({r, x, y});
  }
  sort(vet.begin(), vet.end(), comp);
  for (int i = 0; i < m; i++) {
    bool t = true;
    for (int j = i + 1; j < m; j++) {
      if (inter(vet[i], vet[j])) {
        grafo[i + 2].push_back(j + 2);
        grafo[j + 2].push_back(i + 2);
        t = false;
        break;
      }
    }
    if (t) {
      grafo[i + 2].push_back(1);
      grafo[1].push_back(i + 2);
    }
  }
  vector<int> no(1010, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (inter(K[i], vet[j])) {
        no[i + 2] = j + 2;
        break;
      }
    }
  }
  dfs(1);
  make();
  precompute(2 * (m + 2), tour);
  dfsh(1, -1, 1);
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    int lca = LCA(no[a + 1], no[b + 1]);
    cout << altura[no[a + 1]] + altura[no[b + 1]] - 2 * altura[lca] << '\n';
  }
  return 0;
}
