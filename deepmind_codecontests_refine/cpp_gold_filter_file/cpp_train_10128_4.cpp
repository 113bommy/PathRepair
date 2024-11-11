#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1000000001, INF = (ll)1e18 + 1;
void put(int a, int b, int c, int d, int e, int f, vector<vector<int> > &opps,
         vector<vector<int> > &v) {}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  vector<vector<int> > opps;
  for (int i = n - 1; i >= 2; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (a[i][j]) {
        opps.push_back({i, j, i - 1, j, i - 1, !j ? j + 1 : j - 1});
        a[i][j] ^= 1;
        a[i - 1][j] ^= 1;
        a[i - 1][!j ? j + 1 : j - 1] ^= 1;
      }
    }
  }
  for (int j = m - 1; j >= 2; j--) {
    if (a[0][j] && a[1][j]) {
      opps.push_back({0, j, 1, j, 0, j - 1});
      a[0][j] ^= 1;
      a[1][j] ^= 1;
      a[0][j - 1] ^= 1;
    } else if (a[0][j]) {
      opps.push_back({0, j, 1, j - 1, 0, j - 1});
      a[0][j] ^= 1;
      a[1][j - 1] ^= 1;
      a[0][j - 1] ^= 1;
    } else if (a[1][j]) {
      opps.push_back({1, j, 1, j - 1, 0, j - 1});
      a[1][j] ^= 1;
      a[1][j - 1] ^= 1;
      a[0][j - 1] ^= 1;
    }
  }
  if (a[0][0] ^ a[0][1] ^ a[1][0]) {
    opps.push_back({0, 0, 0, 1, 1, 0});
  }
  if (a[0][0] ^ a[0][1] ^ a[1][1]) {
    opps.push_back({0, 0, 0, 1, 1, 1});
  }
  if (a[0][0] ^ a[1][1] ^ a[1][0]) {
    opps.push_back({0, 0, 1, 1, 1, 0});
  }
  if (a[1][1] ^ a[0][1] ^ a[1][0]) {
    opps.push_back({1, 1, 0, 1, 1, 0});
  }
  cout << opps.size() << endl;
  for (vector<int> i : opps) {
    for (int j : i) cout << j + 1 << " ";
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
