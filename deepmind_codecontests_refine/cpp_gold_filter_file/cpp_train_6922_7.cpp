#include <bits/stdc++.h>
using namespace std;
int a[100000 + 10];
int b[100000 + 10];
int main() {
  int n, x, m, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  printf("%s", a[x] < b[m - y + 1] ? "YES" : "NO");
}
