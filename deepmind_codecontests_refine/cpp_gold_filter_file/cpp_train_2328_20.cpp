#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v;
  scanf("%d %d %d", &n, &m, &v);
  --v;
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; ++i)
    if (i != v) ans.push_back(make_pair(i + 1, v + 1));
  int rest = m - (n - 1);
  int start = 1, end = n - 1;
  if (v == 0) end = n - 2;
  for (int i = start; i <= end; ++i) {
    if (rest <= 0) break;
    if (i == v) continue;
    for (int j = i + 1; j <= end; ++j) {
      if (rest <= 0) break;
      if (j == v) continue;
      ans.push_back(make_pair(i + 1, j + 1));
      --rest;
    }
  }
  if (rest != 0)
    printf("-1\n");
  else
    for (auto& p : ans) printf("%d %d\n", p.first, p.second);
  return 0;
}
