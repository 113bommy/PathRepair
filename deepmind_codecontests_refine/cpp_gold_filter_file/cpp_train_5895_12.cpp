#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
struct query {
  int op, l, r;
} aoq[maxn];
int a[maxn];
int n, q, m;
int change(int x) {
  for (int i = q - 1; i >= 0; i--) {
    int l = aoq[i].l;
    int r = aoq[i].r;
    if (x < l || x > r) continue;
    if (aoq[i].op == 1) {
      if (x == l)
        x = r;
      else
        x--;
    } else {
      x = l + r - x;
    }
  }
  return x;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> q >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> aoq[i].op >> aoq[i].l >> aoq[i].r;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cout << a[change(x)] << ' ';
  }
  cout << endl;
  return 0;
}
