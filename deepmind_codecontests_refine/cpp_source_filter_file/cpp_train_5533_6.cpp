#include <bits/stdc++.h>
static void print_int(int64_t n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n == 0) {
    putchar('0');
    return;
  }
  int s[20], len = 0;
  while (n > 0) {
    s[len++] = n % 10 + '0';
    n /= 10;
  }
  while (len > 0) {
    putchar(s[--len]);
  }
}
static int64_t read_int(void) {
  int prev = '\0';
  int c = getchar();
  while (!('0' <= c && c <= '9')) {
    prev = c;
    c = getchar();
  }
  int64_t res = 0;
  while ('0' <= c && c <= '9') {
    res = 10 * res + c - '0';
    c = getchar();
  }
  return prev == '-' ? -res : res;
}
const int32_t mod = 1000000007;
int32_t inv(int32_t a) {
  int32_t t = 1;
  while (a > 1) {
    t = (int64_t)t * (mod - mod / a) % mod;
    a = mod % a;
  }
  return t;
}
void run(void) {
  const int32_t n = read_int();
  int32_t *factor = (int32_t *)calloc(n + 1, sizeof(int32_t));
  for (int32_t i = 1; i <= n; ++i) {
    factor[i] = i;
  }
  for (int32_t i = 2; i * i <= n; ++i) {
    if (factor[i] < i) continue;
    for (int32_t j = i * i; j <= n; j += i) {
      factor[j] = i;
    }
  }
  int32_t *dp = (int32_t *)calloc(n + 1, sizeof(int32_t));
  dp[1] = 0;
  for (int32_t i = 2; i <= n; ++i) {
    int32_t f[64];
    f[0] = 1;
    int32_t len = 1;
    int32_t t = i;
    while (t > 1) {
      int32_t p = factor[t];
      while (t % p == 0) {
        t /= p;
      }
      for (int32_t j = 0; j < len; ++j) {
        f[j + len] = f[j] * p;
      }
      len *= 2;
    }
    if (f[len - 1] != i) {
      dp[i] = dp[f[len - 1]];
      continue;
    }
    int32_t prob[64];
    for (int32_t j = 0; j < len; ++j) {
      prob[j] = (int64_t)(n / f[j]) * inv(n) % mod;
    }
    for (int32_t j = len - 1; j >= 0; --j) {
      for (int32_t k = j - 1; k >= 0; --k) {
        if ((j & k) == k) {
          prob[k] = (prob[k] - prob[j] + mod) % mod;
        }
      }
    }
    int32_t local = 1;
    for (int32_t j = 0; j < len - 1; ++j) {
      local = (local + (int64_t)prob[j] * dp[f[j]]) % mod;
    }
    dp[i] = local * inv((1 - prob[len - 1] + mod) % mod) % mod;
  }
  int32_t ans = 1;
  for (int32_t i = 1; i <= n; ++i) {
    ans = (ans + (int64_t)dp[i] * inv(n)) % mod;
  }
  print_int(ans);
  puts("");
}
int main(void) {
  run();
  return 0;
}
