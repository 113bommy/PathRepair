#include <bits/stdc++.h>
using namespace std;
int TN = 1;
void solve() {
  long long n, m, v;
  int cl, ce;
  cin >> n >> m >> cl >> ce >> v;
  vector<int> li, e;
  li.resize(cl);
  e.resize(ce);
  if (cl > 0)
    for (int i = 0; i < cl; i++) cin >> li[i], li[i]--;
  if (ce > 0)
    for (int i = 0; i < ce; i++) cin >> e[i], e[i]--;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    if (x1 == x2) {
      cout << abs(y1 - y2) << endl;
      continue;
    }
    long long le = 1000000000;
    int l, r;
    if (cl > 0) {
      l = 0, r = cl - 1;
      while (r - l > 1) {
        int mid = (l + r) / 2;
        if (li[mid] <= y1)
          l = mid;
        else
          r = mid;
      }
      if (li[r] <= y1) l = r;
      if (li[l] <= y1)
        le = min(le, 1ll * abs(li[l] - y1) + 1ll * abs(x1 - x2) +
                         1ll * abs(li[l] - y2));
      l = 0, r = cl - 1;
      while (r - l > 1) {
        int mid = (l + r) / 2;
        if (li[mid] >= y1)
          l = mid;
        else
          r = mid;
      }
      if (li[l] >= y1) r = l;
      if (li[r] >= y1)
        le = min(le, 1ll * abs(li[r] - y1) + 1ll * abs(x1 - x2) +
                         1ll * abs(li[r] - y2));
    }
    if (ce > 0) {
      l = 0, r = ce - 1;
      while (r - l > 1) {
        int mid = (l + r) / 2;
        if (e[mid] <= y1)
          l = mid;
        else
          r = mid;
      }
      if (e[r] <= y1) l = r;
      if (e[l] <= y1)
        le = min(le, 1ll * abs(e[l] - y1) + (1ll * abs(x1 - x2) / v) +
                         1ll * (abs(x1 - x2) % v != 0) + 1ll * abs(e[l] - y2));
      l = 0, r = ce - 1;
      while (r - l > 1) {
        int mid = (l + r) / 2;
        if (e[mid] > y1)
          l = mid;
        else
          r = mid;
      }
      if (e[l] >= y1) r = l;
      if (e[r] >= y1)
        le = min(le, 1ll * abs(e[r] - y1) + (1ll * abs(x1 - x2) / v) +
                         1ll * (abs(x1 - x2) % v != 0) + 1ll * abs(e[r] - y2));
    }
    cout << le << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  while (TN--) solve();
  return 0;
}
