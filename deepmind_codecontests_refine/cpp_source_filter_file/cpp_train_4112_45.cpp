#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, sum = 0;
  long long d[10];
  d[1] = 9, d[2] = 90, d[3] = 900, d[4] = 9000, d[5] = 90000, d[6] = 900000,
  d[7] = 9000000, d[8] = 90000000, d[9] = 900000000;
  cin >> n;
  for (i = 1; i < 10 && n > 0; i++) {
    sum = sum + min(n, d[i]) * i;
    n = n - min(n, d[i]);
  }
  cout << sum;
}
