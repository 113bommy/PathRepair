#include <bits/stdc++.h>
using namespace std;
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
int L1 = 1, L2 = 2, R1 = 4, R2 = 3;
int B1 = 5, B2 = 1, U1 = 5, U2 = 5;
vector<pair<pair<int, int>, pair<int, int> > > ans;
int n;
int get(int x, int y, int xx, int yy) {
  printf("? %d %d %d %d\n", x, y, xx, yy);
  fflush(stdout);
  int o;
  scanf("%d", &o);
  return o;
}
void find(int x, int y, int xx, int yy) {
  int l = x - 1, r = xx;
  while (l + 1 < r) {
    int mid = (l + r + 1) >> 1;
    if (get(x, y, mid, yy))
      r = mid;
    else
      l = mid;
  }
  xx = r;
  l = x, r = xx + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (get(mid, y, xx, yy))
      l = mid;
    else
      r = mid;
  }
  x = l;
  l = y - 1, r = yy;
  while (l + 1 < r) {
    int mid = (l + r + 1) >> 1;
    if (get(x, y, xx, mid))
      r = mid;
    else
      l = mid;
  }
  yy = r;
  l = y, r = yy + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (get(x, mid, xx, yy))
      l = mid;
    else
      r = mid;
  }
  y = l;
  ans.push_back(make_pair(make_pair(x, y), make_pair(xx, yy)));
}
bool check1() {
  int l1 = 0, r1 = n;
  while (l1 + 1 < r1) {
    int mid = (l1 + r1 + 1) >> 1;
    if (get(1, 1, mid, n))
      r1 = mid;
    else
      l1 = mid;
  }
  int l2 = 1, r2 = n + 1;
  while (l2 + 1 < r2) {
    int mid = (l2 + r2) >> 1;
    if (get(mid, 1, n, n))
      l2 = mid;
    else
      r2 = mid;
  }
  if (r1 >= l2) return 0;
  find(1, 1, r1, n);
  find(l2, 1, n, n);
  return 1;
}
bool check2() {
  int l1 = 0, r1 = n;
  while (l1 + 1 < r1) {
    int mid = (l1 + r1 + 1) >> 1;
    if (get(1, 1, n, mid))
      r1 = mid;
    else
      l1 = mid;
  }
  int l2 = 1, r2 = n + 1;
  while (l2 + 1 < r2) {
    int mid = (l2 + r2) >> 1;
    if (get(1, mid, n, n))
      l2 = mid;
    else
      r2 = mid;
  }
  find(1, 1, n, r1);
  find(1, l2, n, n);
  return 1;
}
int main() {
  scanf("%d", &n);
  if (!check1()) check2();
  printf("! ");
  for (auto v : ans)
    printf("%d %d %d %d ", v.first.first, v.first.second, v.second.first,
           v.second.second);
  fflush(stdout);
  return 0;
}
