#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b) {
  if (a >= b)
    return true;
  else
    return false;
}
int main() {
  int i, j, k, m, n, index, discounts, items, sum;
  vector<int> a;
  vector<int> d;
  scanf("%d", &m);
  a.clear();
  d.clear();
  sum = 0;
  for (i = 1; i <= m; i++) {
    scanf("%d", &j);
    d.push_back(j);
  }
  sort(d.begin(), d.end());
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &j);
    a.push_back(j);
  }
  sort(a.begin(), a.end(), compare);
  items = n;
  index = -1;
  while (items >= d[0]) {
    for (k = 0; k <= d[0] - 1; k++) sum = sum + a[++index];
    items = items - d[0];
    if (items >= 2) {
      items = items - 2;
      index = index + 2;
    } else if (items == 1) {
      items = items - 1;
      index = index + 1;
    }
  }
  while (items != 0) {
    sum = sum + a[++index];
    items--;
  }
  printf("%d\n", sum);
  return 0;
}
