#include <bits/stdc++.h>
using namespace std;
int n, m, a, u[4000010];
int id(int y, int x) {
  if (x == 0) return y;
  if (y == n - 1) return n - 1 + x;
  if (x == m - 1) return n - 1 + m - 1 + n - 1 - y;
  return n - 1 + m - 1 + n - 1 + m - 1 - x;
}
void f(int y, int x) {
  if (y < 0 || n <= y || x < 0 || m <= x) return;
  if (u[id(y, x)]) return;
  u[id(y, x)] = 1;
  if (y == 0) {
    f(x, 0);
    f(n - 1, x - n + 1);
    f(m - 1 - x, m - 1);
    f(n - 1, x + n - 1);
  } else if (y == n - 1) {
    f(n - 1 - x, 0);
    f(0, x - n + 1);
    f(n - 1 - (m - 1 - x), m - 1);
    f(0, x + n - 1);
  } else if (x == 0) {
    f(0, y);
    f(y - m + 1, m - 1);
    f(n - 1, n - 1 - y);
    f(y + m - 1, m - 1);
  } else {
    f(0, m - 1 - y);
    f(y - m + 1, 0);
    f(n - 1, m - 1 - (n - 1 - y));
    f(y + m - 1, 0);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    if (!u[id(0, i)]) a++, f(0, i);
  for (int i = 0; i < m; i++)
    if (!u[id(n - 1, i)]) a++, f(n - 1, i);
  for (int i = 0; i < n; i++)
    if (!u[id(i, 0)]) a++, f(i, 0);
  for (int i = 0; i < n; i++)
    if (!u[id(i, m - 1)]) a++, f(i, m - 1);
  cout << a;
}
