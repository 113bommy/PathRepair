#include <bits/stdc++.h>
using namespace std;
int main() {
  double k, n, s, p;
  int sum2, sum1;
  cin >> k >> n >> s >> p;
  sum1 = (n + (s - 1)) / s * k;
  sum2 = (sum1 + (p - 1)) / p;
  cout << sum2 << endl;
  return 0;
}
