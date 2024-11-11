#include <bits/stdc++.h>
using namespace std;
int main() {
  long long sum = 0, exp;
  long n, i, x;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> x;
    sum += x;
  }
  exp = (1LL * n * (n + 1)) / 2;
  cout << exp - sum;
  return 0;
}
