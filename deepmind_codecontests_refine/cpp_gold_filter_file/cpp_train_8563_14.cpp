#include <bits/stdc++.h>
using namespace std;
int n;
int getsum(int n, int system) {
  int res = 0;
  while (n > 0) {
    res += n % system;
    n /= system;
  }
  return res;
}
int gcd(int a, int b) {
  while (b > 0) {
    int ta = a;
    a = b, b = ta % b;
  }
  return a;
}
int main() {
  cin >> n;
  int sum = 0;
  for (int i = 2; i < n; i++) {
    sum += getsum(n, i);
  }
  int nod = gcd(sum, n - 2);
  cout << sum / nod << "/" << (n - 2) / nod;
  return 0;
}
