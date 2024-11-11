#include <bits/stdc++.h>
using namespace std;
int ar[10001];
vector<int> v[51];
map<int, int> mp;
int n, m;
bool func() {
  mp.clear();
  int i, j;
  vector<bitset<10001> > a;
  bitset<10001> b;
  for (i = 0; i < 10001; ++i) b[i] = 0;
  for (i = 1; i <= m; ++i) {
    a.push_back(b);
    for (j = 0; j < v[i].size(); ++j) a[i - 1][v[i][j] - 1] = 1;
  }
  for (i = 0; i < m; ++i) {
    for (j = i + 1; j < m; ++j)
      if ((a[i] & a[j]) == 0) return false;
  }
  return true;
}
int main() {
  std::ios::sync_with_stdio(false);
  int T;
  T = 1;
  while (T--) {
    int i, j, a, b;
    cin >> m >> n;
    for (i = 1; i <= m; ++i) {
      cin >> a;
      while (a--) {
        cin >> b;
        v[i].push_back(b);
        ++ar[b];
      }
    }
    if (func()) {
      cout << "possible" << endl;
      return 0;
    } else {
      cout << "impossible" << endl;
      return 0;
    }
  }
  return 0;
}
