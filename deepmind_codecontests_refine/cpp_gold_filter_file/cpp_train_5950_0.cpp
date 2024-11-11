#include <bits/stdc++.h>
using namespace std;
const int nmax = 100005;
pair<long long, long long> v[nmax], st[nmax];
int n, i, u;
long long det(pair<long long, long long> a, pair<long long, long long> b,
              pair<long long, long long> c) {
  return a.first * b.second + b.first * c.second + c.first * a.second -
         a.second * b.first - b.second * c.first - c.second * a.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> v[i].first >> v[i].second;
    v[i].second -= 1LL * v[i].first * v[i].first;
  }
  sort(v + 1, v + n + 1);
  for (i = 1; i <= n; i++) {
    while (u >= 1 && v[i].first == st[u].first) u--;
    while (u >= 2 && det(st[u - 1], st[u], v[i]) >= 0) u--;
    st[++u] = v[i];
  }
  cout << u - 1;
  return 0;
}
