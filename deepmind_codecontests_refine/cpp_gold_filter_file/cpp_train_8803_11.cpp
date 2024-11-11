#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (1); i <= (b); i++) {
    multiply *= a;
  }
  return multiply;
}
inline long long ABS(long long a) { return (a >= 0) ? a : -a; }
int n;
string s, s1;
long long dp[5007][5007], ultacum[5007][26];
int main() {
  cin >> n >> s;
  s1.push_back(s[0]);
  if (s.size() > 1) {
    for (int i = (1); i <= (s.size() - 1); i++) {
      if (s[i] != s1[s1.size() - 1]) s1.push_back(s[i]);
    }
  }
  n--;
  int m = s1.size() - 1;
  for (int i = (0); i <= (m); i++) dp[n][i] = 1;
  memset(ultacum, 0, sizeof(ultacum));
  ultacum[m][s1[m] - 'a'] = 1;
  for (int i = (m - 1); i >= (0); i--) {
    for (int j = (0); j <= (25); j++) ultacum[i][j] = ultacum[i + 1][j];
    ultacum[i][s1[i] - 'a'] = 1;
  }
  for (int i = (n - 1); i >= (0); i--) {
    for (int j = (0); j <= (m); j++) {
      dp[i][j] = 0;
      for (int k = (0); k <= (25); k++) dp[i][j] += ultacum[j][k];
      dp[i][j] %= 1000000007LL;
    }
    memset(ultacum, 0, sizeof(ultacum));
    ultacum[m][s1[m] - 'a'] = dp[i][m];
    for (int j = (m - 1); j >= (0); j--) {
      for (int k = (0); k <= (25); k++) ultacum[j][k] = ultacum[j + 1][k];
      ultacum[j][s1[j] - 'a'] = dp[i][j];
    }
  }
  long long ans = 0;
  for (int i = (0); i <= (25); i++) ans += ultacum[0][i];
  ans %= 1000000007LL;
  cout << ans << '\n';
  return 0;
}
