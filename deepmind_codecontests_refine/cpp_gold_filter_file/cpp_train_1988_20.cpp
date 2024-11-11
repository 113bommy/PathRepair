#include <bits/stdc++.h>
using namespace std;
int n;
void NoSol() {
  printf("! -1");
  exit(0);
}
int Query(int x) {
  int a, b;
  printf("? %d\n", x + 1);
  fflush(stdout);
  scanf("%d", &a);
  b = a;
  printf("? %d\n", (x + n / 2) % n + 1);
  fflush(stdout);
  scanf("%d", &a);
  b -= a;
  return b;
}
int bs(int b) {
  int l = 0, r = n / 2;
  if (!b) return 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int bMid = Query(mid);
    if (bMid == 0) return mid;
    if ((bMid < 0 && b < 0) || (bMid > 0 && b > 0))
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l;
}
int main() {
  scanf("%d", &n);
  if (n % 4) NoSol();
  int x = Query(0);
  if (x % 2) NoSol();
  printf("! %d\n", bs(x) + 1);
  fflush(stdout);
  return 0;
}
