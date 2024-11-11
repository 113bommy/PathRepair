#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
void go(vector<int> &v) {
  int i, n = v.size();
  if (n == 1) {
    v[0] = 1;
    return;
  }
  if (n == 2) {
    v[0] = 3, v[1] = 4;
    return;
  }
  if (n % 2 == 0) {
    for (i = 0; i < n - 1; i++) {
      v[i] = 1;
    }
    v[n - 1] = n / 2 - 1;
  } else {
    for (i = 0; i < n - 2; i++) {
      v[i] = 1;
    }
    v[n - 2] = 2;
    v[n - 1] = n / 2 + 1;
  }
}
int main() {
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  a.resize(n);
  b.resize(m);
  go(a);
  go(b);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", a[i] * b[j]);
    }
    printf("\n");
  }
  return 0;
}
