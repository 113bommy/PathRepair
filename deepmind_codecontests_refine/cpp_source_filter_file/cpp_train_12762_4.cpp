#include <bits/stdc++.h>
using namespace std;
long long a[200200];
long long b[200200];
long long p[200200];
multiset<pair<long long, pair<long long, long long>>> x[4];
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    pair<long long, long long> f(min(a[i], b[i]), max(a[i], b[i]));
    pair<long long, pair<long long, long long>> d(p[i], f);
    x[a[i]].insert(d);
    x[b[i]].insert(d);
  }
  long long m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long c;
    cin >> c;
    if (x[c].size() == 0)
      cout << -1;
    else {
      cout << x[c].begin()->first << ' ';
      long long a = x[c].begin()->second.first;
      long long b = x[c].begin()->second.second;
      pair<long long, pair<long long, long long>> k(x[c].begin()->first,
                                                    x[c].begin()->second);
      x[a].erase(x[a].find(k));
      x[b].erase(x[b].find(k));
    }
  }
  return 0;
}
