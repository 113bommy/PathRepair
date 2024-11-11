#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[10000];
  int sum = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  int s = a[0];
  v.push_back(0);
  for (int i = 1; i < n && (double)s <= (double)((sum * 1.0) / 2.0); i++) {
    if ((double)a[i] <= (double)((a[0] * 1.0) / 2.0)) {
      v.push_back(i);
      s += a[i];
    }
  }
  if ((double)s > (double)((sum * 1.0) / 2.0)) {
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++) {
      printf("%d ", v[i] + 1);
    }
    printf("\n");
  } else {
    printf("0\n");
  }
  return 0;
}
