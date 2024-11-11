#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 9;
const int N = 1e5 + 10;
int n;
struct Node {
  long long x, y;
  Node(long long X = 0, long long Y = 0) { x = X, y = Y; }
} p[N];
long long miny[2][N], maxy[2][N];
bool cmpx(Node A, Node B) { return A.x < B.x; }
long long ans, a;
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &p[i].x, &p[i].y);
  sort(p + 1, p + n + 1, cmpx);
  ans = ((p[n].x - p[1].x) * (p[n].x - p[1].x));
  miny[0][1] = maxy[0][1] = p[1].y;
  for (int i = 2; i <= n; i++) {
    miny[0][i] = min(p[i].y, miny[0][i - 1]);
    maxy[0][i] = max(p[i].y, maxy[0][i - 1]);
  }
  miny[1][n] = maxy[1][n] = p[n].y;
  for (int i = n - 1; i >= 1; i--) {
    miny[1][i] = min(p[i].y, miny[1][i + 1]);
    maxy[1][i] = max(p[i].y, maxy[1][i + 1]);
  }
  ans = min(ans, ((maxy[0][n] - miny[0][n]) * (maxy[0][n] - miny[0][n])));
}
bool check(long long mid) {
  int l = 1, r = n, ll, rr, mm;
  long long now_miny, now_maxy, now_maxd;
  while (((p[l].x) * (p[l].x)) > mid && l <= n) l++;
  while (((p[r].x) * (p[r].x)) > mid && r >= 1) r--;
  for (int i = l; i <= r; i++) {
    ll = i, rr = r + 1;
    while (rr - ll > 1) {
      mm = (ll + rr) >> 1;
      if (((p[mm].x - p[i].x) * (p[mm].x - p[i].x)) <= mid &&
          abs(p[mm].x) <= abs(p[i].x))
        ll = mm;
      else
        rr = mm;
    }
    now_miny = min(miny[0][i - 1], miny[1][ll + 1]);
    now_maxy = max(maxy[0][i - 1], maxy[1][ll + 1]);
    now_maxd = max(((now_miny) * (now_miny)), ((now_maxy) * (now_maxy))) +
               max(((p[i].x) * (p[i].x)), ((p[ll].x) * (p[ll].x)));
    if (now_maxd <= mid &&
        ((now_maxy - now_miny) * (now_maxy - now_miny)) <= mid &&
        ((p[ll].x - p[i].x) * (p[ll].x - p[i].x)) <= mid)
      return true;
  }
  for (int i = r; i >= l; i--) {
    ll = l - 1, rr = i;
    while (rr - ll > 1) {
      mm = (ll + rr) >> 1;
      if (((p[mm].x - p[i].x) * (p[mm].x - p[i].x)) <= mid &&
          abs(p[mm].x) <= abs(p[i].x))
        rr = mm;
      else
        ll = mm;
    }
    now_miny = min(miny[0][rr + 1], miny[1][i - 1]);
    now_maxy = max(maxy[0][rr + 1], maxy[1][i - 1]);
    now_maxd = max(((now_miny) * (now_miny)), ((now_maxy) * (now_maxy))) +
               max(((p[i].x) * (p[i].x)), ((p[rr].x) * (p[rr].x)));
    if (now_maxd <= mid &&
        ((now_maxy - now_miny) * (now_maxy - now_miny)) <= mid &&
        ((p[rr].x - p[i].x) * (p[rr].x - p[i].x)) <= mid)
      return true;
  }
  return false;
}
void work() {
  long long l = -1, r = ans, mid;
  while (r - l > 1) {
    mid = (l + r) >> 1LL;
    check(mid) ? r = mid : l = mid;
  }
  printf("%I64d\n", r);
}
int main() {
  init();
  work();
  return 0;
}
