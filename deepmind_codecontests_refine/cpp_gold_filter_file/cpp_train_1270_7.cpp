#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, val;
  scanf("%d", &n);
  vector<vector<int> > vec;
  vec.assign(n + 1, vector<int>());
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    vec[val].push_back(i);
  }
  int res = 100000000;
  for (int i = 1; i <= n; i++)
    if (vec[i].size() > 1) {
      for (int s = 0; s < (int)vec[i].size() - 1; s++) {
        res = min(res, vec[i][s + 1] - vec[i][s]);
      }
    }
  if (res == 100000000) return -1;
  return res + 1;
}
int main() {
  int test, res;
  scanf("%d", &test);
  while (test--) {
    printf("%d\n", solve());
  }
}
