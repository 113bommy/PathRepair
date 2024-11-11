#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, m, y;
  cin >> n >> x >> m >> y;
  if (x == y) {
    cout << max(n, m) + 1 << endl;
    return 0;
  }
  if (x > y) {
    swap(x, y);
    swap(n, m);
  }
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    int l = max(y - x - i, i - (y - x) - 1) + 1;
    int ll = max(l, 1);
    int h = y - x + i;
    int hh = min(h, m);
    if (hh >= ll) res += hh - ll + 1;
    ll++;
    h--;
    hh = min(h, m);
    if (hh >= ll) res += hh - ll + 1;
  }
  for (int i = 1; i <= n; i++) {
    if (x - i < y - m) res++;
  }
  for (int i = 1; i <= m; i++) {
    if (y + i > x + n) res++;
  }
  cout << res << endl;
  return 0;
}
