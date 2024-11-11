#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > edge[1 << 20];
long long a[1 << 20];
long long dfs(long long v, long long dist) {
  if (dist > a[v]) return 0;
  long long cnt = 1;
  for (long long i = 0; i < edge[v].size(); i++) {
    cnt += dfs(edge[v][i].first, max(0ll, dist) + edge[v][i].second);
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 2; i <= n; i++) {
    long long temp, temp1;
    cin >> temp >> temp1;
    edge[i].push_back(make_pair(temp, temp1));
  }
  long long rem = dfs(1, 0);
  cout << n - rem;
}
