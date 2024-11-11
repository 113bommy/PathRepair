#include <bits/stdc++.h>
using namespace std;
int n, a[1234567], b[1234567], x;
void init() {
  scanf("%d", &n);
  scanf("%d", &x);
  int N;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &N);
    a[i] = N;
    b[N]++;
  }
  long long cnt = 0, rs = 1;
  for (int i = 1; (i) <= (n); ++i) {
    cnt += b[a[i] ^ x];
  }
  if (x % 2 == 0) {
    printf("%lld\n", cnt / 2);
  } else {
    printf("%lld\n", (cnt - n) / 2);
  }
}
int main() {
  init();
  return 0;
}
