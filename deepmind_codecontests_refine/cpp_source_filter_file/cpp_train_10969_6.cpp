#include <bits/stdc++.h>
using namespace std;
const long long nmax = 405, inf = 1e13;
long long dist[nmax][nmax];
double calc(double a, double b, double l) {
  if (a + l < b) return b;
  if (b + l < a) return a;
  return (a + b + l) / 2.0;
}
double opt(vector<pair<long long, long long> > arr, long long len) {
  sort(arr.rbegin(), arr.rend());
  double ans = inf;
  long long bmax = 0;
  for (long long i = 0; i < arr.size(); ++i) {
    ans = min(ans, calc(arr[i].first, bmax, len));
    bmax = max(bmax, arr[i].second);
  }
  ans = min(ans, calc(0, bmax, len));
  return ans;
}
int main() {
  for (long long i = 0; i < nmax; ++i)
    for (long long j = 0; j < nmax; ++j) dist[i][j] = inf;
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) dist[i][i] = 0;
  vector<long long> A(m), B(m), LEN(m);
  for (long long i = 0; i < m; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    A[i] = a, B[i] = b, LEN[i] = c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }
  for (long long k = 1; k <= n; ++k)
    for (long long i = 1; i <= n; ++i)
      for (long long j = 1; j <= m; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  double ans = inf;
  for (long long i = 0; i < m; ++i) {
    long long a = A[i], b = B[i], c = LEN[i];
    vector<pair<long long, long long> > arr(n + 1);
    for (long long j = 1; j <= n; ++j) {
      arr[j].first = dist[a][j];
      arr[j].second = dist[b][j];
    }
    ans = min(ans, opt(arr, c));
  }
  cout << fixed << setprecision(12);
  cout << ans << '\n';
}
