#include <bits/stdc++.h>
using namespace std;
int A;
int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
int solve(int b) {
  int n = A, sum = 1;
  while (n >= b) {
    sum += n % b;
    n /= b;
  }
  return sum;
}
int main() {
  int sum = 0;
  cin >> A;
  for (int b = 2; b <= A - 1; b++) {
    sum += solve(b);
  }
  int gcd = GCD(sum, A - 2);
  cout << sum / gcd << "/" << (A - 2) / gcd;
  return 0;
}
