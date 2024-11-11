#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int min(int a, int b, int c) {
  int d = min(a, b);
  return min(d, c);
}
int main() {
  int n, k, l, c, d, p, nl, np;
  while (scanf("%d", &n) != EOF) {
    scanf("%d %d %d %d %d", &k, &l, &c, &d, &p);
    scanf("%d %d", &nl, &np);
    int x, y, z;
    x = k * l / n;
    y = c * d;
    z = p / np;
    int res = (int)min(x, y, z) / n;
    cout << res << endl;
  }
  return 0;
}
