#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a >= b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a >= b)
    return b;
  else
    return a;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    long long int a, b, n, c, d;
    scanf("%lld %lld %lld", &a, &b, &n);
    int cnt = 0;
    c = min(a, b), d = max(a, b);
    while (c <= n && d <= n) {
      if (cnt % 2 == 0) {
        d += c;
        cnt++;
      } else {
        c += d;
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }
}
