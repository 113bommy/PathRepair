#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, i, j, maximum = 0, maxbr = 0, brojevi = 0;
  long long sum = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m;
    for (j = 0; j < m; j++) {
      cin >> a;
      if (a > maxbr) maxbr = a;
    }
    if (maxbr > maximum) {
      sum += brojevi * (maxbr - maximum);
      maximum = maxbr;
    } else {
      if (maxbr < maximum) {
        sum += m * (maximum - maxbr);
      }
    }
    brojevi += m;
    maxbr = 0;
  }
  cout << sum;
  return 0;
}
