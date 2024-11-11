#include <bits/stdc++.h>
using namespace std;
int i, j, ind[2000005], lf[2000005], rg[2000005];
vector<long long> a;
vector<pair<int, int> > pr, npr, st, nst;
vector<pair<int, long long> > g[2000005];
long long ans, n, k;
void dfs(int v, long long x = 0, int p = -1) {
  a.push_back(x);
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i].first;
    if (to == p) continue;
    dfs(to, x ^ g[v][i].second, v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cin >> n >> k;
  k--;
  for (i = 0; i < n - 1; i++) {
    int p;
    long long w;
    cin >> p >> w;
    p--;
    g[i + 1].push_back({p, w});
    g[p].push_back({i + 1, w});
  }
  dfs(0);
  sort(a.begin(), a.end());
  st.push_back({0, n - 1});
  pr.push_back({0, 0});
  for (i = 61; i >= 0; i--) {
    nst.clear();
    npr.clear();
    for (j = 0; j < st.size(); j++) {
      int l = st[j].first, r = st[j].second;
      ind[j] = r + 1;
      for (int k = l; k <= r; k++) {
        if (a[k] & (1LL << i)) {
          ind[j] = k;
          break;
        }
      }
      if (l <= ind[j] - 1) {
        lf[j] = nst.size();
        nst.push_back({l, ind[j] - 1});
      } else
        lf[j] = -1;
      if (ind[j] <= r) {
        rg[j] = nst.size();
        nst.push_back({ind[j], r});
      } else
        rg[j] = -1;
    }
    long long sum = 0;
    for (j = 0; j < pr.size(); j++) {
      int a = pr[j].first, b = pr[j].second;
      sum += (ind[a] - st[a].first) * 1LL * (ind[b] - st[b].first);
      sum += (st[a].second - ind[a] + 1) * 1LL * (st[b].second - ind[b] + 1);
      if (sum > n * n) break;
    }
    if (sum > k) {
      for (j = 0; j < pr.size(); j++) {
        int a = pr[j].first, b = pr[j].second;
        if (lf[a] != -1 && lf[b] != -1) npr.push_back({lf[a], lf[b]});
        if (rg[a] != -1 && rg[b] != -1) npr.push_back({rg[a], rg[b]});
      }
    } else {
      k -= sum;
      ans |= (1LL << i);
      for (j = 0; j < pr.size(); j++) {
        int a = pr[j].first, b = pr[j].second;
        if (lf[a] != -1 && rg[b] != -1) npr.push_back({lf[a], rg[b]});
        if (rg[a] != -1 && lf[b] != -1) npr.push_back({rg[a], lf[b]});
      }
    }
    pr = npr;
    st = nst;
  }
  cout << ans;
  return 0;
}
