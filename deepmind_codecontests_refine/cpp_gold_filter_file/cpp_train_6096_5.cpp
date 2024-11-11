#include <bits/stdc++.h>
using namespace std;
int check(int x1, int y1, int x2, int y2) {
  if (x2 < x1 || y2 < y1) return 0;
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
pair<pair<int, int>, pair<int, int> > Search(int x1, int y1, int x2, int y2) {
  int L = x1 + 1, R = x2;
  int ans1 = x1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid, y1, x2, y2) >= 1) {
      ans1 = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  L = ans1, R = x2 - 1;
  int ans2 = x2;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans1, y1, mid, y2) >= 1) {
      ans2 = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  L = y1 + 1, R = y2;
  int ans3 = y1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans1, mid, ans2, y2) >= 1) {
      ans3 = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  L = ans3, R = y2 - 1;
  int ans4 = y2;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans1, ans3, ans2, mid) >= 1) {
      ans4 = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  return make_pair(make_pair(ans1, ans3), make_pair(ans2, ans4));
}
int main() {
  int n;
  scanf("%d", &n);
  int L = 2, R = n, ans = 1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid, 1, n, n) >= 2) {
      ans = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  L = ans, R = n - 1;
  int ans2 = n;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans, 1, mid, n) >= 2) {
      ans2 = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  L = 2, R = n;
  int ans3 = 1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans, mid, ans2, n) >= 2) {
      ans3 = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  L = ans3, R = n - 1;
  int ans4 = n;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans, ans3, ans2, mid) >= 2) {
      ans4 = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  int x1 = ans, x2 = ans2, y1 = ans3, y2 = ans4;
  L = x1 + 1, R = x2;
  int ans5 = x1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid, y1, x2, y2) >= 1) {
      ans5 = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  L = ans5, R = x2 - 1;
  int ans6 = x2;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans5, y1, mid, y2) >= 1) {
      ans6 = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  L = y1 + 1, R = y2;
  int ans7 = y1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans5, mid, ans6, y2) >= 1) {
      ans7 = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  L = ans7, R = y2 - 1;
  int ans8 = y2;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(ans5, ans7, ans6, mid) >= 1) {
      ans8 = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  int x11 = ans5, x12 = ans6, y11 = ans7, y12 = ans8;
  pair<pair<int, int>, pair<int, int> > p;
  if (check(x1, y1, x11 - 1, y2) == 1)
    p = Search(x1, y1, x11 - 1, y2);
  else if (check(x1, y1, x2, y11 - 1) == 1)
    p = Search(x1, y1, x2, y11 - 1);
  else if (check(x12 + 1, y1, x2, y2) == 1)
    p = Search(x12 + 1, y1, x2, y2);
  else if (check(x1, y12 + 1, x2, y2) == 1)
    p = Search(x1, y12 + 1, x2, y2);
  int x21 = p.first.first, x22 = p.second.first, y21 = p.first.second,
      y22 = p.second.second;
  printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
  fflush(stdout);
  return 0;
}
