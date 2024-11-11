#include <bits/stdc++.h>
using namespace std;
int f(long long m, long long k) {
  long long cnt = m / (k + 1);
  if (cnt & 1) {
    if (m & 1)
      return 1;
    else
      return 0;
  } else {
    if (m & 1)
      return 0;
    else
      return 1;
  }
}
int rec(long long v, long long k) {
  if (k == 0) return 1;
  if (v % k == 0) return 0;
  int r = rec(k, v % k);
  if (r) return 0;
  if (!(k & 1)) {
    if (f(v / k, k))
      return 0;
    else
      return 1;
  } else {
    if ((v / k) & 1)
      return 1;
    else
      return 0;
  }
}
int main() {
  int t;
  long long a, b;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%I64d%I64d", &a, &b);
    if (rec(max(a, b), min(a, b)))
      printf("Second");
    else
      printf("First");
    printf("\n");
  }
  return 0;
}
