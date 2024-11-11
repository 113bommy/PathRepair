#include <bits/stdc++.h>
using namespace std;
bool go(long long x) { return sqrt(x * 1.0) == (int)sqrt(x * 1.0); }
bool can(long long n) {
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i > 1 && go(i)) return 0;
      if (go(n / i)) return 0;
    }
  }
  return 1;
}
int main() {
  long long n;
  cin >> n;
  long long mx = 1;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i > 1 && can(i)) mx = max(i, mx);
      if (can(n / i)) mx = max(n / i, mx);
    }
  }
  cout << mx << endl;
  return 0;
}
