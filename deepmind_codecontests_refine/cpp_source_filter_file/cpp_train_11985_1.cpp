#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 15;
int n, m, v[N], d[N], x[N];
long long res[N];
vector<int> g[N];
vector<pair<int, int>> q[N];
long long les[N];
void dfs(int nod, int h, int dad, long long sum) {
  for (auto p : q[nod]) {
    int l = h, r = h + p.first;
    les[l] += p.second;
    if (r + 1 < N) les[r + 1] -= p.second;
  }
  sum += les[h];
  res[nod] = sum;
  for (auto it : g[nod])
    if (it != dad) dfs(it, h + 1, nod, sum);
  for (auto p : q[nod]) {
    int l = h, r = h + p.first;
    les[l] -= p.first;
    if (r + 1 < N) les[r + 1] += p.second;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1, a, b; i < n && cin >> a >> b; i++) {
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int v, d, x;
    cin >> v >> d >> x;
    q[v].push_back({d, x});
  }
  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) cout << res[i] << " ";
  return 0;
}
