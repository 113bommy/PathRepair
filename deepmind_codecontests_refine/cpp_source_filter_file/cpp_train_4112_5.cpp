#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long n;
  float s;
  cin >> n;
  t = log10(n);
  s = ((((9 * t - 1) * pow(10, t)) + 1) / 9) + (n - pow(10, t) + 1) * (t + 1);
  cout << s;
  return 0;
}
