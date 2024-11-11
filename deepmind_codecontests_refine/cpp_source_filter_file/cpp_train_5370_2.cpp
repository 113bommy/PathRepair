#include <bits/stdc++.h>
using namespace std;
const int maxn = 2002;
const long long inf = 1000 * 1000 * 1000;
long long a[maxn][maxn], dist[maxn];
set<pair<long long, int> > s;
bool mark[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long mn = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      cin >> a[i - 1][i + j - 1];
      a[i + j - 1][i - 1] = a[i - 1][i + j - 1];
      mn = min(mn, a[i - 1][i + j - 1]);
    }
    dist[i - 1] = inf;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        a[i][j] -= mn;
        dist[i] = min(dist[i], 2 * a[i][j]);
      }
    }
    s.insert(make_pair(dist[i], i));
  }
  while (!s.empty()) {
    auto it = s.begin();
    int u = it->second;
    mark[u] = 1;
    s.erase(it);
    for (int i = 0; i < n; i++) {
      if (i != u && !mark[i]) {
        s.erase(make_pair(dist[i], i));
        dist[i] = min(dist[i], dist[u] + a[u][i]);
        s.insert(make_pair(dist[i], i));
      }
    }
  }
  int add = mn * (n - 1);
  for (int i = 0; i < n; i++) cout << dist[i] + add << "\n";
}
