#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 5;
bool Has(vector<int> &a, vector<int> &b) {
  int p1 = 0, p2 = 0;
  int cnt = 0;
  while (p1 < a.size() && p2 < b.size()) {
    if (a[p1] < b[p2])
      ++p1;
    else if (a[p1] > b[p2])
      ++p2;
    else {
      ++p1, ++p2;
      ++cnt;
    }
  }
  return cnt == b.size();
}
int main() {
  int n, m[101];
  cin >> n;
  vector<vector<int> > ret;
  ret.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    ret[i].resize(m[i]);
    for (int j = 0; j < m[i]; ++j) cin >> ret[i][j];
    sort(ret[i].begin(), ret[i].end());
  }
  for (int i = 0; i < n; ++i) {
    bool flag = true;
    for (int j = 0; flag && j < n; ++j) {
      if (i == j) continue;
      if (ret[i].size() < ret[j].size()) continue;
      if (Has(ret[i], ret[j])) flag = false;
    }
    puts(flag ? "YES" : "NO");
  }
  return 0;
}
