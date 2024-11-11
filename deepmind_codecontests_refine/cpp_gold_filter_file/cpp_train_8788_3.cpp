#include <bits/stdc++.h>
using namespace std;
long long dist[100001];
bool done[100001];
void dijkstra(long long source, vector<pair<long long, long long> > ed[],
              long long v) {
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      pq;
  for (long long i = 0, _n = (v); i < _n; i++) {
    dist[i + 1] = 1000000000000000;
    done[i + 1] = false;
  }
  dist[source] = {0};
  pq.push(make_pair(0, source));
  while (!pq.empty()) {
    long long minKey = pq.top().second;
    pq.pop();
    for (long long j = 0, _n = (ed[minKey].size()); j < _n; j++) {
      long long a = minKey;
      long long b = ed[a][j].first;
      long long w = ed[a][j].second;
      if (!done[b] && dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w;
        pq.push(make_pair(dist[b], b));
      }
    }
    done[minKey] = true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  long long c[n];
  long long f[n + 1];
  long long p1 = 1;
  long long re[k + 1];
  re[1] = 1;
  for (long long i = 0, _n = (k); i < _n; i++) {
    cin >> c[i];
    for (long long j = 0, _n = (c[i]); j < _n; j++) {
      f[p1] = i + 1;
      p1++;
    }
  }
  for (long long i = (2), _b = (k); i <= _b; i++) {
    re[i] = re[i - 1] + c[i - 1];
  }
  vector<pair<long long, long long> > ed[n + 1];
  for (long long i = 0, _n = (m); i < _n; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    ed[u].push_back(make_pair(v, w));
    ed[v].push_back(make_pair(u, w));
  }
  for (long long i = (1), _b = (k); i <= _b; i++) {
    if (!done[re[i]]) dijkstra(re[i], ed, n);
  }
  long long hu = true;
  p1 = 1;
  for (long long i = 0, _n = (k); i < _n; i++) {
    long long x = dist[p1];
    for (long long j = 0, _n = (c[i]); j < _n; j++) {
      if (dist[p1] != x) {
        hu = false;
      }
      p1++;
    }
  }
  if (!hu) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  long long mat[k + 1][k + 1];
  for (long long i = 0, _n = (k + 1); i < _n; i++) {
    for (long long j = 0, _n = (k + 1); j < _n; j++) {
      mat[i][j] = 1000000000000000;
    }
  }
  for (long long i = 0, _n = (k + 1); i < _n; i++) {
    mat[i][i] = 0;
  }
  for (long long i = (1), _b = (n); i <= _b; i++) {
    for (long long j = 0, _n = (ed[i].size()); j < _n; j++) {
      long long x = i;
      long long y = ed[i][j].first;
      long long w = ed[i][j].second;
      if (mat[f[x]][f[y]] > w) mat[f[x]][f[y]] = w;
    }
  }
  long long dp[k + 1][k + 1];
  for (long long i = 0, _n = (k); i < _n; i++) {
    for (long long j = 0, _n = (k); j < _n; j++) {
      dp[i + 1][j + 1] = mat[i + 1][j + 1];
    }
  }
  for (long long l = 0, _n = (k); l < _n; l++) {
    for (long long i = 0, _n = (k); i < _n; i++) {
      for (long long j = 0, _n = (k); j < _n; j++) {
        dp[i + 1][j + 1] =
            min(dp[i + 1][j + 1], dp[i + 1][l + 1] + dp[l + 1][j + 1]);
      }
    }
  }
  for (long long i = 0, _n = (k); i < _n; i++) {
    for (long long j = 0, _n = (k); j < _n; j++) {
      if (dp[i + 1][j + 1] >= 10000000000)
        cout << "-1 ";
      else
        cout << dp[i + 1][j + 1] << " ";
    }
    cout << endl;
  }
}
