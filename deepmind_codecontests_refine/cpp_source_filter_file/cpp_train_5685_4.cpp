#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
vector<vector<int> > v;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = n; i >= 5; --i) {
    v.push_back({i - 2, i - 1, i});
    v.push_back({i - 2, i - 1, i});
    for (int j = 1; j < i - 2; ++j) v.push_back({i - 1, j, i, j % (i - 3) + 1});
  }
  if (n & 1)
    v.push_back({1, 2, 3}), v.push_back({1, 2, 3});
  else
    v.push_back({1, 2, 3}), v.push_back({1, 2, 4}), v.push_back({1, 3, 4}),
        v.push_back({2, 3, 4});
  printf("%d\n", v.size());
  for (auto &vv : v) {
    printf("%d", vv.size());
    for (auto &x : vv) printf(" %d", x);
    printf("\n");
  }
  return 0;
}
