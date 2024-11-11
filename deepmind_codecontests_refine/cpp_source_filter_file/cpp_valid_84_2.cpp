#include <bits/stdc++.h>
using namespace std;
int n, a[1000001];
bool isprime(int k) {
  for (int i = 2; i <= sqrt(k); i++) {
    if (!(k % i)) {
      return false;
    }
  }
  return true;
}
int bm(int a, int b, int mod) {
  if (b == 0) {
    return 1;
  }
  int t = bm(a, b >> 1, mod);
  t = t * t % mod;
  if (b & 1) {
    return t * a % mod;
  }
  return t;
}
void eat() {
  int s;
  cin >> n >> s;
  cout << s / (n - n / 2) << '\n';
}
int main() {
  long long t = 1, ti;
  cin >> t;
  for (ti = 0; ti < t; ti++) {
    eat();
  }
  return 0;
}
