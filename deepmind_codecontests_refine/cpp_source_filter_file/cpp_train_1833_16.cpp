#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double pi = 3.141592653589793;
const double eps = 1e-8;
int k;
int n, m;
struct node {
  pair<int, int> p1;
  pair<int, int> p2;
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
    cin >> a[i].p1.first >> a[i].p1.second >> a[i].p2.first >> a[i].p2.second;
    l[min(a[i].p1.second, a[i].p2.second)]++;
    r[max(a[i].p1.second, a[i].p2.second)]++;
    u[min(a[i].p1.first, a[i].p2.first)]++;
    d[max(a[i].p1.first, a[i].p2.first)]++;
  }
  for (int i = 0; i <= 100000; i++) {
    suml[i] = suml[i - 1] + l[i];
    sumu[i] = sumu[i - 1] + u[i];
  }
  for (int i = 100000; i >= 0; i--) {
    sumr[i] = sumr[i + 1] + r[i];
    sumd[i] = sumd[i + 1] + d[i];
  }
  int flag = 0;
  int cntl, cntr, cntu, cntd;
  cin >> cntu >> cntd >> cntl >> cntr;
  for (int i = 1; i <= k; i++) {
    int L = min(a[i].p1.second, a[i].p2.second),
        R = max(a[i].p1.second, a[i].p2.second),
        U = min(a[i].p1.first, a[i].p2.first),
        D = max(a[i].p1.first, a[i].p2.first);
    if (suml[R - 1] - (a[i].p1.second != a[i].p2.second) == cntl &&
        sumu[D - 1] - (a[1].p1.first != a[i].p2.first) == cntu &&
        sumr[L + 1] - (a[i].p1.second != a[i].p2.second) == cntr &&
        sumd[U + 1] - (a[1].p1.first != a[i].p2.first) == cntd) {
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
