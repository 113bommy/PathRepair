#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  long long t, e, s, k, l, a, sum = 0;
  long long ar[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
  long long op[11] = {1,         10,         100,        1000,
                      10000,     100000,     1000000,    10000000,
                      100000000, 1000000000, 10000000000};
  cin >> t;
  s = t;
  k = 0;
  while (s != 0) {
    s = s / 10;
    k++;
  }
  sum = sum + 2 * (pow(2, k - 1) - 1);
  e = k;
  for (int i = 0; i < e; i++) {
    l = op[k - 1];
    a = t / l;
    if (a != 4) {
      sum = sum + ar[k - 1];
    }
    t = t - a * l;
    k--;
  }
  cout << sum + 1;
}
