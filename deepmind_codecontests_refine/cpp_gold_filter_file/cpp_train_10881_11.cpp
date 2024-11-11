#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long k = n;
  long long c = n / 2 + n / 3 + n / 5 + n / 7;
  long long d = n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35;
  long long e = n / 30 + n / 42 + n / 70 + n / 105;
  long long f = n / 210;
  long long m = c - d + e - f;
  cout << k - m;
  return 0;
}
