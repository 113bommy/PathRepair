#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
long long terminalNum = 2;
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  if (b % a == 0) return a;
  if (a > b) {
    return gcd(a % b, b);
  } else
    return gcd(a, b % a);
}
long long lcm(long long a, long long b) {
  long long gcdAB = gcd(a, b);
  return a / gcdAB * b;
}
int main() {
  cin >> n;
  for (int i = 2; i <= n + 1; i++) {
    long long lcmIi = lcm(i, i - 1);
    cout << lcmIi / (i - 1) * lcmIi - terminalNum / (i - 1) << endl;
    terminalNum = lcmIi * lcmIi;
  }
  return 0;
}
