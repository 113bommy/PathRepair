#include <bits/stdc++.h>
using namespace std;
bool compare(pair<pair<pair<long long, long long>, pair<long long, long long> >,
                  long long> &a,
             pair<pair<pair<long long, long long>, pair<long long, long long> >,
                  long long> &b) {
  if (a.first.first.first < b.first.first.first)
    return true;
  else if (a.first.first.first > b.first.first.first)
    return false;
  else
    return a.first.second.first < b.first.second.first;
}
long long find(long long parent[], long long u) {
  if (parent[u] == u)
    return u;
  else {
    parent[u] = find(parent, parent[u]);
    return parent[u];
  }
}
vector<long long> mst;
pair<long long, long long> kruskal(
    pair<pair<pair<long long, long long>, pair<long long, long long> >,
         long long>
        edges[],
    long long m, long long n, long long k, long long mid) {
  mst.clear();
  for (long long i = 0; i < m; i++) {
    if (edges[i].first.second.first == 0)
      edges[i].first.first.first = edges[i].first.first.second + mid;
    else
      edges[i].first.first.first = edges[i].first.first.second;
  }
  sort(edges, edges + m, compare);
  long long parent[n];
  for (long long i = 0; i < n; i++) parent[i] = i;
  long long cnt = 0, ans = 0;
  for (long long i = 0; i < m && cnt < n - 1; i++) {
    long long one;
    if (edges[i].first.second.first == 0)
      one = 1;
    else
      one = 0;
    long long x = find(parent, edges[i].first.second.first);
    long long y = find(parent, edges[i].first.second.second);
    if (x != y && (ans + one) <= k) {
      ans += one;
      parent[x] = y;
      cnt++;
      mst.push_back(edges[i].second);
    }
  }
  return {ans, cnt};
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  while (tt--) {
    long long n, m, k;
    cin >> n >> m >> k;
    pair<pair<pair<long long, long long>, pair<long long, long long> >,
         long long>
        edges[m];
    for (long long i = 0; i < m; i++) {
      cin >> edges[i].first.second.first >> edges[i].first.second.second >>
          edges[i].first.first.first;
      edges[i].first.second.first--, edges[i].first.second.second--;
      if (edges[i].first.second.first > edges[i].first.second.second) {
        long long t = edges[i].first.second.first;
        edges[i].first.second.first = edges[i].first.second.second;
        edges[i].first.second.second = t;
      }
      edges[i].first.first.second = edges[i].first.first.first;
      edges[i].second = i + 1;
    }
    pair<long long, long long> z = kruskal(edges, m, n, k, -100000);
    if (z.first < k || z.second < n - 1)
      cout << -1 << endl;
    else {
      long long l = -100000, r = 100000;
      while (l < r) {
        long long mid = (l + r + 1) / 2;
        z = kruskal(edges, m, n, k, mid);
        if (z.first > k)
          l = mid;
        else
          r = mid - 1;
      }
      kruskal(edges, m, n, k, l);
      cout << mst.size() << endl;
      for (long long i = 0; i < mst.size(); i++) cout << mst[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
