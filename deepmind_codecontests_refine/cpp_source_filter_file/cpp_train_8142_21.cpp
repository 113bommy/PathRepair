#include <bits/stdc++.h>
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; c > '9' || c < '0'; c = getchar()) {
    if (c == '-') f = -1;
  }
  for (; c >= '0' && c <= '9'; c = getchar()) {
    x = x * 10 + c - '0';
  }
  return x * f;
}
const long long mod = 1e9 + 7;
long long base[200005], odd[200005], top;
long long hash[200005][2], a[200005];
char s[200005];
inline std::pair<long long, long long> get_hash(long long l, long long r) {
  long long L = std::lower_bound(a + 1, a + top + 1, l) - a;
  if (L > top || a[L] > r) return std::make_pair(0, 0);
  long long R = std::upper_bound(a + 1, a + top + 1, r) - a - 1;
  if (l & 1)
    return std::make_pair(
        (hash[R][0] - hash[L - 1][0] * base[R - L + 1] % mod + mod) % mod,
        R - L + 1);
  else
    return std::make_pair(
        (hash[R][1] - hash[L - 1][1] * base[R - L + 1] % mod + mod) % mod,
        R - L + 1);
}
inline void work() {
  long long n = read();
  base[0] = 1;
  scanf("%s", s + 1);
  for (long long i = 1; i <= n; i++) {
    if (s[i] == '0') {
      a[++top] = i;
      if (i & 1) odd[i] = 1;
    }
    base[i] = 31ll * base[i - 1] % mod;
  }
  for (long long i = 1; i <= top; i++) {
    if (odd[i]) {
      hash[i][0] = (31ll * hash[i - 1][0] + 1) % mod;
      hash[i][1] = (31ll * hash[i - 1][1] + 2) % mod;
    } else {
      hash[i][0] = (31ll * hash[i - 1][0] + 2) % mod;
      hash[i][1] = (31ll * hash[i - 1][1] + 1) % mod;
    }
  }
  for (long long q = read(); q; q--) {
    long long l1 = read(), l2 = read(), len = read();
    auto hash1 = get_hash(l1, l1 + len - 1);
    auto hash2 = get_hash(l2, l2 + len - 1);
    if (hash1 == hash2)
      puts("Yes");
    else
      puts("No");
  }
}
int32_t main() {
  work();
  return 0;
}
