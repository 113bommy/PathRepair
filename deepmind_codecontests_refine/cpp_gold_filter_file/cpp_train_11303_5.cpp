#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
const int MAXN = 61;
long long binPow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2) return binPow(a, n - 1) * a;
  long long b = binPow(a, n >> 1);
  return b * b;
}
long long getNext(char* s, long long& lastPos, long long n, long long pow) {
  long long ret = 0;
  long long p = 1;
  long long lastNotZero = 0;
  int i = lastPos;
  int lastNotZeroPos = lastPos;
  while (i >= 0) {
    if (p >= n || ret + (s[i] - '0') * p >= n) {
      ret = lastNotZero;
      break;
    }
    ret += p * (s[i] - '0');
    if (s[i] != '0') {
      lastNotZeroPos = i;
      lastNotZero = ret;
    }
    p *= 10;
    --i;
  }
  lastPos = lastNotZeroPos - 1;
  return binPow(n, pow) * ret;
}
long long n;
char k[MAXN];
long long res;
int main() {
  scanf("%I64d\n", &n);
  scanf("%s", k);
  long long lastPos = strlen(k) - 1;
  long long res = 0;
  long long p = 0;
  while (lastPos >= 0) {
    res += getNext(k, lastPos, n, p++);
  }
  printf("%I64d", res);
  return 0;
}
