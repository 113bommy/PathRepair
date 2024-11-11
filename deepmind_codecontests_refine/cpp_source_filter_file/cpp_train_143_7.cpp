#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> mx(n + 1, 100000000);
  vector<int> t;
  vector<int> l;
  vector<int> r;
  vector<int> a;
  vector<int> add(n + 1);
  for (int j = 0; j < m; j++) {
    int ax, bx, cx, dx;
    cin >> ax >> bx >> cx >> dx;
    t.push_back(ax);
    l.push_back(bx);
    r.push_back(cx);
    a.push_back(dx);
    if (ax == 1) {
      for (int i = bx; i <= cx; i++) add[i] += dx;
    } else {
      bool any = false;
      for (int i = bx; i <= cx; i++)
        if (mx[i] + add[i] >= dx) {
          any = true;
          break;
        }
      if (!any) {
        cout << "NO";
        return 0;
      }
      for (int i = bx; i <= cx; i++) mx[i] = min(mx[i], dx - add[i]);
    }
  }
  add.assign(n, 0);
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) {
      for (int j = l[i]; j <= r[i]; j++) add[j] += a[i];
    } else {
      bool any = false;
      for (int j = l[i]; j <= r[i]; j++)
        if (mx[j] + add[j] >= a[i]) {
          any = true;
          break;
        }
      if (!any) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << mx[i] << ' ';
}
