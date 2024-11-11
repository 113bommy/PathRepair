#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long an = 1;
  for (long long i = 2; i <= sqrt(n); i++) {
    long long c = 0;
    while (n % i == 0) {
      c++;
      n /= i;
    }
    if (c) an *= i;
  }
  if (n > 2) an *= n;
  cout << an << endl;
  return 0;
}
