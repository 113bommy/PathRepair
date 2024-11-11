#include <bits/stdc++.h>
using namespace std;
long long quick(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (a * ans);
    a = (a * a), b >>= 1;
  }
  return ans;
}
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
long long n;
int main() {
  cin >> n;
  long long t = (n) / 2520;
  cout << t << endl;
  return 0;
}
