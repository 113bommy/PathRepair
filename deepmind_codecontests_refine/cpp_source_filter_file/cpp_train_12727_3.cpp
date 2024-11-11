#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, a[N], f = 0;
int ask(int l, int r = -1) {
  if (r == -1) {
    if (a[l] != -1)
      return a[l];
    else {
      cout << "? " << l << ' ' << l << endl;
      cin >> a[l] >> f;
      return a[l];
    }
  }
  cout << "? " << l << ' ' << r << endl;
  int x;
  cin >> x >> f;
  return x;
}
void fn(int l, int r) {
  int x = ask(l), y = ask(r);
  if (r - l < 2) return;
  if (x == y) {
    fill(a + l, a + r + 1, x);
    return;
  }
  int k = ask(l, r);
  if (x == k) {
    fill(a + l, a + l + f, x);
    fn(l + f, r);
    return;
  }
  if (y == k) {
    fill(a + r - f + 1, a + r + 1, y);
    fn(l, r - f);
    return;
  }
  int mid = (l + r) / 2;
  fn(l, mid), fn(mid + 1, r);
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  memset(a, -1, sizeof a);
  fn(1, n);
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << endl;
}
