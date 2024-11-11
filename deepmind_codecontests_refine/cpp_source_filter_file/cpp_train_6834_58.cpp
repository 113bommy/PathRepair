#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (y ? gcd(y, x % y) : x); }
long long lcm(long long x, long long y) { return x * (y / gcd(x, y)); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int n;
  cin >> n;
  if ((n + 1) / 2 >= 18) {
    cout << "-1\n";
    return 0;
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) cout << "8";
  } else {
    for (int i = 0; i < (n / 2); i++) cout << "8";
    cout << "4";
  }
}
