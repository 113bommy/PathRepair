#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i;
  while (cin >> n) {
    long long sum = 1;
    for (i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        sum *= i;
        while (n % i == 0) n /= i;
      }
    }
    cout << sum * n;
  }
  return 0;
}
