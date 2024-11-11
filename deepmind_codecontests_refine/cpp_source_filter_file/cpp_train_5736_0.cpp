#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int lim, offset;
unordered_map<int, int> fa[600 * 1000 + 30];
void add(int x, int y) {
  for (int i = x; i <= lim; i += (i & -i))
    for (int j = y; j <= lim; j += (j & -j)) ++fa[i][j];
}
int query(int x, int y) {
  int sum = 0;
  for (int i = x; i > 0; i -= (i & -i))
    for (int j = y; j > 0; j -= (j & -j)) sum += fa[i][j];
  return sum;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i] = (x <= m);
    b[i] = (x >= m);
  }
  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
    b[i] += b[i - 1];
  }
  offset = n + 10;
  lim = offset + 2 * n + 10;
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    int x = offset + 2 * a[i] - i - 1;
    int y = offset + 2 * b[i] - i - 1;
    ans += query(x, y);
    add(x, y);
  }
  cout << ans;
}
