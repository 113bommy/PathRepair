#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<long long> > d(n, vector<long long>(m));
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(m); ++j) {
      int a;
      scanf("%d", &a);
      d[i][j] = a;
    }
  for (int i = 0; i < int(n); ++i)
    partial_sum((d[i]).begin(), (d[i]).end(), d[i].begin());
  for (int i = (1); i < int(n); ++i) {
    if (i % 2 == 0) {
      long long g = -100000000000ll;
      for (int j = 0; j < int(m); ++j) {
        d[i][j] += g;
        g = max(g, d[i - 1][j]);
      }
    } else {
      long long g = -100000000000ll;
      for (int j = (m)-1; j >= 0; --j) {
        d[i][j] += g;
        g = max(g, d[i - 1][j]);
      }
    }
  }
  printf("%I64d\n", *max_element((d[n - 1]).begin(), (d[n - 1]).end()));
  return 0;
}
