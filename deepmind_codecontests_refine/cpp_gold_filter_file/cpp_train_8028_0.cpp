#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
int N;
long long a[maxn];
long long zb[maxn];
long long curr[maxn];
long long rj[maxn];
long long sol;
int u;
int v;
vector<int> graf[maxn];
vector<int> stablo[maxn];
bool bio[maxn];
void make_tree(int x) {
  bio[x] = 1;
  for (int i = 0; i < graf[x].size(); i++) {
    int n = graf[x][i];
    if (!bio[n]) {
      stablo[x].push_back(n);
      make_tree(n);
    }
  }
  return;
}
void dfs(int x) {
  zb[x] = a[x];
  curr[x] = 0;
  for (int i = 0; i < stablo[x].size(); i++) {
    int n = stablo[x][i];
    dfs(n);
    zb[x] += zb[n];
    curr[x] += (curr[n] + zb[n]);
  }
  return;
}
void solve(int x, int p) {
  if (p) {
    rj[x] = rj[p] + zb[1] - 2 * zb[x];
    sol = max(sol, rj[x]);
  }
  for (int i = 0; i < stablo[x].size(); i++) solve(stablo[x][i], x);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  for (int i = 1; i < N; i++) {
    cin >> u >> v;
    graf[u].push_back(v);
    graf[v].push_back(u);
  }
  make_tree(1);
  dfs(1);
  rj[1] = curr[1];
  sol = rj[1];
  solve(1, 0);
  cout << sol;
}
