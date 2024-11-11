#include <bits/stdc++.h>
using namespace std;
int x[20005];
int y[20005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int xx, yy;
    scanf("%d %d", &xx, &yy);
    x[xx + 10000]++;
    y[yy + 10000]++;
  }
  long long ret = 0, sumx = 0, sumy = 0, tx = 0, ty = 0, dx = 0, dy = 0;
  for (int i = 0; i <= 20000; i++) {
    ret += (long long)x[i] * tx;
    ret += (long long)y[i] * ty;
    dx += sumx;
    dy += sumy;
    sumx += x[i];
    sumy += y[i];
    dx += sumx;
    dy += sumy;
    tx += dx;
    ty += dx;
  }
  cout << ret << endl;
  return 0;
}
