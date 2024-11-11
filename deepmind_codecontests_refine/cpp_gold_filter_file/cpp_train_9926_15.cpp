#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
int a, b, c, d, i, j, n, m, k;
vector<int> sm[100001], cs[100001], vor[100001];
int p[100001];
long long ds[100001], tr[100001];
int pr[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    q;
bool used[100001], cool[100001];
int main() {
  scanf("%d%d", &n, &m);
  for (int _n((m)-1), i(0); i <= _n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    sm[a].push_back(b);
    sm[b].push_back(a);
    cs[a].push_back(c);
    cs[b].push_back(c);
  }
  scanf("%d", &k);
  for (int _n((k)-1), i(0); i <= _n; i++)
    scanf("%d", &p[i]), --p[i], cool[p[i]] = 1;
  memset(ds, 63, sizeof(ds));
  for (int _n((k)-1), i(0); i <= _n; i++) {
    ds[p[i]] = 0;
    q.push(make_pair(0, p[i]));
    pr[p[i]] = p[i];
  }
  while (!q.empty()) {
    int v = q.top().second;
    long long cd = q.top().first;
    q.pop();
    if (cd != ds[v]) continue;
    for (int _n(((int)((sm[v]).size())) - 1), i(0); i <= _n; i++) {
      int w = sm[v][i];
      if (ds[w] > ds[v] + cs[v][i]) {
        ds[w] = ds[v] + cs[v][i];
        pr[w] = pr[v];
        q.push(make_pair(ds[w], w));
      }
    }
  }
  for (int _n((n)-1), i(0); i <= _n; i++) {
    vor[pr[i]].push_back(i);
  }
  memset(tr, 63, sizeof(tr));
  tr[p[0]] = 0;
  used[p[0]] = 1;
  q.push(make_pair(0, p[0]));
  while (!q.empty()) {
    int v = q.top().second;
    long long cd = q.top().first;
    q.pop();
    if (cd != tr[v]) continue;
    for (int _n(((int)((sm[v]).size())) - 1), i(0); i <= _n; i++) {
      int w = sm[v][i];
      if (tr[w] > tr[v] + cs[v][i]) {
        tr[w] = tr[v] + cs[v][i];
        q.push(make_pair(tr[w], w));
      }
    }
  }
  for (int _n((n)-1), i(0); i <= _n; i++) {
    if (cool[i] && !used[i]) q.push(make_pair(tr[i], i));
  }
  long long ans = ds[0];
  while (!q.empty()) {
    int v = q.top().second;
    long long cd = q.top().first;
    q.pop();
    if (cd != tr[v]) continue;
    ans += cd;
    used[v] = 1;
    for (int _n(((int)((vor[v]).size())) - 1), i(0); i <= _n; i++) {
      int u = vor[v][i];
      for (int _n(((int)((sm[u]).size())) - 1), j(0); j <= _n; j++) {
        int w = sm[u][j];
        if (pr[u] == pr[w]) continue;
        if (used[pr[w]]) continue;
        if (tr[pr[w]] > ds[u] + ds[w] + cs[u][j]) {
          tr[pr[w]] = ds[u] + ds[w] + cs[u][j];
          q.push(make_pair(tr[pr[w]], pr[w]));
        }
      }
    }
  }
  cout << ans << endl;
}
