#include <bits/stdc++.h>
using namespace std;
const int BS = 1 << 17;
char buf[BS], *S, *T;
inline char gc() {
  if (S == T) T = (S = buf) + fread(buf, 1, BS, stdin);
  return S != T ? *(S++) : EOF;
}
inline int in() {
  int x = 0, f = 1;
  char c = gc();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = gc();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = gc();
  return x * f;
}
const int N = 1e5 + 5, inf = 1e9;
int n;
int c[4];
struct point {
  int x, y;
  point(int _x = 0, int _y = 0) { x = _x, y = _y; }
};
vector<point> v1[4], v2[4];
inline bool cmp1(const point &a, const point &b) { return a.x < b.x; }
inline bool cmp2(const point &a, const point &b) { return a.y < b.y; }
bool check1(int x, int xx, int y, int yy, int k) {
  int cnt = 0, l = inf, r = -inf;
  for (point p : v1[c[2]]) {
    if (p.x >= x && p.x <= xx && p.y >= y && p.y <= yy) {
      cnt++;
      if (cnt == k) {
        l = p.x;
        break;
      }
    }
  }
  cnt = 0;
  for (int i = n / 3 - 1; i >= 0; i--) {
    point p = v1[c[3]][i];
    if (p.x >= x && p.x <= xx && p.y >= y && p.y <= yy) {
      cnt++;
      if (cnt == k) {
        r = p.x;
        break;
      }
    }
  }
  if (l < r) return 1;
  l = inf, r = -inf, cnt = 0;
  for (point p : v2[c[2]]) {
    if (p.x >= x && p.x <= xx && p.y >= y && p.y <= yy) {
      cnt++;
      if (cnt == k) {
        l = p.y;
        break;
      }
    }
  }
  cnt = 0;
  for (int i = n / 3 - 1; i >= 0; i--) {
    point p = v2[c[3]][i];
    if (p.x >= x && p.x <= xx && p.y >= y && p.y <= yy) {
      cnt++;
      if (cnt == k) {
        r = p.y;
        break;
      }
    }
  }
  if (l < r) return 1;
  return 0;
}
bool check(int k) {
  c[1] = 1, c[2] = 2, c[3] = 3;
  do {
    int x = v1[c[1]][k - 1].x;
    if (check1(x + 1, inf, -inf, inf, k)) return 1;
    int y = v2[c[1]][k - 1].y;
    if (check1(-inf, inf, y + 1, inf, k)) return 1;
    x = v1[c[1]][n / 3 - k].x;
    if (check1(-inf, x - 1, -inf, inf, k)) return 1;
    y = v2[c[1]][n / 3 - k].y;
    if (check1(-inf, inf, -inf, y - 1, k)) return 1;
  } while (next_permutation(c + 1, c + 4));
  return 0;
}
int main() {
  n = in();
  for (int i = 1; i <= n; i++) {
    int x = in(), y = in(), c = in();
    v1[c].push_back(point(x, y));
    v2[c].push_back(point(x, y));
  }
  for (int i = 1; i <= 3; i++) {
    sort(v1[i].begin(), v1[i].end(), cmp1);
    sort(v2[i].begin(), v2[i].end(), cmp2);
  }
  int l = 1, r = n / 3, mid, ans = 1;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans * 3;
  return 0;
}
