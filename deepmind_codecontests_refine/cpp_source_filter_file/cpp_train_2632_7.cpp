#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long mn = 10000000000000000;
  long long mx = 0;
  for (long long b = 3; b <= ceil(pow(n, (double)1 / 3)) + 2; b++) {
    if (n % (b - 2) != 0) continue;
    for (long long c = b; c <= ceil(pow(n / (b - 2), 0.5)) + 2; c++) {
      if ((n / (b - 2)) % (c - 2) != 0)
        continue;
      else {
        long long a = n / (b - 2) / (c - 2) + 1;
        if (a < c) continue;
        if (a * b * c > mx) mx = a * b * c;
      }
    }
  }
  for (long long a = 2; a <= ceil(pow(n, (double)1 / 3)) + 1; a++) {
    if (n % (a - 1) != 0) continue;
    for (long long b = a; b <= ceil(pow(n / (a - 1), 0.5)) + 2; b++) {
      if (b == 2) continue;
      if ((n / (a - 1)) % (b - 2) != 0)
        continue;
      else {
        long long c = n / (b - 2) / (a - 1) + 2;
        if (c < b) continue;
        if (a * b * c < mn) mn = a * b * c;
      }
    }
  }
  cout << mn - n << " " << mx - n << endl;
  return 0;
}
