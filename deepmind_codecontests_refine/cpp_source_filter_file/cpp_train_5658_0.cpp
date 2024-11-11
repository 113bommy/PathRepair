#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
const int N = 1e5 + 7;
int n, m, k;
bool star[N];
vector<int> ad[N];
int st, ed;
int mnd[N], ded[N];
int nget[N], give[N];
void bfsstar() {
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (star[i]) {
      mnd[i] = 1;
      q.push(i);
    }
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (auto u : ad[v])
      if (!mnd[u]) {
        mnd[u] = mnd[v] + 1;
        q.push(u);
      }
  }
  for (int i = 1; i <= n; i++) mnd[i]--;
}
int f[N];
bool solve(int q) {
  for (int i = 1; i <= n; i++) {
    if (mnd[i] != -1) {
      nget[i] = mnd[i];
      give[i] = q - mnd[i];
    }
    f[i] = -1;
  }
  set<pair<int, int> > s;
  s.insert({-give[st], st});
  f[st] = give[st];
  while (s.size()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    for (auto u : ad[v]) {
      int t = f[v] - 1;
      if (t == -1 || f[u] > -1 || t < nget[u]) continue;
      f[u] = give[u];
      s.insert({-give[u], u});
    }
  }
  for (int i = 1; i <= n; i++)
    if (ded[i] != -1 && ded[i] < f[i]) return 1;
  return 0;
}
void bfsed() {
  queue<int> q;
  q.push(ed);
  ded[ed] = 1;
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (auto u : ad[v])
      if (!ded[u]) {
        ded[u] = ded[v] + 1;
        q.push(u);
      }
  }
  for (int i = 1; i <= n; i++) ded[i]--;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int v;
    scanf("%d", &v);
    star[v] = 1;
  }
  while (m--) {
    int v, u;
    scanf("%d%d", &v, &u);
    ad[v].push_back(u);
    ad[u].push_back(v);
  }
  scanf("%d%d", &st, &ed);
  bfsstar();
  bfsed();
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int md = (r + l) / 2;
    if (solve(md))
      r = md;
    else
      l = md;
  }
  if (r == n + 1)
    printf("%d", -1);
  else
    printf("%d", r);
  return 0;
}
