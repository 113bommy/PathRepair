#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, l, x, y, a[MAXN], xok, yok, arr[MAXN + MAXN], sz;
bool check(int d) {
  for (int i = 0, r = 0; i < n && r < n; ++i) {
    for (; r < n && a[r] - a[i] < d; ++r)
      ;
    if (r < n && a[r] - a[i] == d) return true;
  }
  return false;
}
bool ok(int p) {
  if (p < 0 || p > l) return false;
  return binary_search(arr, arr + sz, p);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> l >> x >> y;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  xok = check(x);
  yok = check(y);
  if (xok && yok)
    cout << 0 << endl;
  else if (xok || yok)
    cout << 1 << endl << x * (xok ^ 1) + y * (yok ^ 1) << endl;
  else {
    int pos = -1;
    for (int i = 0; i < n; ++i) {
      arr[sz++] = a[i] - x;
      arr[sz++] = a[i] - x;
    }
    sort(arr, arr + sz);
    for (int i = 0; i < n && pos < 0; ++i) {
      if (ok(a[i] - y))
        pos = a[i] - y;
      else if (ok(a[i] + y))
        pos = a[i] + y;
    }
    if (pos == -1)
      cout << 2 << endl << x << " " << y << endl;
    else
      cout << 1 << endl << pos << endl;
  }
  return 0;
}
