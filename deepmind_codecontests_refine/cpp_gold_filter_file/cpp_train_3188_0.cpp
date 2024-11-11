#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int m = n;
  long long int sum = 0, sum2 = 0, ans = 0;
  while (n % 5 == 0) {
    n /= 5;
    sum++;
  }
  while (n % 2 == 0) {
    n /= 2;
    sum2++;
  }
  if (sum <= k) {
    long long int x = k - sum;
    sum = k - sum2;
    if (sum > 0) {
      long long int p = powl(2, sum) * powl(5, x);
      ans = m * p;
    } else {
      long long int p = powl(5, x);
      ans = m * p;
    }
  } else {
    k -= sum2;
    if (k > 0)
      ans = m * powl(2, k);
    else
      ans = m;
  }
  cout << ans;
}
