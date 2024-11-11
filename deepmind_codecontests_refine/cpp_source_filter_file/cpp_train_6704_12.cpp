#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1e8;
long long exp(long long base, long long exponente) {
  long long res = 1;
  while (exponente > 0) {
    if ((exponente & 1) != 0) res *= base;
    base *= base;
    exponente >>= 1;
  }
  return res;
}
long long findAlpha(long long n) {
  long long res = 0LL;
  long long powTwo = 1LL;
  while (powTwo <= n + 1LL) {
    powTwo *= 2LL;
    res++;
  }
  res--;
  return res;
}
long long ge(long long alpha, long long n, long long midI) {
  if (midI >= 1415000000LL)
    return 0;
  else {
    long long combi = (midI * (midI - 3LL)) / 2LL;
    long long powTwoI = midI;
    long long pow = 0LL;
    while (powTwoI <= 1000000000000000001LL && pow < alpha) {
      powTwoI *= 2LL;
      pow++;
    }
    if (pow < alpha) {
      return 0LL;
    } else {
      long long f = combi + powTwoI;
      if (n < f)
        return 0LL;
      else if (n == f)
        return 1LL;
      else
        return 2LL;
    }
  }
}
long long findAlpha0I(long long n) {
  long long res = (((long long)sqrt(8LL * n + 1LL)) + 1LL) / 2LL - 2LL;
  while ((res * (res - 1LL)) / 2LL < n) res++;
  if ((res * (res - 1LL)) / 2LL == n)
    return res;
  else
    return -1LL;
}
int main() {
  long long n;
  cin >> n;
  if (n == 1LL) {
    cout << -1 << endl;
    return 0;
  }
  long long maxAlpha = findAlpha(n);
  set<long long> res;
  long long alpha0I = findAlpha0I(n);
  if (alpha0I != -1LL && alpha0I % 2LL == 1LL) {
    res.insert(alpha0I);
  }
  for (long long alpha = 1LL; alpha <= maxAlpha; alpha++) {
    long long loI = 1LL;
    long long hiI = n;
    while (loI < hiI - 1LL) {
      long long midI = (loI + hiI) / 2LL;
      if (ge(alpha, n, midI))
        loI = midI;
      else
        hiI = midI;
    }
    if (ge(alpha, n, loI) == 1LL && loI % 2LL == 1LL)
      res.insert(exp(2LL, alpha) * loI);
  }
  if (res.size() == 0)
    cout << -1 << endl;
  else {
    set<long long>::iterator it;
    for (it = res.begin(); it != res.end(); it++) cout << *it << endl;
  }
  return 0;
}
