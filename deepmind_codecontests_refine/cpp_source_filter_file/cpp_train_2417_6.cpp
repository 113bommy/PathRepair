#include <bits/stdc++.h>
using namespace std;
long long X[2509], Y[2509];
bool crs(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.second - a.second * b.first < 0;
}
long long q(pair<long long, long long> a) {
  if (a.first >= 0 || (a.first == 0 && a.second > 0))
    return 1;
  else
    return 2;
}
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (q(a) == q(b))
    return crs(a, b);
  else
    return q(a) < q(b);
}
long long x[1009], y[1009];
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long c = 0;
    vector<pair<long long, long long> > v;
    for (long long j = 1; j <= n; j++) {
      if (j != i) v.push_back({x[j] - x[i], y[j] - y[i]});
    }
    sort(v.begin(), v.end(), comp);
    long long u = 1;
    long long A = ((long long)(n - 1)) * (n - 2) * (n - 3) / 6;
    for (long long j = 0; j < v.size(); j++) {
      while (u != j && crs(v[j], v[u])) u = (u + 1) % (n - 1);
      long long t = (u - j + n - 2 + n - 1) % (n - 1);
      A -= t * (t - 1) / 2;
    }
    ans += A * (n - 4) / 2;
  }
  cout << ans << endl;
}
