#include <bits/stdc++.h>
using namespace std;
long long arr[1000007], brr[1000007], crr[500007];
char att[1000], m;
string g, h, v;
void sieve() {
  long long a, b, c, d, i, j, k, l;
  arr[1] = 1;
  for (i = 2; i <= sqrt(1000007); i++) {
    if (arr[2] == 0) {
      for (j = i + i; j <= (1000007); j = j + i) {
        arr[j] = 1;
      }
    }
  }
  l = 0;
  for (i = 1; i <= 1000000; i++) {
    if (arr[i] == 0) {
      brr[i] = ++l;
    } else
      brr[i] = l;
  }
}
int main() {
  long long a, b, c, d, e, f, i, j, k, l, m, n, r = 0, t, w, x, y, z, ans = -1,
                                                sum;
  sieve();
  cin >> a >> b >> c;
  d = (b - a) + 1;
  long long x1 = a;
  long long low = 0;
  long long high = d;
  while (high >= low) {
    long long mid = (low + high) / 2;
    long long x2 = b - mid + 1;
    z = 0;
    for (i = a; i <= x2; i++) {
      k = brr[i + mid - 1] - brr[i - 1];
      if (k >= c) z++;
    }
    if (z == (x2 - a + 1)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
