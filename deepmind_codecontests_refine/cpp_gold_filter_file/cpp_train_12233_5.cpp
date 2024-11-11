#include <bits/stdc++.h>
using namespace std;
void solve(long long n) {
  long long i = 2, prod = 1, ot = n;
  for (; i * i <= n; i++) {
    if (n % i == 0) {
      prod *= i;
    }
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) prod *= n;
  cout << prod << endl;
}
int main() {
  long long n;
  cin >> n;
  solve(n);
  return 0;
}
