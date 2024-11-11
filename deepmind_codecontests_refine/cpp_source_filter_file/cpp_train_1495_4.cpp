#include <bits/stdc++.h>
using namespace std;
long long dem(long long u);
long long l, r, lt[100], a[100];
long long t[18] = {1,  2,  3,  4,  5,  6,  7,  8,  9,
                   11, 22, 33, 44, 55, 66, 77, 88, 99};
int main() {
  ios::sync_with_stdio(0);
  lt[0] = 1;
  for (int i = (1), _b = (59); i <= _b; i++) lt[i] = lt[i - 1] * 10;
  cin >> l >> r;
  cout << dem(r) - dem(l - 1);
  return 0;
}
long long dem(long long u) {
  long long p = u;
  long long res = 0;
  long long cnt = 0;
  long long n = 0;
  long long q = 0;
  while (p) {
    cnt++;
    a[++n] = p % 10;
    p /= 10;
  }
  if (cnt <= 2) {
    for (int i = (0), _b = (17); i <= _b; i++)
      if (u < t[i]) return i;
    return 18;
  }
  for (int i = (1), _b = (cnt - 1); i <= _b; i++)
    if (i <= 2)
      res += 9;
    else
      res += 9 * lt[i - 2];
  for (int i = (1), _b = (a[n]); i <= _b; i++) res += lt[cnt - 2];
  for (int i = (n - 1), _b = (2); i >= _b; i--) q = q * 10 + a[i];
  if (a[1] >= a[n])
    res += q + 1;
  else
    res += q;
  return res;
}
