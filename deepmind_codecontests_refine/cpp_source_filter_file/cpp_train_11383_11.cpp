#include <bits/stdc++.h>
uint32_t n;
uint32_t a[(100000 + 4)];
int main(int argc, char** argv) {
  scanf("%d", &n);
  for (uint32_t i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  const uint32_t n_minus_one = n - 1;
  uint64_t t;
  uint64_t count = 0;
  for (uint32_t i = 0; i < n_minus_one; i++) {
    count += a[i];
    t = n - i - 2;
    t++;
    t = t | t >> 1;
    t = t | t >> 2;
    t = t | t >> 4;
    t = t | t >> 8;
    t = t | t >> 16;
    t = t | t >> 32;
    t++;
    t = t >> 1;
    ;
    a[i + t] += a[i];
    printf("%d\n", count);
  }
  return 0;
}
