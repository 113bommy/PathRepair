#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const int MAXN = 300001;
const int MAXMASK = (1 << 12);
bitset<MAXMASK> a[MAXN];
vector<pair<int, int>> orig[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(20);
  cout.tie(nullptr);
  int n, k, q;
  cin >> n >> k >> q;
  for (int i = 1; i <= k; ++i) {
    a[i].reset();
    for (int j = 0; j < MAXMASK; ++j) {
      if (j & (1 << (i - 1))) {
        a[i][j] = true;
      }
    }
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      orig[j].emplace_back(x, i - 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    sort(orig[i].begin(), orig[i].end());
  }
  int c = k;
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[++c] = a[x] & a[y];
    } else if (t == 2) {
      a[++c] = a[x] | a[y];
    } else {
      int curm = 0;
      for (int j = 0; j < k; ++j) {
        if (a[x][curm |= (1 << orig[y][j].second)]) {
          cout << orig[y][j].first << "\n";
          break;
        }
      }
    }
  }
}
