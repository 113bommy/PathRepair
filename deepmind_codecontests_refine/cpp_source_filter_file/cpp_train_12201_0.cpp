#include <bits/stdc++.h>
using namespace std;
long long dsu[2001];
long long sz[1001];
long long getParent(long long x) {
  while (dsu[x] != x) x = dsu[x];
  return x;
}
void merge(long long x, long long y) {
  int rootx = getParent(x);
  int rooty = getParent(y);
  if (sz[rootx] > sz[rooty]) {
    sz[rootx] += sz[rooty];
    dsu[rooty] = rootx;
  } else {
    sz[rooty] += sz[rootx];
    dsu[rootx] = getParent(rooty);
  }
}
int main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  long long cost[n];
  for (long long i = 0; i < n; i++) cin >> cost[i];
  long long k[n];
  for (long long i = 0; i < n; i++) cin >> k[i];
  vector<vector<long long> > edges;
  for (long long i = 0; i < n; i++) {
    vector<long long> edge = {cost[i], 0, i + 1};
    edges.push_back(edge);
    for (long long j = i + 1; j < n; j++) {
      edge = {(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) *
                  (k[i] + k[j]),
              i + 1, j + 1};
      edges.push_back(edge);
    }
  }
  for (long long i = 0; i < n + 1; i++) dsu[i] = i, sz[i] = 1;
  sort(edges.begin(), edges.end());
  long long ans = 0;
  vector<long long> stations;
  vector<pair<long long, long long> > pipes;
  for (int i = 0; i < edges.size(); i++)
    if (getParent(edges[i][1]) != getParent(edges[i][2])) {
      merge(edges[i][1], edges[i][2]);
      ans += edges[i][0];
      if (edges[i][1] == 0)
        stations.push_back(edges[i][2]);
      else
        pipes.push_back({edges[i][1], edges[i][2]});
    }
  cout << ans << '\n';
  cout << stations.size() << '\n';
  for (auto station : stations) cout << station << '\n';
  cout << pipes.size() << '\n';
  for (auto pipe : pipes) cout << pipe.first << " " << pipe.second << '\n';
}
