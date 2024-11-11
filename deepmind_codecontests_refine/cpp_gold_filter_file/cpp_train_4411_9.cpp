#include <bits/stdc++.h>
using namespace std;
long long int inf = 100000000000;
map<long long, map<long long, long long> > w, b;
vector<long> a[100004];
long long int d[100004];
long long int z[100004];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long n, m;
  cin >> n >> m;
  long long int u, v, x;
  for (long i = 0; i < m; i++) {
    cin >> u >> v >> x;
    b[u][v] = x;
    b[v][u] = x;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  long k;
  for (long i = 1; i <= n; i++) {
    cin >> k;
    d[i] = inf;
    for (long j = 1; j <= k; j++) {
      cin >> z[j];
    }
    if (k != 0) w[i][z[k]] = 1;
    for (long j = k - 1; j >= 1; j--) {
      if (z[j] + 1 == z[j + 1])
        w[i][z[j]] = w[i][z[j + 1]] + 1;
      else
        w[i][z[j]] = 1;
    }
  }
  d[1] = 0;
  set<pair<long, long> > s;
  set<pair<long, long> >::const_iterator r;
  s.insert(make_pair(0, 1));
  while (!s.empty()) {
    r = s.begin();
    pair<long, long> e = *r;
    s.erase(r);
    long i = e.first;
    long j = e.second;
    for (long k = 0; k < a[j].size(); k++) {
      long h = a[j][k];
      long long int p = w[j][i] + i + b[j][h];
      if (p < d[h]) {
        s.erase(make_pair(d[h], h));
        d[h] = p;
        s.insert(make_pair(d[h], h));
      }
    }
  }
  if (d[n] == inf)
    cout << "-1" << endl;
  else
    cout << d[n] << endl;
}
