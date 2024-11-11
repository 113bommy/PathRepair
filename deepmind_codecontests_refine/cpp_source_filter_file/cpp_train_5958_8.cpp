#include <bits/stdc++.h>
using namespace std;
int i, j;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long int N, g, b;
    scanf("%lld %lld %lld", &N, &g, &b);
    long long int day = N / 2 + N % 2;
    if (N <= g) {
      printf("%lld\n", N);
    } else {
      long long int ans = day / g * (g + b) - (!(day % g) ? b : 0) + day % g;
      printf("%lld\n", ans);
    }
  }
}
