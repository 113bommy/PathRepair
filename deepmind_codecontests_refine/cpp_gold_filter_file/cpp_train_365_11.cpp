#include <bits/stdc++.h>
using namespace std;
typedef struct pt {
  long long x;
  long long y;
};
int n;
long long const INF = (long long)1e18;
long long const UNK = (long long)2e18;
pt A, B;
pt v[2000];
double intersection(pt p1, pt p2) {
  if (p2.y == p1.y) {
    if (p1.x > p2.x) return -INF;
    return INF;
  }
  if (!((p2.y > p1.y) ^ (p1.y > A.y))) {
    return UNK;
  }
  double val = p2.x - 1.0 * (p2.y - A.y) / (p2.y - p1.y) * (p2.x - p1.x);
  return val;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d %I64d", &v[i].x, &v[i].y);
  }
  if (v[2].y > v[0].y) {
    for (int i = 0; i < n; i++) {
      v[i].y = -v[i].y;
    }
  }
  if (v[1].x < v[0].x) {
    for (int i = 0; i < n; i++) {
      v[i].x = -v[i].x;
    }
  }
  A = v[0];
  B = v[1];
  double top = INF;
  double bottom = -INF;
  for (int i = 2; i < n; i++) {
    double left = intersection(v[i], v[(i + 1) % n]);
    double right = intersection(v[i], v[i - 1]);
    if (left != UNK && right != UNK) {
      top = min(top, right);
      bottom = max(bottom, left);
    } else if (right != UNK) {
      top = min(top, right);
    } else if (left != UNK) {
      bottom = max(bottom, left);
    } else {
      double t1 = atan2(v[i - 1].y - v[i].y, v[i - 1].x - v[i].x);
      double t2 = atan2(v[i + 1].y - v[i].y, v[i + 1].x - v[i].x);
      if (t1 < t2) {
        top = -INF;
        bottom = INF;
        break;
      }
    }
  }
  int count = 0;
  for (int i = A.x; i <= B.x; i++) {
    if (i >= bottom && i <= top) {
      count++;
    }
  }
  printf("%d\n", count);
}
