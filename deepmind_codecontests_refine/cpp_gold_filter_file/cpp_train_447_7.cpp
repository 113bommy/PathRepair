#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n);
  for (int i = 0; i < int((a).size()); ++i) a[i].resize(n);
  for (int i = 0; i < int((a).size()); ++i)
    for (int j = 0; j < int((a[i]).size()); ++j) cin >> a[i][j];
  int r = 0;
  for (int i = 0; i < int((a).size()); ++i)
    for (int j = 0; j < int((a[i]).size()); ++j) {
      int c1 = 0, c2 = 0;
      for (int t = 0; t < (n); ++t) {
        c1 += a[i][t];
        c2 += a[t][j];
      }
      if (c2 > c1) ++r;
    }
  cout << r << endl;
  return 0;
}
