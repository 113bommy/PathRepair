#include <bits/stdc++.h>
using namespace std;
int n, ans;
struct Edge {
  int l;
  int r;
  friend bool operator<(Edge a, Edge b) {
    if (a.r != b.r)
      return a.r < b.r;
    else
      return a.l < b.l;
  }
} a[2000001];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, w;
    cin >> x;
    cin >> w;
    a[i].l = x - w;
    a[i].r = x + w;
  }
  sort(a + 1, a + n + 1);
  int x = -(1 << 30);
  for (int i = 1; i <= n; i++) {
    if (a[i].l >= x) {
      ans++;
      x = a[i].r;
    }
  }
  cout << ans << endl;
  return 0;
}
