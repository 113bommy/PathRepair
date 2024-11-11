#include <bits/stdc++.h>
using namespace std;
const int limit = 1e5 + 1;
vector<int> g[limit];
int p[limit];
int a[limit];
double dnodes[limit];
double ewt[limit];
pair<int, int> edge[limit];
double ans = 0;
double deno;
double nume;
void dfs(int s) {
  long long cnt = 1;
  for (int i = 0; i < g[s].size(); i++) {
    int v = g[s][i];
    if (v != p[s]) {
      p[v] = s;
      dfs(v);
      cnt += dnodes[v];
    }
  }
  dnodes[s] = cnt;
}
void preprocess(long long n) {
  deno = 1LL * n * (n - 1) / 6;
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    a = edge[i].first;
    b = edge[i].second;
    if (p[a] == b) swap(a, b);
    nume = nume + (n - dnodes[b]) * dnodes[b] * ewt[i];
  }
}
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n - 1; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    edge[i] = make_pair(a, b);
    ewt[i] = l;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  dnodes[0] = dnodes[1];
  preprocess(n);
  int q;
  cin >> q;
  while (q--) {
    int r, w;
    cin >> r >> w;
    int a, b;
    a = edge[r].first;
    b = edge[r].second;
    if (p[a] == b) swap(a, b);
    nume = nume - (n - dnodes[b]) * dnodes[b] * (ewt[r] - w);
    double ans = nume / deno;
    printf("%0.7f\n", ans);
    ewt[r] = w;
  }
  return 0;
}
