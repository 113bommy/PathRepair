#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double pi = 3.141592653589793;
const double eps = 1e-8;
int k;
int n, m;
struct point {
  int x, y;
};
struct node {
  point p1;
  point p2;
};
node a[100010];
int l[100010];
int r[100010];
int u[100010];
int d[100010];
int suml[100010];
int sumr[100010];
int sumu[100010];
int sumd[100010];
int main() {
  ios::sync_with_stdio(false);
  cin >> k;
  cin >> n >> m;
  for (int i = 1; i <= k; i++) {
    cin >> a[i].p1.x >> a[i].p1.y >> a[i].p2.x >> a[i].p2.y;
    l[min(a[i].p1.x, a[i].p2.x)]++;
    r[max(a[i].p1.x, a[i].p2.x)]++;
    u[min(a[i].p1.y, a[i].p2.y)]++;
    d[max(a[i].p1.y, a[i].p2.y)]++;
  }
  for (int i = 1; i <= 100000; i++) {
    suml[i] = suml[i - 1] + l[i];
    sumu[i] = sumu[i - 1] + u[i];
  }
  for (int i = 100000; i >= 0; i--) {
    sumr[i] = sumr[i + 1] + r[i];
    sumd[i] = sumd[i + 1] + d[i];
  }
  int flag = 0;
  int cntl, cntr, cntu, cntd;
  cin >> cntl >> cntr >> cntu >> cntd;
  for (int i = 1; i <= k; i++) {
    int L = min(a[i].p1.x, a[i].p2.x), R = max(a[i].p1.x, a[i].p2.x),
        U = min(a[i].p1.y, a[i].p2.y), D = max(a[i].p1.y, a[i].p2.y);
    if (suml[R - 1] - (a[i].p1.x != a[i].p2.x) == cntl &&
        sumu[D - 1] - (a[i].p1.y != a[i].p2.y) == cntu &&
        sumr[L + 1] - (a[i].p1.x != a[i].p2.x) == cntr &&
        sumd[U + 1] - (a[i].p1.y != a[i].p2.y) == cntd) {
      flag = i;
      break;
    }
  }
  if (flag)
    cout << flag << endl;
  else
    cout << -1 << endl;
  return 0;
}
