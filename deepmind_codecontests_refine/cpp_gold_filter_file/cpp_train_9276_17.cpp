#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = (int)(1e9 + 1e6);
const long long LINF = (long long)(4e18);
const double EPS = 1e-9;
const long long mod = 1e9 + 7;
mt19937 ggen;
void solve();
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  ggen = mt19937(1337);
  solve();
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> tr(n);
  for (int i = 0; i < n; ++i) {
    int r;
    cin >> r;
    tr[i].resize(r);
    for (int j = 0; j < r; ++j) {
      cin >> tr[i][j];
    }
  }
  for (int i = 1; i <= 100; ++i) {
    bool an = true;
    for (int j = 0; j < n; ++j) {
      bool fl = false;
      for (auto trs : tr[j]) {
        if (i == trs) {
          fl = true;
          break;
        }
      }
      if (!fl) {
        an = false;
        break;
      }
    }
    if (an) {
      cout << i << " ";
    }
  }
}
