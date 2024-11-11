#include <bits/stdc++.h>
using namespace std;
int par[200005];
int fin(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = fin(par[x]);
}
void bing(int x, int y) { par[fin(x)] = fin(y); }
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 2 * n + 1; i++) {
    par[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    x--;
    y--;
    if (c) {
      if (fin(x) == fin(n + y) || fin(n + x) == fin(y)) {
        cout << 0;
        return 0;
      } else {
        bing(x + n, y + n);
        bing(x, y);
      }
    } else {
      if (fin(x) == fin(y) || fin(x + n) == fin(y + n)) {
        cout << 0;
        return 0;
      } else {
        bing(x, y + n);
        bing(x, y + n);
      }
    }
  }
  long long res = 1;
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    if (par[i] == i) {
      if (flag) res <<= 1;
      flag = 1;
      res %= 1000000007;
    }
  }
  cout << res;
  return 0;
}
