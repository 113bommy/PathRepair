#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
bitset<4096> q[N];
int n, k, m, type, x, y, sz, a[N][12];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> m;
  sz = n;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < (1 << k); j++) {
      if ((j >> i) & 1) {
        q[i][j] = true;
      }
    }
    for (int j = 0; j < n; j++) {
      cin >> a[j][i];
    }
  }
  while (m--) {
    cin >> type >> x >> y;
    x--, y--;
    if (type == 1) {
      q[sz++] = q[x] | q[y];
    } else if (type == 2) {
      q[sz++] = q[x] & q[y];
    } else {
      vector<pair<int, int> > s;
      for (int i = 0; i < k; i++) {
        s.push_back(make_pair(a[y][i], i));
      }
      sort(s.rbegin(), s.rend());
      int cur = 0;
      for (int i = 0; i < k; i++) {
        cur |= (1 << s[i].second);
        if (q[x][cur]) {
          cout << s[i].first << "\n";
          break;
        }
      }
    }
  }
}
