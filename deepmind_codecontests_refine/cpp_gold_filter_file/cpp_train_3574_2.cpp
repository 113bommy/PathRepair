#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int e;
  int l = 0;
  int h = 0;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d ", &e);
    if (e < x) {
      ++l;
    } else if (e > x) {
      ++h;
    } else {
      ++s;
    }
  }
  int half = (n + 1) / 2;
  if (l < half) {
    if (s + l >= half) {
      printf("0\n");
      return 0;
    } else {
      if (s) {
        printf("%d\n", h - l - s);
      } else {
        printf("%d\n", h - l);
      }
      return 0;
    }
  } else {
    if (s) {
      printf("%d\n", l - h - s + 1);
    } else {
      printf("%d\n", l - h + 1);
    }
    return 0;
  }
}
