#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector<pair<long long, long long> > pr;
struct pl {
  long long a[101];
  long long b[101];
  long long c[101];
} plt[11];
long long cont(pl x, pl y) {
  pr.clear();
  for (long long i = 1; i <= m; i++) {
    long long d = y.b[i] - x.a[i];
    pr.push_back({d, x.c[i]});
  }
  sort(pr.rbegin(), pr.rend());
  long long r = k;
  long long s = 0;
  long long i = 0;
  while (r) {
    long long mn = min(pr[i].second, r);
    r -= mn;
    if (pr[i].first <= 0) break;
    s += mn * pr[i].first;
    i++;
    if (i >= m) break;
  }
  return s;
}
int main() {
  long long i, j, s1, d, r, s2;
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    string line;
    cin >> line;
    for (j = 1; j <= m; j++) {
      cin >> plt[i].a[j] >> plt[i].b[j] >> plt[i].c[j];
    }
  }
  long long mx = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == j) continue;
      mx = max(cont(plt[i], plt[j]), mx);
    }
  }
  cout << mx << endl;
}
