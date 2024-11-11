#include <bits/stdc++.h>
using namespace std;
long long n, x, m, ans, fix[1001][1001], parent[10001], fixx[10001];
pair<long long, pair<int, int>> a[10001];
int P(int x) {
  if (parent[x] == x) return x;
  return parent[x] = P(parent[x]);
}
void dsu(int a, int b) {
  a = P(a);
  b = P(b);
  parent[a] = b;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x, parent[i] = i;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].second.first >> a[i].second.second >> a[i].first;
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) {
    if (fixx[a[i].second.second]) continue;
    fixx[a[i].second.second] = 1;
    if (P(a[i].second.first) != P(a[i].second.second)) {
      dsu(a[i].second.first, a[i].second.second);
      ans += a[i].first;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (P(i) != P(1)) {
      cout << "-1";
      return 0;
    }
  }
  cout << ans;
}
