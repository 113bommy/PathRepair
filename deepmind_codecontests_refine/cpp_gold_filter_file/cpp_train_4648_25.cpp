#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 2e5 + 5, sz = 500;
int n, arr[N], sq;
list<int> b[sz][105];
void updatel(int li, int l, int r, int x, int y) {
  for (auto it = b[li][x].begin(); it != b[li][x].end();) {
    auto tmp = it;
    tmp++;
    if (*it >= l && *it <= r) b[li][y].splice(b[li][y].end(), b[li][x], it);
    it = tmp;
  }
}
void update(int l, int r, int x, int y) {
  int li = l / sq, ri = r / sq;
  updatel(li, l, r, x, y);
  if (li == ri) return;
  for (int i = li + 1; i < ri; i++) {
    b[i][y].splice(b[i][y].end(), b[i][x]);
  }
  updatel(ri, l, r, x, y);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  sq = ceil(sqrt(n));
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    b[i / sq][arr[i]].push_back(i);
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (x == y) continue;
    l--, r--;
    update(l, r, x, y);
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j * sq < n; j++) {
      if (b[j][i].size()) {
        for (auto it : b[j][i]) arr[it] = i;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << arr[i] << ' ';
  return 0;
}
