#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rnd(time(nullptr));
const int N = 2e5 + 5;
long long a[N], b[N];
int pr[N], sz[N];
int get(int v) {
  if (pr[v] == v) return v;
  return pr[v] = get(pr[v]);
}
void add(int a, int b) {
  a = get(a), b = get(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    pr[b] = a, sz[a] += sz[b];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n + m; ++i) pr[i] = i, sz[i] = 1;
  vector<pair<long long, pair<int, int>>> edg;
  for (int i = 1; i <= m; ++i) {
    int s;
    cin >> s;
    while (s--) {
      int v;
      cin >> v;
      edg.push_back({a[i] + b[v], {i, v + m}});
    }
  }
  long long ans = 0;
  sort(edg.begin(), edg.end(), greater<pair<long long, pair<int, int>>>());
  for (auto cur : edg) {
    if (get(cur.second.first) == get(cur.second.second)) ans += cur.first;
    add(cur.second.first, cur.second.second);
  }
  cout << ans;
}
