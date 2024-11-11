#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e18 + 9;
const int INF = 1e9 + 7;
const int SIZE = 2 * 1e5 + 10;
const long long MOD = 1e9 + 7;
int n, m, x, y, z, k, c, r, l;
long long lans;
int ans[5][5];
int toi[5] = {0, 0, 0, 1, -1};
int toj[5] = {0, 1, -1, 0, 0};
string second;
void solve() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> x;
      if (x % 2 == 1)
        for (int to = 0; to < 5; ++to) {
          ans[i + 1 + toi[to]][j + 1 + toj[to]] =
              !ans[i + 1 + toi[to]][j + 1 + toj[to]];
        }
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << !ans[i + 1][j + 1];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
