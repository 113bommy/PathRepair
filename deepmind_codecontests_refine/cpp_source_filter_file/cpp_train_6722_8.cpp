#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a, b, as, bs, tmp(n + 1);
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      a = i;
      b = n / i;
      if (abs(a - b) < tmp) {
        as = a;
        bs = b;
        tmp = abs(a - b);
      }
    }
  }
  cout << as << " " << bs << endl;
}
