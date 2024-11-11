#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 100 * 1000 + 24, INF = (1 << 30);
long long n;
int sz[MAX_N], ans[MAX_N];
bool mark[MAX_N];
vector<int> G[MAX_N];
void prep(int v, int par = -1) {
  sz[v] = 1;
  for (int i = 0; i < G[v].size(); i++) {
    int u = G[v][i];
    if (u != par and mark[u] == false) {
      prep(u, v);
      sz[v] += sz[u];
    }
  }
}
int centroid(int v, int cst) {
  bool bl = false;
  int par = -1;
  while (bl == false) {
    bl = true;
    for (int i = 0; i < G[v].size(); i++) {
      int u = G[v][i];
      if (u != par and mark[u] == false and sz[u] > cst) {
        par = v;
        v = u;
        bl = false;
        break;
      }
    }
  }
  return v;
}
void cnd_dec(int v, int c = 0) {
  prep(v);
  int cent = centroid(v, sz[v]);
  mark[cent] = true;
  ans[cent] = c;
  for (int i = 0; i < G[cent].size(); i++) {
    int u = G[cent][i];
    if (mark[u] == false) cnd_dec(u, c + 1);
  }
}
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cnd_dec(1);
  for (int i = 1; i <= n; i++) {
    cout << char(ans[i] + 'A') << " ";
  }
  cout << endl;
}
