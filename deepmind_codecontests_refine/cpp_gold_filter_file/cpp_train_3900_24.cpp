#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, j, k, x, y, z;
  cin >> n;
  vector<int> v1(n, 0);
  vector<vector<int> > v;
  v.resize(n, v1);
  unordered_map<long long, long long> m1, m2;
  x = 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> x;
      v[i][j] = x;
      m1[i + j] += x;
      m2[i - j] += x;
    }
  }
  long long maxodd = -1, maxeven = -1, x1, y1, x2, y2;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      z = m1[i + j] + m2[i - j] - v[i][j];
      if ((i + j) % 2 == 0) {
        if (z > maxeven) {
          maxeven = z;
          x1 = i + 1;
          y1 = j + 1;
        }
      } else {
        if (z > maxodd) {
          maxodd = z;
          x2 = i + 1;
          y2 = j + 1;
        }
      }
    }
  }
  cout << maxeven + maxodd << "\n";
  cout << x1 << " " << y1 << " " << x2 << " " << y2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t-- > 0) {
    solve();
  }
}
