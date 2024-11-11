#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long n) {
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0 or n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return false;
  return true;
}
void swap(long long &a, long long &b) {
  long long t = a;
  a = b;
  b = t;
}
long long sumdigits(long long x) {
  long long sum = 0;
  while (x) {
    long long t = x % 10;
    sum += t;
    x /= 10;
  }
  return sum;
}
bool norep(int x) {
  map<long long, long long> m;
  while (x) {
    long long t = x % 10;
    m[t]++;
    if (m[t] > 1) return false;
    x /= 10;
  }
  return true;
}
const long long N = 2e5 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a[8][8];
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> a[i][j];
    }
  }
  int h = 0, v = 0;
  for (int i = 0; i < 8; ++i) {
    bool add = true;
    for (int j = 1; j < 8; ++j) {
      if (a[i][j] == 'W') add = false;
    }
    h += add;
    add = true;
    for (int j = 1; j < 8; ++j) {
      if (a[j][i] == 'W') add = false;
    }
    v += add;
  }
  if (h == 8)
    cout << 8;
  else
    cout << h + v;
  return 0;
}
