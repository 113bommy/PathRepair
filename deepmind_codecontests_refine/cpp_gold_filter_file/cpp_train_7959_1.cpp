#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%*d %*d %d", &n);
  pair<int, int> h[4];
  int m0 = 2100000000, m1 = (-1) * 2100000000, m2 = (-1) * 2100000000,
      m3 = (-1) * 2100000000;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x + y < m0) {
      m0 = x + y;
      h[0].first = x;
      h[0].second = y;
    }
    if (x + y > m2) {
      m2 = x + y;
      h[2].first = x;
      h[2].second = y;
    }
    if (x - y > m1) {
      m1 = x - y;
      h[1].first = x;
      h[1].second = y;
    }
    if (y - x > m3) {
      m3 = y - x;
      h[3].first = x;
      h[3].second = y;
    }
  }
  int N;
  scanf("%d", &N);
  int m = 2100000000, no = 2100000000;
  for (int i = 0; i < N; i++) {
    int xx, yy, mm;
    mm = 0;
    scanf("%d %d", &xx, &yy);
    int a[4];
    for (int j = 0; j < 4; j++) {
      a[j] = abs(xx - h[j].first) + abs(yy - h[j].second);
      if (a[j] > mm) {
        mm = a[j];
      }
    }
    if (mm < m) {
      m = mm;
      no = i + 1;
    }
  }
  printf("%d\n%d\n", m, no);
}
