#include <bits/stdc++.h>
const int N = 300300;
int a, b, c, d;
long long lens[N];
long long sum;
long long calcSum(long long len) {
  if (len < 0) return 0;
  return lens[len];
}
void calcOne(int a, int b, int c) {
  for (int i = 0; i <= d; ++i) {
    long long maxbc = a + i;
    long long delta = d - i;
    if (maxbc - b - c < delta) delta = maxbc - b - c;
    sum -= calcSum(delta);
  }
}
int main() {
  lens[0] = 1;
  for (int i = 1; i < N; ++i) lens[i] = lens[i - 1] + i + 1;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = 0; i <= d; ++i) sum += 1LL * (i + 2) * (i + 1) / 2LL;
  calcOne(a, b, c);
  calcOne(b, a, c);
  calcOne(c, a, b);
  printf("%I64d\n", sum);
  return 0;
}
