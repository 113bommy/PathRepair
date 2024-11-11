#include <bits/stdc++.h>
int32_t bin_pow(int32_t base, int64_t pow, int32_t mod) {
  if (pow == 0) return 1;
  if (pow == 1) return base;
  if (pow % 2 == 0) {
    int32_t prev = bin_pow(base, pow / 2, mod);
    return ((int64_t)prev * prev) % mod;
  } else {
    return ((int64_t)bin_pow(base, pow - 1, mod) * base) % mod;
  }
}
std::pair<int32_t, int32_t> fib(int64_t num, int32_t mod) {
  if (num == 0) return {0, 1};
  std::pair<int32_t, int32_t> prev = fib(num / 2, mod);
  int32_t c = ((int64_t)prev.first *
               (((int64_t)prev.second * 2 - prev.first + mod) % mod)) %
              mod;
  int32_t d =
      ((int64_t)prev.first * prev.first + (int64_t)prev.second * prev.second) %
      mod;
  if (num % 2 == 0) {
    return {c, d};
  } else {
    return {d, (c + d) % mod};
  }
}
int main() {
  int64_t n;
  uint64_t res;
  int32_t num_bits, mod;
  std::cin >> n >> res >> num_bits >> mod;
  if (num_bits == 0) {
    if (res >= 1) {
      std::cout << 0;
      return 0;
    }
    if (res == 0) {
      std::cout << 1;
      return 0;
    }
  }
  int32_t num_without = fib(n + 2, mod).first;
  int32_t num_with = (bin_pow(2, n, mod) - num_without + mod) % mod;
  int32_t answer = 1;
  for (int32_t i = 0; i < 64; i++) {
    bool one = ((1ull << i) & res) != 0;
    if (one && i >= num_bits) {
      std::cout << 0;
      return 0;
    }
    if (i < num_bits) {
      if (one)
        answer = ((int64_t)answer * num_with) % mod;
      else
        answer = ((int64_t)answer * num_without) % mod;
    }
  }
  std::cout << answer;
}
