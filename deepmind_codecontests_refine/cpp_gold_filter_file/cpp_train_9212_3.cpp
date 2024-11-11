#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const int N = 333;
struct Node {
  int x, y;
  int id;
} a[N];
int main() {
  int i, j, k;
  int len = 0;
  for (i = 0; i < 3; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].id = i;
    len = max(len, max(a[i].x, a[i].y));
  }
  for (i = 0; i < 3; ++i) {
    if (a[i].y == len) swap(a[i].y, a[i].x);
  }
  if (a[0].x == len && a[1].x == len && a[2].x == len) {
    if (a[0].y + a[1].y + a[2].y == len) {
      printf("%d\n", len);
      for (k = 0; k < 3; ++k) {
        for (i = 0; i < a[k].y; ++i) {
          for (j = 0; j < len; ++j) {
            printf("%c", a[k].id + 'A');
          }
          puts("");
        }
      }
      return 0;
    }
  } else {
    for (i = 0; i < 3; ++i) {
      if (a[i].x == len) {
        swap(a[0], a[i]);
        break;
      }
    }
    if (a[1].y + a[0].y == len) swap(a[1].y, a[1].x);
    if (a[2].y + a[0].y == len) swap(a[2].y, a[2].x);
    if (a[1].x + a[0].y == len && a[2].x + a[0].y == len) {
      if (a[1].y + a[2].y == len) {
        printf("%d\n", len);
        for (i = 0; i < a[0].y; ++i) {
          for (j = 0; j < len; ++j) {
            printf("%c", a[0].id + 'A');
          }
          puts("");
        }
        for (i = a[0].y; i < len; ++i) {
          for (j = 0; j < a[1].y; ++j) {
            printf("%c", a[1].id + 'A');
          }
          for (j = a[1].y; j < len; ++j) {
            printf("%c", a[2].id + 'A');
          }
          puts("");
        }
        return 0;
      }
    }
  }
  puts("-1");
}
