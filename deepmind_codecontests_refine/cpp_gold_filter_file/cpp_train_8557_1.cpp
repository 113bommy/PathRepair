#include <bits/stdc++.h>
using namespace std;
long long L, R, mid;
long long n, k, Ans1, Ans2;
bool Check(long long x) {
  long long Ans = 0;
  if (x % 2 == 0) {
    long long tmp = 1;
    while (x + (1LL << tmp) - 1 <= n) {
      Ans += (1LL << tmp);
      tmp++;
      x <<= 1;
    }
    if (n >= x) Ans += n - x + 1;
  } else {
    long long tmp = 0;
    while (x + (1LL << tmp) - 1 <= n) {
      Ans += (1LL << tmp);
      tmp++;
      x <<= 1;
    }
    if (n >= x) Ans += n - x + 1;
  }
  return Ans >= k;
}
int main() {
  cin >> n >> k;
  L = 0, R = (n + 1) / 2 + 1;
  while (R - L > 1) {
    mid = (L + R) >> 1;
    if (Check(mid * 2 - 1))
      L = mid;
    else
      R = mid;
  }
  Ans1 = L * 2 - 1;
  L = 0, R = n / 2 + 1;
  while (R - L > 1) {
    mid = (L + R) >> 1;
    if (Check(mid * 2))
      L = mid;
    else
      R = mid;
  }
  Ans2 = L * 2;
  cout << max(Ans1, Ans2) << endl;
  return 0;
}
