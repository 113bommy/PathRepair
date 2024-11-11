#include <bits/stdc++.h>
using namespace std;
const long long modn = 998244353;
const int maxn = 100005, maxbit = 30;
int bitCount[maxbit] = {0}, BCP[maxbit] = {0};
long long A[maxn], dPower[maxbit];
inline int getbit(long long x) {
  int r = 0;
  while (x) {
    ++r;
    x /= 10;
  }
  return max(1, r);
}
int main() {
  dPower[0] = 1;
  for (int i = 1; i < maxbit; ++i) {
    dPower[i] = dPower[i - 1] * 10ll % modn;
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    bitCount[getbit(A[i])] += 1;
  }
  for (int i = 1; i < maxbit; ++i) {
    BCP[i] = BCP[i - 1] + bitCount[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int b = getbit(A[i]);
    long long HB = A[i], LB = 0;
    for (int j = 1; j <= b; ++j) {
      LB += (HB % 10) * 11 * dPower[(j - 1) * 2];
      HB /= 10;
      long long comboSum = HB * 2 * dPower[j * 2] + LB;
      if (j < b) {
        (ans += comboSum * bitCount[j]) %= modn;
      } else {
        (ans += comboSum * (BCP[maxbit - 1] - BCP[j - 1])) %= modn;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
