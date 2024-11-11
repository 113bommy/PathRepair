#include <bits/stdc++.h>
using namespace std;
long long mInv[41];
long long fact[41];
long long factInv[41], M;
map<string, long> mymap;
long long li[100005], ri[100005], range[100005], primeNum[100005];
long bulbs[110];
long long getmoduloInv(long long n) {
  if (n == 1) return 1;
  if (mInv[n] > 0) return mInv[n];
  long long m = (-1 * 1000000007) / n;
  m += 1000000007;
  m *= getmoduloInv(1000000007 % n);
  mInv[n] = (m % 1000000007);
  return mInv[n];
}
long long getMul(long long val, long long pow) {
  if (pow == 1) return val;
  long long tempVal = getMul(val, pow / 2);
  tempVal = tempVal * tempVal;
  tempVal %= 1000000007;
  if (pow % 2 == 1) {
    tempVal *= val;
    tempVal %= 1000000007;
  }
  return tempVal;
}
long torightBottom[3010], toLeftBottom[3010];
int main(void) {
  long long test_cases = 1;
  cout << setprecision(15) << fixed;
  long burstPos = -1;
  long long n, minOdd = 999999999999, num, p;
  cin >> n >> p;
  memset(toLeftBottom, 0, sizeof(toLeftBottom));
  memset(torightBottom, 0, sizeof(torightBottom));
  long long lt, rt, x, y;
  cin >> li[0] >> ri[0];
  range[0] = 1 + ri[0] - li[0];
  primeNum[0] = (range[0] + p - (1 + ri[0] % p)) / p;
  double ans = 0;
  for (long i = 1; i < n; i++) {
    cin >> li[i] >> ri[i];
    range[i] = 1 + ri[i] - li[i];
    primeNum[i] = (range[i] + p - (1 + ri[i] % p)) / p;
    double expectedMatch =
        ((primeNum[i] * range[i - 1]) + (primeNum[i - 1] * range[i]) -
         (primeNum[i] * primeNum[i - 1]));
    expectedMatch /= (double)(range[i] * range[i - 1]);
    ans += expectedMatch;
  }
  ans += ((double)((primeNum[0] * range[n - 1]) + (primeNum[n - 1] * range[0]) -
                   (primeNum[0] * primeNum[n - 1]))) /
         ((double)(range[0] * range[n - 1]));
  ans *= (double)2000;
  cout << ans << endl;
  return 0;
}
