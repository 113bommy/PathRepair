#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e6 + 100;
const double PI = acos(-1.0);
void fre() {
  freopen("/Users/luras/Desktop/in.txt", "r", stdin);
  freopen("/Users/luras/Desktop/out.txt", "w", stdout);
}
const long long Z = 25 * 1e8;
struct A {
  int x, y, ord, num;
} a[N];
int cmp(A a, A b) {
  if (a.ord == b.ord) {
    if (a.ord % 2) {
      if (a.y == b.y) {
        if (a.y % 2) {
          return a.x < b.x;
        } else
          return a.x > b.x;
      } else {
        return a.y < b.y;
      }
    } else {
      if (a.y == b.y) {
        if (a.y % 2) {
          return a.x < b.x;
        } else
          return a.x > b.x;
      } else {
        return a.y > b.y;
      }
    }
  } else
    return a.ord < b.ord;
}
int n;
double ans;
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
      a[i].ord = a[i].x / 1000;
      a[i].num = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i < n; i++) {
      printf("%d ", a[i].num);
    }
    printf("%d\n", a[n].num);
  }
  return 0;
}
