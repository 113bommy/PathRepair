#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int q, n, a[N], vis[N];
void divV(int l, int r) {
  if (r <= l || l > n || r < 1) return;
  int M = n + 1, pos;
  for (int i = l; i <= r; i++) {
    if (a[i] < M) {
      M = a[i];
      pos = i;
    }
  }
  if (pos == l) {
    div(l + 1, r);
    return;
  }
  for (int i = pos - 1; i >= l; i--) swap(a[i], a[i + 1]);
  divV(pos, r);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  for (cin >> q; q; q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    int k = n - 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    divV(1, n);
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
  }
  return 0;
}
