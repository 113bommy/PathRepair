#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int X[200020];
int Y[200020];
int sum[200020][2];
struct yqh {
  int x, y, id;
} a[300020];
int sta[200020], top;
int get() {
  char t = getchar();
  while (t < '0' || t > '9') t = getchar();
  int x = 0;
  while (t >= '0' && t <= '9') {
    x *= 10;
    x += t - '0';
    t = getchar();
  }
  return x;
}
bool cmpX(yqh x, yqh y) {
  if (x.x < y.x) return true;
  if (x.x > y.x) return false;
  if (x.y < y.y) return true;
  if (x.y > y.y) return false;
  return x.id < y.id;
}
bool cmpY(yqh x, yqh y) {
  if (x.y < y.y) return true;
  if (x.y > y.y) return false;
  if (x.x < y.x) return true;
  if (x.x > y.x) return false;
  return x.id < y.id;
}
int main() {
  int T = get();
  for (int ii = 1; ii <= T; ++ii) {
    n = get();
    m = get();
    k = get();
    for (int i = 0; i < n; ++i) {
      sum[i][0] = 0;
      int x = get();
      X[i] = x;
    }
    for (int i = 0; i < m; ++i) {
      sum[i][1] = 0;
      int y = get();
      Y[i] = y;
    }
    for (int i = 1; i <= k; ++i) {
      int x = get();
      int y = get();
      a[i].x = x;
      a[i].y = y;
      a[i].id = i;
      auto x1 = lower_bound(X, X + n, x) - X;
      auto y1 = lower_bound(Y, Y + m, y) - Y;
      if (X[x1] > x)
        ++sum[x1][0];
      else if (Y[y1] > y)
        ++sum[y1][1];
    }
    long long aug = 0;
    for (int i = 0; i < n; ++i) {
      if (sum[i][0] > 1) {
        long long x = sum[i][0];
        x = x * (x - 1) / 2;
        aug += x;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (sum[i][1] > 1) {
        long long x = sum[i][1];
        x = x * (x - 1) / 2;
        aug += x;
      }
    }
    for (int i = 0; i < n; ++i) sum[i][0] = 0;
    for (int i = 0; i < m; ++i) sum[i][1] = 0;
    sort(a + 1, a + 1 + k, cmpX);
    a[k + 1].x = a[k].x + 1;
    top = 0;
    long long aug2 = 0;
    for (int i = 1; i <= k; ++i) {
      auto y1 = lower_bound(Y, Y + m, a[i].y) - Y;
      if (Y[y1] > a[i].y) {
        ++sum[y1][1];
        if (sum[y1][1] == 1) sta[++top] = y1;
      }
      if (a[i].x != a[i + 1].x) {
        for (int j = 1; j <= top; ++j) {
          if (sum[sta[j]][1] > 1) {
            long long x = sum[sta[j]][1];
            x = x * (x - 1) / 2;
            aug2 += x;
          }
          sum[sta[j]][1] = 0;
        }
        top = 0;
      }
    }
    sort(a + 1, a + 1 + k, cmpY);
    a[k + 1].y = a[k].y + 1;
    top = 0;
    for (int i = 1; i <= k; ++i) {
      auto x1 = lower_bound(X, X + n, a[i].x) - X;
      if (X[x1] > a[i].x) {
        ++sum[x1][0];
        if (sum[x1][0] == 1) sta[++top] = x1;
      }
      if (a[i].y != a[i + 1].y) {
        for (int j = 1; j <= top; ++j) {
          if (sum[sta[j]][0] > 1) {
            long long x = sum[sta[j]][0];
            x = x * (x - 1) / 2;
            aug2 += x;
          }
          sum[sta[j]][0] = 0;
        }
        top = 0;
      }
    }
    aug = aug - aug2;
    printf("%lld\n", aug);
  }
  return 0;
}
