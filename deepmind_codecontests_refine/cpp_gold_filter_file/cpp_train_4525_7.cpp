#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, z;
} a[2050];
bool cmp(node aa, node bb) { return aa.x < bb.x; }
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].x);
    a[i].y = i + 1;
  }
  sort(a, a + n, cmp);
  int t = 0;
  int num[2050];
  memset(num, 0, sizeof(num));
  num[0] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i].x != a[i - 1].x) {
      ++t;
      num[t] = 1;
    } else {
      num[t]++;
    }
  }
  int sum = 1;
  int flag = 0;
  for (int i = 0; i <= t; i++) {
    sum *= num[i];
    if (sum >= 3) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    puts("YES");
    for (int i = 0; i < n; i++) {
      printf("%d", a[i].y);
      if (i != n - 1) printf(" ");
    }
    puts("");
    for (int i = 0; i < n; i++) {
      if (a[i].x == a[i + 1].x) {
        swap(a[i].y, a[i + 1].y);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%d", a[i].y);
      if (i != n - 1) printf(" ");
    }
    puts("");
    for (int i = n; i >= 0; i--) {
      if (a[i].x == a[i - 1].x) {
        swap(a[i].y, a[i - 1].y);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%d", a[i].y);
      if (i != n - 1) printf(" ");
    }
    puts("");
  } else
    puts("NO");
}
