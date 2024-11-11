#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int b[maxn];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  int tmp = a[d] + b[1];
  int id = 2;
  int rank = d;
  for (int i = d - 1; i >= 1; i--) {
    while (id <= n && a[i] + b[id] > tmp) id++;
    if (id <= n) rank--, id++;
    if (id > n) break;
  }
  printf("%d\n", rank);
  return 0;
}
