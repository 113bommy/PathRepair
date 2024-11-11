#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n;
  scanf("%d", &n);
  v.assign(n, 0);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  int ans = (int)1e8 + 10;
  int m = n >> 1;
  for (int i = 0; i + m < n; ++i) ans = min(ans, v[i + m] - v[i]);
  printf("%d\n", ans);
}
