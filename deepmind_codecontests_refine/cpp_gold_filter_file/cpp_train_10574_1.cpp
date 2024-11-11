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
const int maxn = 110;
int n, kr, kb, ky, kg;
char s[maxn], t[4];
bool check() {
  for (int i = 0; i < 4; ++i) {
    for (int j = i; j < n; j += 4) {
      if (s[j] == '!') continue;
      if (s[j] != t[i]) return false;
    }
  }
  return true;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  t[0] = 'R', t[1] = 'B', t[2] = 'Y', t[3] = 'G';
  int cnt = 24;
  while (cnt--) {
    if (check()) break;
    next_permutation(t, t + 4);
  }
  int d = n / 4, r = n % 4;
  kr = kb = ky = kg = d;
  for (int i = 0; i < r; ++i) {
    if (t[i] == 'R') ++kr;
    if (t[i] == 'B') ++kb;
    if (t[i] == 'Y') ++ky;
    if (t[i] == 'G') ++kg;
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') --kr;
    if (s[i] == 'B') --kb;
    if (s[i] == 'Y') --ky;
    if (s[i] == 'G') --kg;
  }
  printf("%d %d %d %d\n", kr, kb, ky, kg);
  return 0;
}
