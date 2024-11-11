#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T mod_v(T num) {
  if (num >= 0)
    return num % 1000000007;
  else
    return (num % 1000000007 + 1000000007) % 1000000007;
}
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <class T>
T fast_pow(T n, T p) {
  if (p == 0) return 1;
  if (p % 2) {
    T g = mod_v(mod_v(n) * mod_v(fast_pow(n, p - 1)));
    return g;
  } else {
    T g = fast_pow(n, p / 2);
    g = mod_v(mod_v(g) * mod_v(g));
    return g;
  }
}
template <class T>
inline T modInverse(T n) {
  return fast_pow(n, 1000000007 - 2);
}
template <class T>
inline void debug(string S1, T S2, string S3) {
  cout << S1 << S2 << S3;
}
template <class T>
inline T in() {
  register char c = 0;
  register T num = 0;
  bool n = false;
  while (c < 33) c = getchar();
  while (c > 33) {
    if (c == '-')
      n = true;
    else
      num = num * 10 + c - '0';
    c = getchar();
  }
  return n ? -num : num;
}
long long ara[1008];
int n, m, k;
int dp[1008][108][2];
int re(int p, int v, int s) {
  if (p == 1) {
    int c = 0;
    for (int i = 1; i <= 9; i++) {
      long long x = (long long)i * ara[p] + (long long)v;
      if (x % (long long)k == 0 || s) c++;
    }
    return c;
  }
  if (dp[p][v][s] != -1) return dp[p][v][s];
  dp[p][v][s] = 0;
  if (s) {
    for (int i = 0; i <= 9; i++) {
      long long x = (long long)i * ara[p] + (long long)v;
      dp[p][v][s] =
          (dp[p][v][s] % m + re(p - 1, (int)(x % (long long)k), 1) % m) % m;
    }
  } else {
    for (int i = 0; i <= 9; i++) {
      long long x = (long long)i * ara[p] + (long long)v;
      if (x % (long long)k == 0 && i > 0)
        dp[p][v][s] =
            (dp[p][v][s] % m + re(p - 1, (int)(x % (long long)k), 1) % m) % m;
      else
        dp[p][v][s] =
            (dp[p][v][s] % m + re(p - 1, (int)(x % (long long)k), 0) % m) % m;
    }
  }
  return dp[p][v][s];
}
int main() {
  n = in<int>();
  k = in<int>();
  m = in<int>();
  int a = n, b = k, c = m;
  ara[n] = 1;
  for (int i = n - 1; i > 0; i--) {
    ara[i] = (ara[i + 1] * 10) % (long long)k;
  }
  memset(dp, -1, sizeof(dp));
  ;
  printf("%d\n", re(n, 0, 0) % m);
  return 0;
}
