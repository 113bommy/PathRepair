#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
vector<int> xs(100000), ys(100000);
vector<int> ms(100000);
map<int, int> xsIndexMap;
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> xs[i];
    ys[i] = xs[i];
    xsIndexMap[xs[i]] = i;
  }
  sort(ys.begin(), ys.begin() + n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    int y0 = ys[i];
    int xStart = xsIndexMap[y0];
    int xEnd = xStart + 1;
    while (xEnd < n && xs[xEnd] == ys[i + xEnd - xStart]) {
      ++xEnd;
    }
    i += xEnd - xStart - 1;
    ms[i] = xEnd - xStart;
    ++m;
  }
  bool result = false;
  if (m == k) {
    result = true;
  } else if (m > k) {
    result = false;
  } else {
    int m2 = m;
    for (int i = 0; i < m; ++i) {
      m2 += ms[i] - 1;
    }
    result = (m2 >= k);
  }
  if (result) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int nCases;
  cin >> nCases;
  for (int i = 0; i < nCases; ++i) {
    solve();
  }
  return 0;
}
