#include <bits/stdc++.h>
using namespace std;
int const N = int(1e5) + 7;
int const mod = int(1e9) + 7;
int a[505][505];
int b[505][505];
map<int, int> cnta;
map<int, int> cntb;
bool check(int d, int n, int m) {
  cnta.clear();
  cntb.clear();
  for (int r = 0; r < n; ++r) {
    int c = d - r;
    if (0 <= c && c < m) {
      ++cnta[a[r][c]];
      ++cntb[b[r][c]];
    }
  }
  if (cnta.size() != cntb.size()) return false;
  auto itb = cntb.begin();
  for (auto ita = cnta.begin(); ita != cnta.end(); ++ita) {
    if ((*ita).first != (*itb).first || (*ita).second != (*itb).second)
      return false;
    ++itb;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  ifstream in("input.txt");
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }
  for (int i = 0; i < 2 * n - 1; ++i) {
    if (!check(i, n, m)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
