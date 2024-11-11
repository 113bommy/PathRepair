#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
const long long inf = 1e18;
int a[maxn], b[maxn];
int seg[maxn * 4];
void update(int x, int s, int e, int idx, int val) {
  if (s == e) {
    seg[x] = val;
    return;
  }
  int mid = (s + e) / 2;
  if (idx <= mid) {
    update(x * 2 + 1, s, mid, idx, val);
  } else
    update(x * 2 + 2, mid + 1, e, idx, val);
  seg[x] = min(seg[x * 2 + 1], seg[x * 2 + 2]);
}
int query(int x, int ss, int se, int qs, int qe) {
  if (se < qs || ss > qe)
    return 1e9;
  else if (qs <= ss && se <= qe) {
    return seg[x];
  }
  int mid = (ss + se) / 2;
  return min(query(x * 2 + 1, ss, mid, qs, qe),
             query(x * 2 + 2, mid + 1, se, qs, qe));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      update(1, 1, n, i, a[i]);
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    bool canDo = true;
    for (int i = 1; i <= n; i++) {
      int lo = 1, hi = n, md;
      while (hi - lo > 2) {
        md = (lo + hi) / 2;
        if (query(1, 1, n, 1, md) <= b[i])
          hi = md;
        else
          lo = md;
      }
      int f = 0;
      for (md = lo; md <= hi; md++) {
        if (query(1, 1, n, 1, md) == b[i]) {
          f = md;
          break;
        }
      }
      if (!f) {
        canDo = false;
        break;
      }
      update(1, 1, n, md, 1e9);
    }
    if (canDo)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
