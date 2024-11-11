#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
;
struct trap {
  int l, r, d;
  trap(int x, int y, int z) {
    l = x;
    r = y;
    d = z;
  }
};
vector<trap> v;
vector<int> h;
int st[1000006], ed[1000006];
int cal(int mid) {
  if (mid > n) return false;
  memset(st, 0, sizeof st);
  memset(ed, 0, sizeof ed);
  int durbol = h[mid - 1];
  for (int i = 0; i < m; i++) {
    if (v[i].d > durbol) {
      st[v[i].l]++;
      ed[v[i].r]++;
    }
  }
  int time = 0, pt = 0;
  for (int i = 1; i <= k; i++) {
    pt += st[i];
    if (pt) time++;
    pt -= ed[i];
  }
  time *= 2;
  time += k + 1;
  if (time > t) return false;
  return true;
}
int main() {
  cin >> n >> k >> m >> t;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    h.push_back(x);
  }
  sort(h.rbegin(), h.rend());
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    trap tp = trap(x, y, z);
    v.push_back(tp);
  }
  int hi, lo, mid;
  hi = n, lo = 0;
  while (lo <= hi) {
    mid = (hi + lo) / 2;
    if (cal(mid) && !cal(mid + 1)) {
      break;
    }
    if (!cal(mid))
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  cout << mid << endl;
  return 0;
}
