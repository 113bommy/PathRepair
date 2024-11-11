#include <bits/stdc++.h>
long long n, m;
long long size[2][1 << 10];
void init() { std::cin >> n >> m; }
long long getDigit(long long x) {
  long long result = 1;
  long long cc = 7;
  while (cc - 1 < x) {
    result++;
    cc *= 7;
  }
  return result;
}
long long getState(long long x, long long y) {
  long long result = 0;
  for (long long i = 1; i <= y; i++) {
    result |= (1 << (x % 7));
    x /= 7;
  }
  return result;
}
void work() {
  long long c = getDigit(n), d = getDigit(m);
  if (c + d > 7) {
    printf("0\n");
    return;
  }
  for (long long i = 0; i <= n - 1; i++) {
    long long state = getState(i, c);
    if (__builtin_popcount(state) == c) {
      size[0][state]++;
    }
  }
  for (long long i = 0; i <= m - 1; i++) {
    long long state = getState(i, d);
    if (__builtin_popcount(state) == d) {
      size[1][state]++;
    }
  }
  long long answer = 0;
  for (long long s0 = 0; s0 < (1 << 7); s0++) {
    for (long long s1 = 0; s1 < (1 << 7); s1++) {
      if ((s0 & s1) == 0) {
        answer += size[0][s0] * size[1][s1];
      }
    }
  }
  std::cout << answer << std::endl;
}
int main() {
  init();
  work();
  return 0;
}
