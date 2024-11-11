#include <bits/stdc++.h>
using namespace std;
long long coeff[200500];
int pof2[200500];
int sgn(long long n) {
  if (n < 0) return -1;
  if (n > 0) return 1;
  return 0;
}
long long flog2(long long n) {
  long long num = 1;
  int ans = 0;
  while (num <= n / 2) {
    num *= 2;
    ++ans;
  }
  return ans;
}
int main() {
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i <= n; ++i) {
    cin >> coeff[i];
    long long t = ((coeff[i]) < 0 ? (-(coeff[i])) : (coeff[i]));
    while (t != 0) {
      int k = flog2(t);
      pof2[k + i] += sgn(coeff[i]);
      t -= (1 << k);
    }
  }
  int max_pow = 0;
  for (int i = 0; i < 200500; ++i) {
    if (pof2[i] == 0) continue;
    pof2[i + 1] += pof2[i] / 2;
    pof2[i] %= 2;
    if (pof2[i] != 0) max_pow = i;
  }
  int latest1 = max_pow;
  int sign = sgn(pof2[max_pow]);
  int min_pow = 0;
  for (int i = max_pow; i >= 0; --i) {
    if (pof2[i] == 0) continue;
    pof2[i] *= sign;
    if (pof2[i] == 1)
      latest1 = i;
    else {
      if (latest1 == max_pow) --max_pow;
      pof2[i] = 1;
      pof2[latest1] = 0;
      for (int j = i + 1; j < latest1; ++j) pof2[j] = 1;
      latest1 = i;
    }
    if (pof2[i] != 0) min_pow = i;
  }
  if (max_pow - min_pow >= 61) {
    cout << "0\n";
    return 0;
  }
  long long sum = 0;
  for (int i = min_pow; i <= max_pow; ++i) {
    sum += pof2[i] * (1LL << (i - min_pow));
  }
  int ans = 0;
  long long bound = (1LL << 61);
  for (int i = min_pow; i >= 0; --i) {
    if (i == n && sign * sum == coeff[i])
      ans += 0;
    else if (i <= n &&
             ((coeff[i] - sign * sum) < 0 ? (-(coeff[i] - sign * sum))
                                          : (coeff[i] - sign * sum)) <= k) {
      ++ans;
    }
    if (sum * 2 > bound) break;
    sum *= 2;
  }
  cout << ans << endl;
}
