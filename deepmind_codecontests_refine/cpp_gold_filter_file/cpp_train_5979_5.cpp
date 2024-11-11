#include <bits/stdc++.h>
using namespace std;
int n, m, r, ans;
struct data {
  int x, y, xr, yr;
} ng[50005], d[50005], tmp1[50005];
int cmp1(data x, data y) {
  if (x.x == y.x) return abs(x.y - x.yr) < abs(y.y - y.yr);
  return x.x < y.x;
}
int cmp2(data x, data y) {
  if (x.y == y.y) return abs(x.x - x.xr) > abs(y.x - y.xr);
  return x.y > y.y;
}
void Cal() {
  sort(d + 1, d + 1 + n, cmp1);
  sort(ng + 1, ng + 1 + m, cmp2);
  int top = 0;
  for (int i = 1; i <= m; i++) {
    int l = 1, r = n, ll = 0, rr = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (d[mid].x > ng[i].x + ans)
        ll = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (d[mid].x < ng[i].xr - ans)
        rr = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (ll != 0 && rr != 0) {
      for (int j = ll; j <= min(rr, ll + 1000); j++) {
        int tmp1 = 1e9, tmp2 = 1e9, tmp3 = 1e9;
        if (ng[i].y < d[j].yr && ng[i].y > d[j].y) {
          tmp1 = min(abs(ng[i].x - d[j].x), abs(ng[i].xr - d[j].x));
          tmp2 = min(tmp1, abs(d[j].yr - ng[i].y));
          tmp3 = min(tmp2, abs(ng[i].y - d[j].y));
          ans = max(ans, tmp3);
        }
      }
      for (int j = rr; j >= max(ll, rr - 1000); j--) {
        int tmp1 = 1e9, tmp2 = 1e9, tmp3 = 1e9;
        if (ng[i].y < d[j].yr && ng[i].y > d[j].y) {
          tmp1 = min(abs(ng[i].x - d[j].x), abs(ng[i].xr - d[j].x));
          tmp2 = min(tmp1, abs(d[j].yr - ng[i].y));
          tmp3 = min(tmp2, abs(ng[i].y - d[j].y));
          ans = max(ans, tmp3);
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> d[i].x >> d[i].y >> r;
    d[i].xr = d[i].x;
    d[i].yr = d[i].y + r;
  }
  for (int i = 1; i <= m; i++) {
    cin >> ng[i].x >> ng[i].y >> r;
    ng[i].xr = ng[i].x + r;
    ng[i].yr = ng[i].y;
  }
  Cal();
  for (int i = 1; i <= n; ++i) tmp1[i] = d[i];
  for (int i = 1; i <= m; ++i) d[i] = ng[i];
  for (int i = 1; i <= n; ++i) ng[i] = tmp1[i];
  swap(n, m);
  for (int i = 1; i <= n; ++i) {
    swap(d[i].x, d[i].y);
    swap(d[i].xr, d[i].yr);
  }
  for (int i = 1; i <= m; ++i) {
    swap(ng[i].x, ng[i].y);
    swap(ng[i].xr, ng[i].yr);
  }
  Cal();
  cout << ans;
}
