#include <bits/stdc++.h>
int main() {
  double k, b, n, t;
  double bacteria = 1;
  double time = 0;
  scanf("%lf %lf %lf %lf", &k, &b, &n, &t);
  while (bacteria <= t) {
    bacteria = (k * bacteria + b);
    if (bacteria > t) {
      break;
    } else if (bacteria == t) {
      time++;
      break;
    }
    time++;
  }
  if (time > n) {
    n = 0;
  } else {
    n -= time;
  }
  printf("%0.0lf", n);
  return 0;
}
