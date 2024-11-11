#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n + 3; i *= 3) {
    if (n % i) {
      cout << (n / i) + 1 << endl;
      break;
    }
  }
}
