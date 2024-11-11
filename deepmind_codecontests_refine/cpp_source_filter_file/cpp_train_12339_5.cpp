#include <bits/stdc++.h>
using namespace std;
using three = tuple<int, int, int>;
int a[2501][2501];
bitset<2501> b[2501];
three v[2501];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i][i] != 0) {
      printf("NOT MAGIC\n");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i][j] != a[j][i]) {
        printf("NOT MAGIC\n");
        return 0;
      }
    }
  }
  int k = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      v[++k] = make_tuple(a[i][j], i, j);
    }
  }
  assert(k == n * n);
  sort(v + 1, v + k + 1);
  int l = 1;
  for (int i = 1; i <= k; i++) {
    while (l <= k && get<0>(v[l]) < get<0>(v[i])) {
      b[get<1>(v[l])][get<2>(v[l])] = 1;
      l++;
    }
    if ((b[get<1>(v[i])] & b[get<2>(v[i])]).any()) {
      printf("NOT MAGIC\n");
      return 0;
    }
  }
  printf("MAGIC\n");
  return 0;
}
