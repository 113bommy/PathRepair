#include <bits/stdc++.h>
using namespace std;
long long d, k, a, b, t, T = 0;
void read() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &d, &k, &a, &b, &t);
  return;
}
void init() { return; }
void work() {
  if (d <= k) {
    T = d * a;
    return;
  } else {
    d -= k;
    T += k * a;
    if (d > k) {
      if (k * a + t > k * b) {
        T += d * b;
        return;
      } else {
        long long tmp = d / k;
        T += tmp * (k * a + t);
        d -= k * tmp;
        T += (((d * a + t) > (d * b)) ? (d * b) : (d * a + t));
        return;
      }
    } else {
      T += (((d * a + t) > (d * b)) ? (d * b) : (d * a + t));
    }
  }
  return;
}
void print() {
  printf("%I64d", T);
  return;
}
int main() {
  read();
  init();
  work();
  print();
  return 0;
}
