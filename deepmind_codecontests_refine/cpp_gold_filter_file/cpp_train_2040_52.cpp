#include <bits/stdc++.h>
const bool debug = false;
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
void buginfo(const char* f, ...) {
  if (!debug) return;
  va_list al;
  va_start(al, f);
  vprintf(f, al);
  va_end(al);
}
int n;
int main() {
  scanf("%d", &n);
  return 0 * printf("%d\n", (n + 1) / 2 - 1);
}
