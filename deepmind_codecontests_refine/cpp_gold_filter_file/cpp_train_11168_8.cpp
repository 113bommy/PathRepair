#include <bits/stdc++.h>
using namespace std;
int query(int l, int r) {
  int s;
  cout << "? " << l + 1 << " " << r + 1 << endl;
  cin >> s;
  return s;
}
void solve() {
  int n, i, s, p;
  cin >> n;
  int a[n];
  p = query(0, n - 1);
  for (i = 1; i < n - 1; i++) {
    s = query(i, n - 1);
    a[i - 1] = p - s;
    p = s;
  }
  s = query(n - 3, n - 2);
  a[n - 2] = s - a[n - 3];
  a[n - 1] = p - a[n - 2];
  cout << "!";
  for (i = 0; i < n; i++) cout << " " << a[i];
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) solve();
}
