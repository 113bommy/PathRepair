#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, vis[N], par[N], num[N], rk[N];
vector<int> g[N][10];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (m); ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u][w].push_back(v);
    g[v][w].push_back(u);
  }
  vector<int> v, nv;
  v.push_back(n - 1);
  vis[n - 1] = true;
  for (int i = 0; i < ((int)(v).size()); ++i) {
    int c = v[i];
    for (auto t : g[c][0])
      if (!vis[t]) vis[t] = true, v.push_back(t), num[t] = 0, par[t] = c;
  }
  while ((int)(v).size()) {
    nv.clear();
    for (int i = 0, j = 0; i < (int)(v).size(); i = j) {
      for (int k = 0; k < (10); ++k) {
        for (j = i; j < (int)(v).size() && rk[v[j]] == rk[v[i]]; ++j) {
          int c = v[j];
          for (auto t : g[c][k])
            if (!vis[t]) vis[t] = true, nv.push_back(t), num[t] = k, par[t] = c;
        }
      }
    }
    sort((nv).begin(), (nv).end(), [&](int a, int b) {
      return make_pair(rk[par[a]], num[a]) < make_pair(rk[par[b]], num[b]);
    });
    for (int i = 0; i < ((int)(nv).size()); ++i) {
      int c = nv[i];
      if (i == 0)
        rk[c] = 0;
      else
        rk[c] = make_pair(rk[par[c]], num[c]) ==
                        make_pair(rk[par[nv[i - 1]]], num[nv[i - 1]])
                    ? rk[nv[i - 1]]
                    : rk[nv[i - 1]] + 1;
    }
    v.swap(nv);
  }
  vector<int> res;
  string ans;
  for (int c = 0;;) {
    res.push_back(c);
    if (c == n - 1) break;
    ans += char(num[c] + '0');
    c = par[c];
  }
  while ((int)(ans).size() && *ans.rbegin() == '0') ans.pop_back();
  reverse((ans).begin(), (ans).end());
  if ((int)(ans).size() == 0) ans = "0";
  cout << ans << endl;
  cout << (int)(res).size() << endl;
  for (int i = 0; i < ((int)(res).size()); ++i)
    printf("%d%c", res[i], " \n"[i + 1 == (int)(res).size()]);
  return 0;
}
