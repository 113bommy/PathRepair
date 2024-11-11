#include <bits/stdc++.h>
using namespace std;
long long int pwr(long long int a, long long int n, long long int m) {
  long long int p = 1;
  while (n > 0) {
    if (n % 2 == 1) p = (p * a) % m;
    a = (a * a) % m;
    n = n / 2;
  }
  return p;
}
char str[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, a, b, k, s = 0, i;
  cin >> n >> a >> b >> k;
  long long int f =
      (((pwr(b, n + 1, (long long int)(1e9 + 9)) -
         pwr(a, n + 1, (long long int)(1e9 + 9)) + (long long int)(1e9 + 9)) %
        (long long int)(1e9 + 9)) *
       pwr(a, k, (long long int)(1e9 + 9))) %
      (long long int)(1e9 + 9);
  long long int g =
      (((pwr(b, k, (long long int)(1e9 + 9)) -
         pwr(a, k, (long long int)(1e9 + 9)) + (long long int)(1e9 + 9)) %
        (long long int)(1e9 + 9)) *
       pwr(a, n + 1, (long long int)(1e9 + 9))) %
      (long long int)(1e9 + 9);
  long long int r =
      ((f * pwr(g, (long long int)(1e9 + 9) - 2, (long long int)(1e9 + 9))) %
           (long long int)(1e9 + 9) +
       (long long int)(1e9 + 9)) %
      (long long int)(1e9 + 9);
  if (a == b) r = (n + 1) / k;
  cin >> str;
  for (i = 0; i < k; i++) {
    if (str[i] == '+')
      s = (s +
           (pwr(a, n - i, (long long int)(1e9 + 9)) *
            pwr(b, i, (long long int)(1e9 + 9))) %
               (long long int)(1e9 + 9) +
           (long long int)(1e9 + 9)) %
          (long long int)(1e9 + 9);
    else
      s = (s -
           (pwr(a, n - i, (long long int)(1e9 + 9)) *
            pwr(b, i, (long long int)(1e9 + 9))) %
               (long long int)(1e9 + 9) +
           (long long int)(1e9 + 9)) %
          (long long int)(1e9 + 9);
  }
  cout << ((s * r) % (long long int)(1e9 + 9) + (long long int)(1e9 + 9)) %
              (long long int)(1e9 + 9)
       << endl;
  return 0;
}
