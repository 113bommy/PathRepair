#include <bits/stdc++.h>
using namespace std;
long long chek(long long n) {
  if (n == 2 || n == 3) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long d1 = a + b;
    long long d2 = a - b;
    if (chek(d1) && d2 == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
