#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int x, y, h, w;
  x = 0;
  y = 0;
  h = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) x++;
    if (a[i] == 2) y++;
    if (a[i] == 3) h++;
  }
  int p[x], m[y], q[h];
  w = x < y ? x < h ? x : h : y < h ? y : h;
  if (x == 0 || y == 0 || h == 0) {
    std::cout << w << "\n";
    return 0;
  }
  std::cout << w << "\n";
  x = 0;
  y = 0;
  h = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      p[x] = i + 1;
      x++;
    }
    if (a[i] == 2) {
      m[y] = i + 1;
      y++;
    }
    if (a[i] == 3) {
      q[h] == i + 1;
      h++;
    }
  }
  for (int i = 0; i < w; i++)
    std::cout << p[i] << " " << m[i] << " " << q[i] << "\n";
  return 0;
}
