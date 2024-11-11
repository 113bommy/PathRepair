#include <bits/stdc++.h>
using namespace std;
long long const inf = 1e15;
int32_t main() {
  long long n, m;
  cin >> n >> m;
  set<pair<long long, long long>> s;
  vector<long long> len(n, inf);
  vector<vector<long long>> al(n);
  vector<vector<long long>> w(n);
  vector<map<long long, long long>> arrive(n);
  for (long long i = 0; i < m; ++i) {
    long long a, b, time;
    cin >> a >> b >> time;
    --a;
    --b;
    al[a].push_back(b);
    al[b].push_back(a);
    w[a].push_back(time);
    w[b].push_back(time);
  }
  for (long long i = 0; i < n; ++i) {
    long long k;
    cin >> k;
    vector<long long> inv;
    for (long long j = 0; j < k; ++j) {
      long long x;
      cin >> x;
      inv.push_back(x);
    }
    long long count = 0;
    long long prev = inf;
    for (long long j = k - 1; j >= 0; --j) {
      if (inv[j] == prev - 1)
        ++count;
      else
        count = 0;
      arrive[i][inv[j]] = count;
      prev = inv[j];
    }
  }
  long long shit = arrive[0][0];
  s.insert(make_pair(shit, 0));
  len[0] = shit;
  while (!s.empty()) {
    auto it = s.begin();
    pair<long long, long long> p = *it;
    long long v = p.second;
    s.erase(it);
    for (long long i = 0; i < al[v].size(); ++i) {
      long long to = al[v][i];
      long long delay = 0;
      if (to != n - 1) delay = arrive[to][len[v] + w[v][i]];
      if (len[v] + w[v][i] + delay < len[to]) {
        if (len[to] != inf) s.erase(s.find(make_pair(len[to], to)));
        len[to] = len[v] + w[v][i] + delay;
        s.insert(make_pair(len[to], to));
      }
    }
  }
  if (len[n - 1] != inf)
    cout << len[n - 1] << ' ';
  else
    cout << -1 << ' ';
  return 0;
}
