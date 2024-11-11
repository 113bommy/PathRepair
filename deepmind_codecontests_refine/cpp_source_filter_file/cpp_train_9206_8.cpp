#include <bits/stdc++.h>
using namespace std;
long long n, m, ar[1005], cu[1005];
vector<vector<int> > adj;
int main(void) {
  cin >> n;
  cin >> m;
  vector<pair<long long, long long> > v;
  adj.clear();
  adj.resize(n + 1, vector<int>());
  for (int x = 1; x <= n; x++) {
    cin >> cu[x];
    v.push_back(make_pair(ar[x], x));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long a, b;
  for (int x = 0; x < m; x++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    ar[a] += cu[b];
    ar[b] += cu[a];
  }
  pair<int, int> par;
  long long total = 0;
  for (int x = 0; x < v.size(); x++) {
    par = v[x];
    total += ar[par.second];
    for (int y = 0; y < adj[par.second].size(); y++) {
      ar[adj[par.second][y]] -= cu[par.second];
    }
  }
  cout << total << "\n";
  return 0;
}
