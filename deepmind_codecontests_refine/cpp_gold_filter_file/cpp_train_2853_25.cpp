#include <bits/stdc++.h>
const int N = 1005, M = 1000005;
int n, a[N], x, y, z, L[M], R[M], cnt;
int find() {
  for (int i = 1; i <= n; ++i)
    if (a[i] && i != x && i != y && i != z) return i;
  return 0;
}
void boom(int x, int y) {
  a[x] -= a[y], a[y] <<= 1;
  L[cnt] = y, R[cnt++] = x;
  assert(cnt <= 1000000);
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  x = find(), y = find(), z = find();
  while (x && y && z) {
    do {
      if (a[x] > a[y]) std::swap(x, y);
      if (a[x] > a[z]) std::swap(x, y);
      if (a[y] > a[z]) std::swap(y, z);
      for (int d = a[y] / a[x]; d; d >>= 1) boom(d & 1 ? y : z, x);
    } while (a[x] && a[y] && a[z]);
    if (a[x] > a[y]) std::swap(x, y);
    if (a[x] > a[z]) std::swap(x, y);
    if (a[y] > a[z]) std::swap(y, z);
    x = find();
  }
  if (!x + !y + !z != 1)
    std::cout << "-1\n";
  else {
    std::cout << cnt << '\n';
    for (int i = 0; i < cnt; ++i) std::cout << L[i] << ' ' << R[i] << '\n';
  }
  return 0;
}
