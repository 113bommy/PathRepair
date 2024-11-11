#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > v(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      v[i].push_back(x);
    };
  }
  int a, b;
  cin >> a >> b;
  int mi = 1000000, h;
  for (int i = 0; i + a < n; ++i) {
    for (int j = 0; j + b <= m; ++j) {
      h = 0;
      for (int ii = i; ii <= i + a; ++ii) {
        for (int jj = j; jj < j + b; ++jj) {
          h += v[ii][jj];
        };
      };
      if (h < mi) {
        mi = h;
      };
    };
  };
  swap(a, b);
  for (int i = 0; i + a <= n; ++i) {
    for (int j = 0; j + b <= m; ++j) {
      h = 0;
      for (int ii = i; ii < i + a; ++ii) {
        for (int jj = j; jj < j + b; ++jj) {
          h += v[ii][jj];
        };
      };
      if (h < mi) {
        mi = h;
      };
    };
  };
  cout << mi;
  return 0;
};
