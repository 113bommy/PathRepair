#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool mark[1005];
vector<long long> e;
long long dis[2 * 1005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    long long t;
    cin >> t;
    mark[t] = true;
  }
  for (long long i = 1; i <= 1000; i++) {
    if (mark[i]) {
      e.push_back(i - n);
    }
  }
  memset(dis, 127, sizeof(dis));
  queue<pair<long long, long long> > q;
  q.push(make_pair(1000, 0));
  while (!q.empty()) {
    long long u = q.front().first;
    long long d = q.front().second;
    q.pop();
    for (long long i = 0; i < e.size(); i++) {
      long long v = u + e[i];
      if (0 <= v && v <= 2000 && dis[v] > d + 1) {
        dis[v] = d + 1;
        q.push(make_pair(v, d + 1));
      }
    }
  }
  if (dis[1000] > 1e9)
    cout << -1 << '\n';
  else
    cout << dis[1000] << '\n';
}
