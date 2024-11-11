#include <bits/stdc++.h>
using namespace std;
int _abs(int a) {
  if (a < 0) return -a;
  return a;
}
bool a[200], b[200];
int n, m;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  int t, num;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &num);
    a[num] = 1;
  }
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &num);
    b[num] = 1;
  }
  for (int i = 0; i <= n * m; i++) {
    int x = i % n, y = i % m;
    if (a[x] || b[y]) {
      a[x] = b[y] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      printf("No\n");
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (!b[i]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
