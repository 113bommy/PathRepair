#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 5;
int n, m, p, q, root[N];
long long sum[N];
int getroot(int u) { return u == root[u] ? u : root[u] = getroot(root[u]); }
void join(int u, int v) {
  u = getroot(u);
  v = getroot(v);
  if (u != v) {
    sum[u] += sum[v];
    root[v] = u;
  }
}
int main() {
  cin >> n >> m >> p >> q;
  for (int i = (1); i <= (n); ++i) root[i] = i;
  for (int zz = 0; zz < (m); ++zz) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    join(u, v);
    sum[getroot(u)] += w;
  }
  int rootcnt = 0;
  for (int i = (1); i <= (n); ++i) rootcnt += (root[i] == i);
  int maxcomp;
  if (rootcnt < n)
    maxcomp = rootcnt;
  else if (p > 0)
    maxcomp = n - 1;
  else
    maxcomp = n;
  if (maxcomp < q || p < rootcnt - q) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  priority_queue<pair<long long, int> > pq;
  for (int i = (1); i <= (n); ++i)
    if (root[i] == i) pq.push(make_pair(-sum[i], i));
  for (int zz = 0; zz < (rootcnt - q); ++zz) {
    int u = pq.top().second;
    pq.pop();
    int v = pq.top().second;
    pq.pop();
    printf("%d %d\n", u, v);
    long long s = sum[getroot(u)] + sum[getroot(v)];
    s = min<long long>(s, 1e9);
    join(u, v);
    u = getroot(u);
    sum[u] += s;
    pq.push(make_pair(-sum[u], u));
  }
  p -= rootcnt - q;
  for (int i = (1); i <= (n); ++i)
    if (getroot(i) != i) {
      for (int j = 0; j < (p); ++j) {
        printf("%d %d\n", i, getroot(i));
      }
      break;
    }
  return 0;
}
