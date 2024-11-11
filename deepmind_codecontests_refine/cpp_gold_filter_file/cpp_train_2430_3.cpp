#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline bool umin(T1 &a, const T2 &b) {
  return a > b ? a = b, true : false;
}
template <typename T1, typename T2>
inline bool umax(T1 &a, const T2 &b) {
  return a < b ? a = b, true : false;
}
inline int read() {
  int x = 0, ng = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ng = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return ng ? -x : x;
}
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int seed = 20040305;
string b, n;
long long c, a;
long long res;
long long pw(long long p, long long k) {
  long long q = 1;
  while (k) {
    if (k & 1) q = q * p % c;
    k >>= 1;
    p = p * p % c;
  }
  return q;
}
long long get(string s) {
  long long base = a;
  long long ret = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    ret = ret * pw(base, s[i] - '0') % c;
    base = pw(base, 10);
  }
  return ret;
}
int main() {
  cin >> b >> n >> c;
  for (int i = 0; i < b.size(); i++) {
    a = (a * 10 + b[i] - '0') % c;
  }
  for (int i = n.size() - 1; i >= 0; i--) {
    if (n[i] != '0') {
      n[i] = n[i] - 1;
      break;
    }
    n[i] = '9';
  }
  res = get(n);
  res = res * (a - 1 + c * 5) % c;
  if (res == 0) res = c;
  printf("%lld", res);
}
