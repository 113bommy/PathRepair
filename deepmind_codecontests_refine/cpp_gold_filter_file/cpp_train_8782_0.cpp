#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b) {
  if (a > b)
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
  items = 0;
  index = 0;
  while (index <= n - 1) {
    if (items == d[0]) {
      index = index + 2;
      items = 0;
    } else {
      sum = sum + a[index++];
      items++;
    }
  }
  printf("%d\n", sum);
  return 0;
}
