#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 2, maxm = 1000 * 1000 + 2;
int n, m, q, parent[maxn], r[maxn], b[maxn];
pair<pair<long long, int>, pair<int, int> > v[maxm];
bool chek = false;
int par(int x) {
  if (x == parent[x]) return x;
  int y = par(parent[x]);
  b[x] += b[y];
  b[x] %= 2;
  return parent[x] = y;
}
void merge(int x, int y) {
  int second = x, e = y;
  x = par(x);
  y = par(y);
  if (x == y) {
    if (b[second] == b[e]) chek = true;
    return;
  }
  if (r[x] < r[y]) {
    swap(x, y);
    swap(second, e);
  }
  r[x] += r[y];
  parent[y] = x;
  b[y] = (b[e] + 1 + b[second]) % 2;
}
int main() {
  ios::sync_with_stdio(false);
  int x, y, second, e;
  long long z;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    x--;
    y--;
    v[i] = make_pair(make_pair(z, i + 1), make_pair(x, y));
  }
  sort(v, v + m);
  reverse(v, v + m);
  for (int t = 0; t < q; t++) {
    chek = false;
    cin >> second >> e;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      r[i] = 1;
      b[i] = 0;
    }
    for (int i = 0; i < m; i++)
      if (v[i].first.second >= second && v[i].first.second <= e) {
        x = v[i].second.first;
        y = v[i].second.second;
        z = v[i].first.first;
        merge(x, y);
        if (chek == true) {
          cout << z << endl;
          break;
        }
      }
    if (chek == false) cout << -1 << endl;
  }
  return 0;
}
