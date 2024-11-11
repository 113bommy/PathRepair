#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  if (n % 3 != 0) {
    cout << n % 3 << " " << n % 3 << " " << n - 2 * (n % 3);
  } else {
    cout << 1 << " " << 1 << " " << n - 2;
  }
  return 0;
}
