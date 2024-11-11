#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int main() {
  int n, l, m;
  scanf("%d%d%d", &n, &l, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  if (n == 0) {
    printf("%d\n", l / m);
    return 0;
  }
  a[n] = l;
  int res = a[0] / m;
  for (int i = 0; i < n; i++) {
    res += (a[i + 1] - a[i] - b[i]) / m;
  }
  printf("%d\n", res);
  return 0;
}
