#include <bits/stdc++.h>
using namespace std;
long long n, m;
const int N = 1e6 + 10;
vector<pair<long long, long long>> g[N];
int ja[N];
long long tenho[N], quero[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%lld", tenho + i);
  for (int i = 0; i < m; i++) {
    long long ia, ib;
    scanf("%lld%lld", &ia, &ib);
    ia--, ib--;
    quero[ia]++, quero[ib]++;
    g[ia].emplace_back(ib, i);
    g[ib].emplace_back(ia, i);
  }
  vector<int> ans;
  set<pair<long long, long long>> st;
  for (int i = 0; i < n; i++) {
    st.emplace(quero[i] - tenho[i], i);
  }
  while (!st.empty()) {
    long long dif, id;
    tie(dif, id) = *st.begin();
    st.erase(st.begin());
    map<long long, long long> mp;
    if (dif > 0) break;
    for (auto &par : g[id]) {
      long long it, ie;
      tie(it, ie) = par;
      if (ja[ie]) continue;
      ans.push_back(ie);
      ja[ie] = 1;
      mp[it]++;
    }
    for (auto &par : mp) {
      long long it, sub;
      tie(it, sub) = par;
      st.erase(pair<long long, long long>(quero[it] - tenho[it], it));
      quero[it] -= sub;
      st.emplace(quero[it] - tenho[it], it);
    }
  }
  if (!st.empty()) {
    puts("DEAD");
    return 0;
  } else {
    reverse((ans).begin(), (ans).end());
    puts("ALIVE");
    for (int i = 0; i < (int)(ans.size()); i++)
      printf("%d%c", ans[i] + 1, " \n"[i == (int)(ans.size()) - 1]);
  }
}
