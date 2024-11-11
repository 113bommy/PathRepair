#include <bits/stdc++.h>
#pragma GCC optimize("fast-math")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")
using namespace std;
vector<set<long long>> vec;
vector<long long> su;
vector<long long> pr;
set<pair<long long, long long>> st;
long long ko;
void unite(long long u, long long v, long long x) {
  if (pr[u] == pr[v]) {
    u = pr[u];
    st.erase({su[u], u});
    su[u] += x;
    st.insert({su[u], u});
    return;
  }
  u = pr[u];
  v = pr[v];
  ko--;
  if (vec[u].size() < vec[v].size()) swap(u, v);
  for (auto it : vec[v]) {
    pr[it] = u;
    vec[u].insert(it);
  }
  st.erase({su[u], u});
  st.erase({su[v], v});
  su[u] += su[v] + x;
  st.insert({su[u], u});
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, p, q;
  cin >> n >> m >> p >> q;
  pr.assign(n, 0);
  su.assign(n, 0);
  vec.resize(n);
  for (long long i = 0; i < n; ++i) {
    st.insert({0, i});
  }
  ko = n;
  for (long long i = 0; i < n; ++i) {
    set<long long> stt;
    stt.insert(i);
    vec[i] = stt;
    pr[i] = i;
  }
  for (long long i = 0; i < m; ++i) {
    long long u, v, x;
    cin >> u >> v >> x;
    unite(u - 1, v - 1, x);
  }
  if (ko < q) {
    cout << "NO";
    return 0;
  }
  long long o = 0;
  vector<pair<long long, long long>> ans;
  while (ko > q && o < p) {
    auto w1 = (*st.begin());
    st.erase(st.begin());
    auto w2 = (*st.begin());
    st.insert(w1);
    ans.push_back({w1.second, w2.second});
    o++;
    unite(w1.second, w2.second, w1.first + w2.first + 1);
  }
  if (ko > q) {
    cout << "NO";
    return 0;
  }
  if (o == p) {
    cout << "YES" << '\n';
    for (auto it : ans) cout << it.first + 1 << " " << it.second + 1 << '\n';
    return 0;
  }
  long long a = 1e9, b = 1e9;
  for (long long i = 0; i < n; ++i) {
    if (pr[i] == i) {
      if (vec[i].size() > 1) {
        a = *(vec[i].begin());
        vec[i].erase(a);
        b = *(vec[i].begin());
      }
    }
  }
  if (a == 1e9) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << '\n';
  for (auto it : ans) cout << it.first + 1 << " " << it.second + 1 << '\n';
  while (o < p) {
    o++;
    cout << a + 1 << " " << b + 1 << '\n';
  }
}
