#include <bits/stdc++.h>
using namespace std;
int power(int a, int b) {
  if (b <= 0) return 1;
  if (b == 1)
    return a;
  else
    return (a * power(a, b - 1)) % 1000000007;
}
int main() {
  int n, k;
  cin >> n >> k;
  cout << (power(n - k, n - k) * power(k, k - 1)) % 1000000007;
  return 0;
}
