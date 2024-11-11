#include <bits/stdc++.h>
using namespace std;
inline void __CIN__() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
char buf;
inline int xint() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  int x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline long long xll() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  long long x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline string xstring() {
  while (buf = getchar(), buf == ' ' || buf == '\n')
    ;
  string x = "";
  for (x += buf; buf = getchar(), buf != ' ' && buf != '\n'; x += buf)
    ;
  return x;
}
const long long MOD = 1000000009;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
int main() {
  int l, data[105], i, j, k, n;
  string s;
  cin >> n;
  cin >> s;
  for (i = 0; i < n - 5; ++i)
    if (s[i] = '*') {
      for (j = 1;; ++j) {
        if (4 * j + i >= n) break;
        if (s[i + j] == '*' && s[i + 2 * j] == '*' && s[i + 3 * j] == '*' &&
            s[i + 4 * j] == '*') {
          cout << "yes" << endl;
          exit(0);
        }
      }
    }
  cout << "no" << endl;
  return 0;
}
