#include <bits/stdc++.h>
using namespace std;
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  return true;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
void Loop_until_T_dies() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int s = 0;
  long long int z = 0;
  long long int f = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      f = 1;
    }
    if (a[i] <= -1) {
      s += -1 - a[i];
      z++;
    } else {
      s += abs(1 - a[i]);
    }
  }
  if (z % 2 == 0) {
    cout << s << endl;
  } else {
    if (f == 1) {
      cout << s << endl;
    } else {
      cout << s + 2 << endl;
    }
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int T;
  T = 1;
  while (T--) {
    Loop_until_T_dies();
  }
  return 0;
}
