#include <bits/stdc++.h>
using namespace std;
int px, py;
int tx, ty;
int decide(int x, int y, int x2, int y2) {
  px = tx;
  py = ty;
  px -= x;
  py -= y;
  x2 -= x;
  y2 -= y;
  int dis = x2 * py - y2 * px;
  return dis <= 0;
}
int main() {
  int n, d;
  cin >> n >> d;
  int ele;
  cin >> ele;
  while (ele--) {
    int cnt = 0;
    cin >> tx >> ty;
    cnt += decide(0, d, n, n - d);
    cnt += decide(n, n - d, n - d, n);
    cnt += decide(n - d, n, d, 0);
    cnt += decide(d, 0, 0, d);
    if (cnt == 4)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
