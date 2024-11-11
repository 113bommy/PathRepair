#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, pair<long long, long long>>> v;
long long a, b, w, cnt;
long long parent[100005], sz[100005];
void init(long long n) {
  for (long long i = 1; i <= n; i++) parent[i] = i, sz[i] = 1;
}
long long root(long long x) {
  if (parent[x] == x) return x;
  return parent[x] = root(parent[x]);
}
long long mst(long long n, long long k) {
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long x = v[i].second.first, y = v[i].second.second, z = v[i].first;
    if (x == a && y == b) continue;
    long long px = root(x), py = root(y);
    if (px != py) {
      if (sz[px] < sz[py]) swap(px, py);
      ans += z;
      sz[px] += sz[py];
      parent[py] = px;
      cnt++;
    }
  }
  if (cnt != k) return -1;
  return ans;
}
int main() {
  long long t, n, i, j, m, ans = 0;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (x > y) swap(x, y);
    v.push_back({z, {x, y}});
  }
  a = v[0].second.first, b = v[0].second.second, w = v[0].first;
  sort(v.begin(), v.end());
  init(n);
  cnt = 2;
  sz[a] = 2;
  parent[b] = a;
  long long ans1 = w + mst(m, n);
  init(n);
  cnt = 1;
  long long ans2 = mst(m, n);
  if (ans2 > 0)
    cout << w - (ans1 - ans2);
  else
    cout << 1000000000;
}
