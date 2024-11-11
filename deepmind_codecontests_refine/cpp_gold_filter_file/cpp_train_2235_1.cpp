#include <bits/stdc++.h>
using namespace std;
int solve(int aa, int bb, int t) {
  vector<int> a(100), b(100), c(100);
  int i = 0;
  int mx_base = 0;
  while (aa) {
    if (aa % 10 > mx_base) mx_base = aa % 10;
    a[i++] = aa % 10;
    aa /= 10;
  }
  i = 0;
  while (bb) {
    if (bb % 10 > mx_base) mx_base = bb % 10;
    b[i++] = bb % 10;
    bb /= 10;
  }
  if (mx_base >= t && !(mx_base == 1 && t == 2)) return 0;
  for (int i = 0; i < 100; i++) c[i] = a[i] + b[i];
  for (int i = 0; i < 99; i++) {
    if (c[i] >= t) {
      c[i + 1] += c[i] / t;
      c[i] %= t;
    }
  }
  while (c.back() == 0 && c.size() > 1) c.pop_back();
  return c.size();
}
int main() {
  string t;
  int a, b;
  cin >> a >> b;
  int mx = 0;
  for (int i = 2; i < 50; i++)
    if (mx < solve(a, b, i)) mx = solve(a, b, i);
  cout << mx;
  return 0;
}
