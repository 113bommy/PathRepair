#include <bits/stdc++.h>
using namespace std;
long long X, Y, x, y, n, m, t, t1, t2, i, p, k, r[100001], l[100001], a[100001];
void w() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
void YoN(bool bol) {
  if (bol)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
void CL(long long bol) {
  cout << bol << endl;
  return;
}
int main() {
  cin >> t1 >> t2 >> t >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  X = 1;
  r[0] = t1 - 1;
  a[n + 1] = -1;
  for (i = 2; i <= n + 1; i++)
    if (a[i - 1] == a[i])
      X++;
    else {
      r[++k] = max(r[k - 1], a[i - 1] - 1) + X * t;
      l[k] = a[i - 1];
      X = 1;
    }
  if (l[1] > t1) {
    X = l[1] - 1;
    Y = t;
  } else if (l[1] == 0) {
    X = 0;
    Y = r[1] + t;
  } else if (l[1] == t1) {
    X = l[1] - 1;
    Y = t + 1;
  } else if (l[1] < t1) {
    X = l[1] - 1;
    Y = t + t1 - X;
  }
  for (i = 2; i <= k; i++) {
    x = l[i] - 1;
    p = r[i - 1];
    if (x <= p)
      y = p - x + 1 + t;
    else
      y = t;
    if (y + x - 1 > t2) break;
    if (y < Y) {
      X = x;
      Y = y;
    }
  }
  y = t;
  x = r[k] + 1;
  if (y + x - 1 <= t2) X = x;
  cout << X << endl;
}
