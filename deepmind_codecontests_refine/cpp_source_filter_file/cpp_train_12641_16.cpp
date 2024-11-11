#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3FFFFFFF;
char arr[1001][1001];
int main() {
  int n, m, x, y, z, p;
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
  x %= 4;
  y %= 2;
  z %= 4;
  vector<int> a(p), b(p);
  for (int i = 0; i < p; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  if (x == 1) {
    for (int i = 0; i < p; i++) {
      int at = b[i];
      int bt = n - a[i] + 1;
      a[i] = at;
      b[i] = bt;
    }
    swap(n, m);
  } else if (x == 2) {
    for (int i = 0; i < p; i++) {
      int at = n - a[i] + 1;
      int bt = m - b[i] + 1;
      a[i] = at;
      b[i] = bt;
    }
  } else if (x == 3) {
    for (int i = 0; i < p; i++) {
      int at = m - b[i] + 1;
      int bt = a[i];
      a[i] = at;
      b[i] = bt;
    }
    swap(n, m);
  }
  if (y == 1) {
    for (int i = 0; i < p; i++) {
      int at = a[i];
      int bt = m - b[i] + 1;
      a[i] = at;
      b[i] = bt;
    }
  }
  if (y == 3) {
    for (int i = 0; i < p; i++) {
      int at = b[i];
      int bt = n - a[i] + 1;
      a[i] = at;
      b[i] = bt;
    }
    swap(n, m);
  } else if (y == 2) {
    for (int i = 0; i < p; i++) {
      int at = n - a[i] + 1;
      int bt = m - b[i] + 1;
      a[i] = at;
      b[i] = bt;
    }
  } else if (y == 1) {
    for (int i = 0; i < p; i++) {
      int at = m - b[i] + 1;
      int bt = a[i];
      a[i] = at;
      b[i] = bt;
    }
    swap(n, m);
  }
  for (int i = 0; i < p; i++) {
    printf("%d %d\n", a[i], b[i]);
  }
  return 0;
}
