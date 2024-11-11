#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i;
  cin >> n >> k;
  int max = -999999999;
  for ((i) = 0; (i) < (int)(n); (i)++) {
    int f, t;
    cin >> f >> t;
    int joy = (t > k) ? (f - (t - k)) : f;
    max = (max > joy) ? max : joy;
  }
  cout << max;
  return 0;
};
