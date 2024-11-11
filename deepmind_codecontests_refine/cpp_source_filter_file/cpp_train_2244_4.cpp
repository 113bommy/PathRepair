#include <bits/stdc++.h>
using namespace std;
const int STEP = 20;
vector<int> find_rect(int left, int down, int right, int up) {
  vector<int> res(4);
  int c;
  int l = left, r = right + 1, m;
  for (int i = 0; i < STEP; ++i) {
    m = ((l + r) >> 1);
    printf("? %d %d %d %d\n", left, down, m, up);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0)
      r = m;
    else
      l = m;
  }
  int x1_2 = r;
  l = left, ++r;
  for (int i = 0; i < STEP; ++i) {
    m = ((l + r) >> 1);
    printf("? %d %d %d %d\n", m, down, x1_2, up);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0)
      l = m;
    else
      r = m;
  }
  int x1_1 = l;
  l = down, r = up + 1;
  for (int i = 0; i < STEP; ++i) {
    m = ((l + r) >> 1);
    printf("? %d %d %d %d\n", x1_1, down, x1_2, m);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0)
      r = m;
    else
      l = m;
  }
  int y1_2 = r;
  l = down, ++r;
  for (int i = 0; i < STEP; ++i) {
    m = ((l + r) >> 1);
    printf("? %d %d %d %d\n", x1_1, m, x1_2, y1_2);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0)
      l = m;
    else
      r = m;
  }
  int y1_1 = l;
  res[0] = x1_1, res[1] = y1_1, res[2] = x1_2, res[3] = y1_2;
  return res;
}
int main() {
  int n, c;
  cin >> n;
  vector<int> a, b;
  a = find_rect(1, 1, n, n);
  if (a[0] != 1) {
    printf("? %d %d %d %d\n", 1, 1, a[0] - 1, n);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0) {
      b = find_rect(1, 1, a[0] - 1, n);
      goto exit;
    }
  }
  if (a[2] != n) {
    printf("? %d %d %d %d\n", a[2] + 1, 1, n, n);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0) {
      b = find_rect(a[2] + 1, 1, n, n);
      goto exit;
    }
  }
  if (a[1] != n) {
    printf("? %d %d %d %d\n", 1, 1, n, a[1] - 1);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0) {
      b = find_rect(1, 1, n, a[1] - 1);
      goto exit;
    }
  }
  if (a[3] != n) {
    printf("? %d %d %d %d\n", 1, a[3] + 1, n, n);
    fflush(stdout);
    scanf("%d", &c);
    if (c > 0) {
      b = find_rect(1, a[3] + 1, n, n);
      goto exit;
    }
  }
exit:
  printf("! %d %d %d %d %d %d %d %d", a[0], a[1], a[2], a[3], b[0], b[1], b[2],
         b[3]);
  fflush(stdout);
  return 0;
}
