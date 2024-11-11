#include <bits/stdc++.h>
using namespace std;
void print(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
}
int x11, x12, y11, y12, x21, x22, y21, y22;
int n;
void solvex() {
  int l, r, cnt;
  l = 1, r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(1, 1, m, n);
    scanf("%d", &cnt);
    if (cnt == 2) {
      r = m;
    } else {
      l = m;
    }
  }
  print(1, 1, l, n);
  scanf("%d", &cnt);
  if (cnt == 2) {
    x22 = l;
  } else {
    x22 = r;
  }
  l = 1, r = x22;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(1, 1, m, n);
    scanf("%d", &cnt);
    if (cnt >= 1) {
      r = m;
    } else {
      l = m;
    }
  }
  print(1, 1, l, n);
  scanf("%d", &cnt);
  if (cnt >= 1) {
    x12 = l;
  } else {
    x12 = r;
  }
  l = 1, r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(m, 1, n, n);
    scanf("%d", &cnt);
    if (cnt == 2) {
      l = m;
    } else {
      r = m;
    }
  }
  print(r, 1, n, n);
  scanf("%d", &cnt);
  if (cnt == 2) {
    x11 = r;
  } else {
    x11 = l;
  }
  l = x11, r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(m, 1, n, n);
    scanf("%d", &cnt);
    if (cnt >= 1) {
      l = m;
    } else {
      r = m;
    }
  }
  print(r, 1, n, n);
  scanf("%d", &cnt);
  if (cnt >= 1) {
    x21 = r;
  } else {
    x21 = l;
  }
}
void solvey() {
  int l, r, cnt;
  l = 1, r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(1, 1, n, m);
    scanf("%d", &cnt);
    if (cnt == 2) {
      r = m;
    } else {
      l = m;
    }
  }
  print(1, 1, n, l);
  scanf("%d", &cnt);
  if (cnt == 2) {
    y22 = l;
  } else {
    y22 = r;
  }
  l = 1, r = y22;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(1, 1, n, m);
    scanf("%d", &cnt);
    if (cnt >= 1) {
      r = m;
    } else {
      l = m;
    }
  }
  print(1, 1, n, l);
  scanf("%d", &cnt);
  if (cnt >= 1) {
    y12 = l;
  } else {
    y12 = r;
  }
  l = 1, r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(1, m, n, n);
    scanf("%d", &cnt);
    if (cnt == 2) {
      l = m;
    } else {
      r = m;
    }
  }
  print(1, r, n, n);
  scanf("%d", &cnt);
  if (cnt == 2) {
    y11 = r;
  } else {
    y11 = l;
  }
  l = y11, r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    print(1, m, n, n);
    scanf("%d", &cnt);
    if (cnt >= 1) {
      l = m;
    } else {
      r = m;
    }
  }
  print(1, r, n, n);
  scanf("%d", &cnt);
  if (cnt >= 1) {
    y21 = r;
  } else {
    y21 = l;
  }
}
bool check() {
  int cnt;
  int s = 0;
  if (x11 > x12 || y11 > y12) return false;
  print(x11, y11, x12, y12);
  scanf("%d", &cnt);
  s += cnt;
  if (x21 > x22 || y21 > y22) return false;
  print(x21, y21, x22, y22);
  scanf("%d", &cnt);
  s += cnt;
  if (s == 2) {
    return true;
  }
  return false;
}
int ans() {
  printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
  fflush(stdout);
  return 0;
}
int main() {
  scanf("%d", &n);
  int l, r;
  int cnt = 0;
  solvex();
  solvey();
  int s;
  if (check()) return ans();
  swap(x11, x21);
  if (check()) return ans();
  swap(x11, x21);
  swap(y11, y21);
  if (check()) return ans();
  swap(x11, x21);
  if (check()) return ans();
  swap(x11, x21);
  swap(y11, y21);
  swap(y11, y21);
  swap(y12, y22);
  if (check()) return ans();
  swap(x11, x21);
  if (check()) return ans();
  swap(x11, x21);
  swap(y11, y21);
  if (check()) return ans();
  swap(x11, x21);
  if (check()) return ans();
  swap(x11, x21);
  swap(y11, y21);
  return 0;
}
