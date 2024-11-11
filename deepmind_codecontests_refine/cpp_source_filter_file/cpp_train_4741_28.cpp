#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0;
  cin >> n;
  sum = 2 * n / 3;
  if (n % 3 > 0) {
    sum++;
  }
  cout << sum;
  return 0;
}
