#include <bits/stdc++.h>
const int MX = 1e5 + 23;
int read() {
  char k = getchar();
  int x = 0;
  while (k < '0' || k > '9') k = getchar();
  while (k >= '0' && k <= '9') x = x * 10 + k - '0', k = getchar();
  return x;
}
long long qpow(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p, b >>= 1;
  }
  return ans;
}
int m, n, a[MX], A, B;
bool solve() {
  std::set<int> S;
  for (int i = 1; i <= n; ++i) {
    S.insert(a[i]);
  }
  std::random_shuffle(a + 1, a + 1 + n);
  if (n == 1) {
    A = a[1], B = 1;
    return 1;
  }
  int d = (a[2] - a[1] + m) % m;
  int spl = 0;
  for (int i = 1; i <= n; ++i) {
    if (S.find(a[i]) != S.end()) {
      ++spl;
      for (int j = (a[i] + d) % m;; j = (j + d) % m) {
        if (S.find(j) != S.end()) {
          S.erase(j);
        } else
          break;
      }
      for (int j = a[i];; j = (j - d + m) % m) {
        if (S.find(j) != S.end()) {
          S.erase(j);
        } else
          break;
      }
    }
  }
  d = 1LL * d * qpow(spl, m - 2, m) % m;
  for (int i = 1; i <= n; ++i) {
    S.insert(a[i]);
  }
  for (int i = (a[1] + d) % m;; i = (i + d) % m) {
    if (S.find(i) != S.end()) {
      S.erase(i);
    } else
      break;
  }
  int good = 0;
  for (int i = a[1];; i = (i - d + m) % m) {
    if (S.find(i) != S.end()) {
      good = i;
      S.erase(i);
    } else
      break;
  }
  if (S.empty()) {
    A = good, B = d;
    return 1;
  } else
    return 0;
}
int main() {
  m = read(), n = read();
  if (n == m) return puts("0 1"), 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  if (n * 2 > m) {
    std::set<int> S;
    for (int i = 1; i <= n; ++i) S.insert(a[i]);
    n = 0;
    for (int i = 0; i < m; ++i) {
      if (S.find(i) == S.end()) {
        a[++n] = i;
      }
    }
    if (solve()) {
      printf("%d %d\n", (A - B + m) % m, (m - B) % m);
    } else
      puts("-1");
  } else {
    if (solve()) {
      printf("%d %d\n", A, B);
    } else
      puts("-1");
  }
  return 0;
}
