#include <bits/stdc++.h>
using namespace std;
template <typename T>
T input() {
  T ans = 0, m = 1;
  char c = ' ';
  while (!((c >= '0' && c <= '9') || c == '-')) c = getchar();
  if (c == '-') m = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + (c - '0'), c = getchar();
  }
  return ans * m;
}
template <typename T>
void read(T& a) {
  a = input<T>();
}
template <typename T, typename... R>
void read(T& a, R&... r) {
  a = input<T>();
  read(r...);
}
const int N = 1e3 + 12;
const int M = 1e4 + 12;
const long long INF = 2e18;
int x[M], y[M], w[M];
bool emp[M];
long long dist1[N], dist2[N];
vector<int> g[N];
int n, m, L, s, t;
long long need;
void dijk(long long* dist, bool fl) {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  dist[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int v = q.top().second;
    long long d = q.top().first;
    q.pop();
    if (d > dist[v]) continue;
    for (auto i : g[v]) {
      int u = x[i] + y[i] - v;
      if (fl && emp[i] && d + w[i] < dist[u] && d + w[i] < dist1[u] + need) {
        w[i] = dist1[u] + need - d;
      }
      if (d + w[i] < dist[u]) {
        dist[u] = d + w[i];
        q.push({dist[u], u});
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  read(n, m, L, s, t);
  for (int i = 0; i < m; ++i) {
    read(x[i], y[i], w[i]);
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
    if (!w[i]) {
      emp[i] = w[i] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    dist1[i] = dist2[i] = INF;
  }
  dijk(dist1, 0);
  if (dist1[t] > L) {
    cout << "NO\n";
    return 0;
  }
  need = L - dist1[t];
  dijk(dist2, 1);
  if (dist2[t] != L) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < m; ++i) {
    cout << x[i] << " " << y[i] << " " << w[i] << "\n";
  }
}
