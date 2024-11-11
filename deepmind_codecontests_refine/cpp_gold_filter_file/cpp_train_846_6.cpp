#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n, i, j, a[maxn], res(0), b[maxn], c[maxn], kt[maxn], x, y;
set<int> s;
void read() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    cin >> b[i];
    kt[b[i]]++;
    s.insert(b[i]);
  }
}
void solve() {
  for (i = 1; i <= n; i++) {
    auto p = s.lower_bound(n - a[i]);
    auto q = s.begin();
    x = *p;
    y = *q;
    if (s.end() == p) x = y;
    if ((x + a[i]) % n < (y + a[i]) % n) {
      c[i] = (x + a[i]) % n;
      if (kt[x] != 0) kt[x]--;
      if (kt[x] == 0) s.erase(x);
    } else {
      c[i] = (y + a[i]) % n;
      if (kt[y] != 0) kt[y]--;
      if (kt[y] == 0) s.erase(y);
    }
  }
  for (i = 1; i <= n; i++) cout << c[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read();
  solve();
}
