#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3000], n, i = 0, t = 10, t1 = 190;
  scanf("%d", &n);
  for (i = 1; i <= 10; i++) {
    a[i] = i;
  }
  for (i = 10; i <= 100; i++) {
    a[t] = i / 10;
    a[t + 1] = i % 10;
    t += 2;
  }
  for (i = 100; i < 1000; i++) {
    a[t1] = i / 100;
    a[t1 + 1] = i / 10 % 10;
    a[t1 + 2] = i % 10;
    t1 += 3;
  }
  printf("%d", a[n]);
}
