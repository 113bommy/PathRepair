#include <bits/stdc++.h>
using namespace std;
int accux[210000];
int accuy[210000];
int raccux[210000];
int raccuy[210000];
int bb(int inicio, int n, int x, int y) {
  int l = inicio, r = n - 1;
  int m, tam, dist;
  int tx = 0, ty = 0;
  if (inicio > 0) {
    tx = accux[inicio - 1];
    ty = accuy[inicio - 1];
  }
  while (l <= r) {
    m = (l + r) / 2;
    tam = m - inicio + 1;
    if (m == n - 1) {
      dist = abs(tx - x) + abs(ty - y);
    } else {
      dist = abs((raccux[m + 1] + tx) - x) + abs((raccuy[m + 1] + ty) - y);
    }
    if (tam == dist) {
      if (tam - 1 != abs((raccux[m] + tx) - x) + abs((raccuy[m] + ty) - y)) {
        return tam;
      } else {
        r = m - 1;
      }
    } else if (tam > dist)
      l = m + 1;
    else if (tam < dist)
      r = m - 1;
  }
  return n + 1;
}
int main() {
  int n, x, y;
  cin >> n;
  char c;
  int vx[n];
  int vy[n];
  int tx = 0, ty = 0;
  for (int i = 0; i < n; ++i) {
    scanf(" %c", &c);
    switch (c) {
      case 'U':
        vx[i] = 0;
        vy[i] = 1;
        break;
      case 'D':
        vx[i] = 0;
        vy[i] = -1;
        break;
      case 'L':
        vx[i] = -1;
        vy[i] = 0;
        break;
      case 'R':
        vx[i] = +1;
        vy[i] = 0;
        break;
    }
  }
  scanf("%d %d", &x, &y);
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      accux[i] = accux[i - 1] + vx[i];
      accuy[i] = accuy[i - 1] + vy[i];
      raccux[n - 1 - i] = raccux[n - i] + vx[n - 1 - i];
      raccuy[n - 1 - i] = raccuy[n - i] + vy[n - 1 - i];
    } else {
      accux[i] = vx[i];
      accuy[i] = vy[i];
      raccux[n - 1 - i] = vx[n - 1 - i];
      raccuy[n - 1 - i] = vy[n - 1 - i];
    }
  }
  if (accux[n - 1] == x && accuy[n - 1] == y) {
    printf("0\n");
    return 0;
  }
  int ans = n + 1;
  for (int i = 0; i < n; ++i) {
    ans = min(bb(i, n, x, y), ans);
  }
  if (ans == n + 1)
    printf("-1\n");
  else
    printf("%d\n", ans);
}
