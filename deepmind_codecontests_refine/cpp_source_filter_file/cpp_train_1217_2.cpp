#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
template <typename T>
void chkmax(T& x, T y) {
  if (y > x) x = y;
}
template <typename T>
void chkmin(T& x, T y) {
  if (y < x) x = y;
}
int N, M;
struct node {
  int x, y;
} a[MAXN], b[MAXN];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
    if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
  }
  for (int i = 1; i <= M; ++i) {
    scanf("%d%d", &b[i].x, &b[i].y);
    if (b[i].x > b[i].y) swap(b[i].x, b[i].y);
  }
  int per1 = 0;
  for (int i = 1; i <= N; ++i) {
    int cur = 0;
    for (int j = 1; j <= M; ++j) {
      if (a[i].x == b[j].x && a[i].y == b[j].y) continue;
      int qwq;
      if (a[i].x == b[j].x || a[i].x == b[j].y)
        qwq = a[i].x;
      else if (a[i].y == b[j].x || a[i].y == b[j].y)
        qwq = a[i].y;
      else
        continue;
      if (!cur)
        cur = qwq;
      else if (cur != qwq) {
        per1 = -1;
        break;
      }
    }
    if (per1 == -1) break;
    if (cur) per1 = 1;
  }
  int per2 = 0;
  for (int i = 1; i <= M; ++i) {
    int cur = 0;
    for (int j = 1; j <= N; ++j) {
      if (a[j].x == b[i].x && a[j].y == b[i].y) continue;
      int qwq;
      if (a[j].x == b[i].x || a[j].x == b[i].y)
        qwq = a[j].x;
      else if (a[j].y == b[i].x || a[j].y == b[i].y)
        qwq = a[i].y;
      else
        continue;
      if (!cur)
        cur = qwq;
      else if (cur != qwq) {
        per2 = -1;
        break;
      }
    }
    if (per2 == -1) break;
    if (cur) per2 = 1;
  }
  int my = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (a[i].x == b[j].x && a[i].y == b[j].y) continue;
      int qwq;
      if (a[i].x == b[j].x || a[i].x == b[j].y)
        qwq = a[i].x;
      else if (a[i].y == b[j].x || a[i].y == b[j].y)
        qwq = a[i].y;
      else
        continue;
      if (!my)
        my = qwq;
      else if (my != qwq) {
        my = -1;
        break;
      }
    }
    if (my == -1) break;
  }
  if (my >= 1)
    printf("%d", my);
  else if (per1 == 1 && per2 == 1)
    printf("0");
  else
    printf("-1");
  return 0;
}
