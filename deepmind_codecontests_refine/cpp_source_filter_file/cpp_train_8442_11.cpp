#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  if ((a -= b) < 0) a += mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
inline int power(int a, int b) {
  int out = 1;
  while (b) {
    if (b & 1) out = mult(out, a);
    a = mult(a, a);
    b >>= 1;
  }
  return out;
}
char s1[100010], s2[100010];
int a, b, c, d, fac[100010], ifac[100010], one, otot, zero, ztot, n;
inline int C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return mult(fac[a], mult(ifac[b], ifac[a - b]));
}
inline int solve(char* s) {
  int len = strlen(s);
  if (len < n) return 0;
  if (len > n)
    return mult(C(otot - 1, one - 1),
                !ztot && !zero ? 1 : C(ztot - 1, zero - 1));
  int cnt1 = 0, cnt0 = 0, lst = 0, siz0 = 0, siz1 = 0, ans = 0;
  for (int i = 0; i < len; i++) {
    if (i && s[i] == '1') {
      siz0++;
      if (lst) cnt0++;
      ans = add(ans, mult(otot == siz1 && one == cnt1
                              ? 1
                              : C(otot - siz1 - 1, one - cnt1 - 1),
                          C(ztot - siz0, zero - cnt0)));
      --siz0;
      if (lst) --cnt0;
    }
    if (s[i] == '1') {
      ++siz1;
      if (!lst) {
        ++cnt1;
      }
      lst = 1;
    } else {
      ++siz0;
      if (lst) cnt0++;
      lst = 0;
    }
  }
  return ans;
}
int main() {
  scanf("%s%s", s1, s2);
  int l2 = strlen(s2);
  for (int i = l2 - 1; i >= 0; i--) {
    if (s2[i] == '0') {
      s2[i] = '1';
      break;
    } else {
      s2[i] = '0';
      if (!i) {
        for (int j = l2 - 1; j >= 0; j--) s2[j + 1] = s2[j];
        s2[0] = '1';
      }
    }
  }
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (c - b < 0 || c - b > 1) {
    puts("0");
    return 0;
  }
  one = c + (b == c), zero = b + (b != c), otot = one + a, ztot = zero + d,
  n = otot + ztot;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mult(fac[i - 1], i);
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = mult(ifac[i + 1], i + 1);
  printf("%d\n", dec(solve(s2), solve(s1)));
  return 0;
}
