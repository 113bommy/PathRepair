#include <bits/stdc++.h>
using namespace std;
const int maxn = 400;
const double EPS = 1e-9;
typedef struct {
  int x, y;
} TPoint;
int det(const TPoint &A, const TPoint &B, const TPoint &C) {
  return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}
int cmp(const void *t1, const void *t2) {
  TPoint *A, *B;
  A = (TPoint *)t1;
  B = (TPoint *)t2;
  if (A->y < B->y || (A->y == B->y && A->x < B->x)) {
    return -1;
  } else {
    return 1;
  }
}
void calcConvexHull(TPoint p[], int N, vector<TPoint> &ch) {
  int i;
  vector<TPoint> stack;
  ch.clear();
  qsort(p, N, sizeof(TPoint), cmp);
  if (N <= 3) {
    for (i = 0; i < N; i++) {
      ch.push_back(p[i]);
    }
    return;
  }
  stack.clear();
  stack.push_back(p[0]);
  stack.push_back(p[1]);
  int top = 1;
  for (i = 2; i < N; i++) {
    while (top >= 1 && det(stack[top - 1], stack[top], p[i]) < 0) {
      top--;
      stack.pop_back();
    }
    stack.push_back(p[i]);
    top++;
  }
  for (i = 0; i < stack.size() - 1; i++) {
    ch.push_back(stack[i]);
  }
  stack.clear();
  stack.push_back(p[N - 1]);
  stack.push_back(p[N - 2]);
  top = 1;
  for (i = N - 3; i >= 0; i--) {
    while (top >= 1 && det(stack[top - 1], stack[top], p[i]) < 0) {
      top--;
      stack.pop_back();
    }
    stack.push_back(p[i]);
    top++;
  }
  for (i = 0; i < stack.size() - 1; i++) {
    ch.push_back(stack[i]);
  }
}
int abs(int x) { return (x > 0) ? x : (-x); }
int main() {
  TPoint p[400];
  vector<TPoint> ch;
  int N;
  int result;
  while (1 == scanf("%d", &N)) {
    for (int i = 0; i < N; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    calcConvexHull(p, N, ch);
    if (ch.size() == 3) {
      int area = abs(det(ch[0], ch[1], ch[2]));
      result = 0;
      for (int i = 0; i < N; i++) {
        if (p[i].x == ch[0].x && p[i].y == ch[0].y) continue;
        if (p[i].x == ch[1].x && p[i].y == ch[1].y) continue;
        if (p[i].x == ch[2].x && p[i].y == ch[2].y) continue;
        result = max(result, area - abs(det(ch[0], ch[1], p[i])));
        result = max(result, area - abs(det(ch[1], ch[2], p[i])));
        result = max(result, area - abs(det(ch[2], ch[0], p[i])));
      }
    } else if (ch.size() == 4) {
      result = abs(det(ch[0], ch[1], ch[2])) + abs(det(ch[0], ch[3], ch[2]));
    } else {
      result = 0;
      int M = ch.size();
      for (int i = 0; i <= M - 4; i++) {
        for (int j = i + 2; j <= M - 2; j++) {
          int area1 = 0;
          for (int k = i + 1; k < j; k++) {
            area1 = max(area1, abs(det(ch[i], ch[j], ch[k])));
          }
          int area2 = 0;
          for (int k = j + 1; k < M; k++) {
            area2 = max(area2, abs(det(ch[i], ch[j], ch[k])));
          }
          result = max(result, area1 + area2);
        }
      }
    }
    printf("%.9lf\n", 0.5 * (double)result);
  }
  return 0;
}
