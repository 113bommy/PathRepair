#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long n, long long m) {
  if (n == 0) return 1;
  if (n == 1) return a;
  if (n % 2 == 0) {
    long long s = pow(a, n / 2, m);
    return (s * s) % m;
  } else {
    long long s = pow(a, n - 1, m);
    return s * 3;
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  cout << (pow(3, n, m) - 1) % m << endl;
}
