#include <bits/stdc++.h>
using namespace std;
struct range {
  int a;
  int b;
};
range arr[400000];
int mark[400000];
int main() {
  int t;
  scanf("%d", &t);
  for (int y = 0; y < t; y++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &arr[i].a, &arr[i].b);
      mark[i] = 0;
    }
    int l = arr[0].a;
    int r = arr[0].b;
    for (int k = 0; k < 3400; k++) {
      for (int i = 0; i < n; i++) {
        if (arr[i].a >= l and arr[i].a <= r) {
          l = min(l, arr[i].a);
          r = max(r, arr[i].b);
          mark[i] = 1;
        } else if (arr[i].b >= l and arr[i].b <= r) {
          l = min(l, arr[i].a);
          r = max(r, arr[i].b);
          mark[i] = 1;
        } else if (l >= arr[i].a and l <= arr[i].b) {
          l = min(l, arr[i].a);
          r = max(r, arr[i].b);
          mark[i] = 1;
        } else if (r >= arr[i].a and r <= arr[i].b) {
          l = min(l, arr[i].a);
          r = max(r, arr[i].b);
          mark[i] = 1;
        }
      }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (mark[i] == 0) {
        flag = true;
      }
    }
    if (!flag) {
      printf("-1\n");
    } else {
      for (int i = 0; i < n; i++) {
        if (mark[i] == 1) {
          printf("1 ");
        } else {
          printf("2 ");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
