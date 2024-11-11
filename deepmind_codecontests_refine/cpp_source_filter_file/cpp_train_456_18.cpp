#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 50;
struct edge {
  int a, b, l, r;
  edge() {}
  edge(int _a, int _b, int _l, int _r) {
    a = _a;
    b = _b;
    l = _l;
    r = _r;
  }
};
int n, m, parent[maxN], size[maxN], ans;
int a[maxN * 3], b[maxN * 3], l[maxN * 3], r[maxN * 3];
vector<pair<int, int> > e;
int find(int x) {
  if (parent[x] == x) return x;
  int t = find(parent[x]);
  parent[x] = t;
  return t;
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (size[x] > size[y]) swap(x, y);
  if (x == y) return;
  size[y] += size[x];
  parent[x] = y;
}
bool comp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> l[i] >> r[i];
    e.push_back(make_pair(r[i], i));
  }
  sort(e.begin(), e.end(), comp);
  for (int i = 0; i < m; i++) {
    int k = r[i];
    for (int j = 1; j <= n; j++) {
      parent[j] = j;
      size[j] = 1;
    }
    for (int j = 0; j < m; j++) {
      int id = e[j].second;
      if (l[id] > k) continue;
      if (r[id] >= k) {
        merge(a[id], b[id]);
        k = min(k, r[id]);
      }
      if (find(n) == find(1)) ans = max(ans, k - l[i] + 1);
    }
  }
  if (ans != 0)
    cout << ans << endl;
  else
    cout << "Nice work, Dima!" << endl;
  return 0;
}
