#include <bits/stdc++.h>
using namespace std;
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  int n = ri(), r = ri(), v = ri();
  for (int i = 0; i < int(n); ++i) {
    int s = ri(), f = ri();
    int dist = f - s;
    long double a = 0;
    long double b = 1e9 + 10;
    for (int k = 0; k < int(50); ++k) {
      long double ctime = (a + b) * 0.5;
      long double cdist = ctime * v + r * fabs(sin((long double)v / r * ctime));
      if (cdist * 2 > dist)
        b = ctime;
      else
        a = ctime;
    }
    printf("%.9f\n", (double)(a + b));
  }
  return 0;
}
