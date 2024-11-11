#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void ran() { srand(chrono::steady_clock::now().time_since_epoch().count()); }
long long get_rand() {
  long long a = rand();
  long long b = rand();
  return a * (RAND_MAX + 1ll) + b;
}
const int MXN = 200005, MXK = 25, MXM = 400005;
int n, m;
int arr[MXN];
int where[MXM];
vector<int> sub[MXM];
int par[MXM][MXK];
int depth[MXM];
void dfs(int no, int pa, int dep = 0) {
  par[no][0] = pa;
  depth[no] = dep;
  for (int i = 1; i < MXK; i++) {
    int p = par[no][i - 1];
    if (p != -1) {
      par[no][i] = par[p][i - 1];
    }
  }
  for (auto x : sub[no]) dfs(x, no, dep + 1);
}
int kth_par(int n, int k) {
  for (int i = 0; i < MXK; i++) {
    if (k & (1 << i)) {
      n = par[n][i];
    }
  }
  return n;
}
int lca(int a, int b) {
  if (depth[a] > depth[b])
    a = kth_par(a, depth[a] - depth[b]);
  else
    b = kth_par(b, depth[b] - depth[a]);
  if (a == b) return a;
  for (int i = MXK - 1; i >= 0; i--) {
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  }
  return par[a][0];
}
signed main() {
  ran();
  fast();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= m; i++) where[i] = i;
  int co = 1, l;
  for (int i = m + 1; i <= INT_MAX && co < m; i++, co++) {
    int a, b;
    cin >> a >> b;
    sub[i].push_back(where[a]);
    sub[i].push_back(where[b]);
    where[a] = i;
    where[b] = i;
    l = i;
  }
  for (int i = 0; i < MXN; i++)
    for (int j = 0; j < MXK; j++) par[i][j] = -1;
  dfs(l, -1);
  vector<int> t;
  for (int i = 2; i <= n; i++) {
    int a = arr[i - 1], b = arr[i];
    int l = lca(a, b);
    t.push_back(max(l - m, 0));
  }
  sort(t.begin(), t.end());
  int x = 0;
  for (int i = 0; i < m; i++) {
    while (x < n - 1 && t[x] <= i) {
      x++;
    }
    cout << n - 1 - x << endl;
  }
}
