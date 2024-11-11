#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 18;
using ll = long long;
map<pair<int, int>, pair<int, int>> cache;
pair<int, int> qry(int l, int r) {
  if (cache.count({l, r})) return cache[{l, r}];
  cout << "? " << l << " " << r << endl;
  int x, f;
  cin >> x >> f;
  return cache[{l, r}] = {x, f};
}
int n, a[1 << 18];
void fill(int l, int r, int c) {
  while (l <= r) a[l++] = c;
}
void solve(int l, int r) {
  if (l > r) return;
  int x, f;
  tie(x, f) = qry(l, r);
  vector<array<int, 2>> ch;
  int gl = 0, gr = 0;
  for (int i = l; i <= r; i += f) {
    int j = min(r, i + f - 1);
    auto [tx, tf] = qry(i, j);
    if (tf == f)
      fill(i, j, tx);
    else {
      ch.push_back({i, j});
      if (x == tx) {
        if (i + tf - 1 <= n && i + tf - 1 - f + 1 >= 1 &&
            qry(i + tf - 1 - f + 1, i + tf - 1) == pair<int, int>{x, f}) {
          gr = i + tf - 1;
          gl = gr - f + 1;
        } else {
          gl = j - tf + 1;
          gr = gl + f - 1;
        }
        fill(gl, gr, x);
      }
    }
  }
  for (auto &i : ch) {
    if (i[0] <= gl && gl <= i[1]) i[1] = gl - 1;
    if (i[0] <= gr && gr <= i[1]) i[0] = gr + 1;
    solve(i[0], i[1]);
  }
}
int main() {
  cin >> n;
  solve(1, n);
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
