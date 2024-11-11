#include <bits/stdc++.h>
using namespace std;
long long int getSum(long long int n) {
  long long int sum;
  for (sum = 0; n > 0; sum += n % 10, n /= 10)
    ;
  return sum;
}
int32_t main() {
  long long int n;
  cin >> n;
  long long int start = getSum(n);
  if (start % 4 == 0) {
    cout << n << endl;
    return 0;
  }
  for (long long int i = n + 1; i < n + 1000; ++i) {
    if (getSum(i) % 4 == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
