#include <bits/stdc++.h>
using namespace std;
const int INF = (-1u) / 2;
const long long int INF2 = (-1ull) / 2;
int a, b, i, d[1011000], j, k, n, m, timer = 0, l, r, x, y;
int c[1011000], cnt = 0, fl = 0, a2, a3 = -1000000, ans = 0;
int procedure(int l, int r) {
  int x = 0;
  if (c[l] == c[r]) {
    for (int i = l + 1; i < r; i++) {
      d[i] = c[l];
    }
    x = (r - l) / 2;
  } else {
    for (i = l; i <= r; i++) {
      if (i <= (l + r) / 2)
        d[i] = c[l];
      else
        d[i] = c[r];
    }
    x = r - l + 1;
    x /= 2;
    x--;
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> c[i];
    d[i] = c[i];
  }
  x = 0;
  y = -1;
  c[n] = c[n - 1];
  for (i = 1; i < n; i++) {
    if (c[i] == c[i - 1]) x = i;
    if (c[i] == c[i + 1]) y = i;
    if (y > x) a = max(a, procedure(x, y));
  }
  cout << a << "\n";
  for (i = 0; i < n; i++) {
    cout << d[i] << " ";
  }
  return 0;
}
