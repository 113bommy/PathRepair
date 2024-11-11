#include <bits/stdc++.h>
using namespace std;
const int N = 100008;
long long n, a[N];
long long absx(long long x) {
  if (x < 0) x = -x;
  return x;
}
int main(void) {
  std::ios::sync_with_stdio(false);
  long long i, j, k, an1, an2;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  an1 = an2 = 0;
  j = 0;
  k = 1;
  for (i = 1; i < n; i++) {
    if (j < 0) j = 0;
    j += k * absx(a[i] - a[i + 1]);
    if (j > an1) an2 = j;
    k *= -1;
  }
  j = 0;
  k = 1;
  for (i = 2; i < n; i++) {
    if (j < 0) j = 0;
    j += k * absx(a[i] - a[i + 1]);
    if (j > an2) an2 = j;
    k *= -1;
  }
  if (an2 > an1) an1 = an2;
  cout << an1;
  return 0;
}
