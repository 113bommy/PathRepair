#include <bits/stdc++.h>
using namespace std;
const int n = 1 * 1e7 + 200;
const int mod = 1e9 + 7;
int N;
int main() {
  scanf("%d", &N);
  if (N <= 2) {
    puts("-1");
  } else {
    puts("10\n6\n21");
    long long r = 50;
    for (int i = 4; i <= N; i++) {
      printf("%lld\n", r);
      r *= 5;
    }
  }
  return 0;
}
