#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int par[N], par2[N], fans[N], tc, tct[N];
vector<pair<int, int> > w[N];
pair<int, pair<int, int> > edge[N];
vector<pair<int, int> > g[N];
int findp(int a) { return par[a] == a ? a : par[a] = findp(par[a]); }
int findp2(int a) {
  if (tct[a] != tc) {
    tct[a] = tc;
    return par2[a] = findp(a);
  }
  return par2[a] == a ? a : par2[a] = findp2(par2[a]);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) par[i] = i, par2[i] = i;
  for (int i = 0, a, b, c; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    edge[i].first = a;
    edge[i].second.first = b;
    edge[i].second.second = c;
    g[c].push_back({a, b});
  }
  int q;
  scanf("%d", &q);
  for (int t = 0; t < q; t++) {
    int am;
    scanf("%d", &am);
    for (int i = 0, in; i < am; i++) {
      scanf("%d", &in);
      --in;
      w[edge[in].second.second].push_back({t, in});
    }
  }
  for (int i = 1, in; i < N; i++) {
    sort(w[i].begin(), w[i].end());
    while (w[i].size()) {
      in = w[i].back().first;
      tc++;
      while (w[i].size() && w[i].back().first == in) {
        int a = edge[w[i].back().second].first,
            b = edge[w[i].back().second].second.first;
        if (findp2(a) == findp2(b)) {
          fans[in] = 1;
        }
        par2[findp2(a)] = findp2(b);
        w[i].pop_back();
      }
    }
    while (g[i].size()) {
      if (findp(g[i].back().first) != findp(g[i].back().second)) {
        par[findp(g[i].back().first)] = findp(g[i].back().second);
      }
      g[i].pop_back();
    }
  }
  for (int i = 0; i < q; i++) {
    if (fans[i])
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
