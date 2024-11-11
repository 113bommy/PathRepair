#include <bits/stdc++.h>
using namespace std;
long long int powr(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return powr(((a % 1000000007) * (a % 1000000007)) % 1000000007, b / 2);
  } else {
    if (b == 1) {
      return a;
    } else {
      return (a * powr(((a % 1000000007) * (a % 1000000007) % 1000000007),
                       (b - 1) / 2)) %
             1000000007;
    }
  }
}
long long gcd1(long long a, long long b) {
  if (a == 0)
    return b;
  else {
    return gcd1(b % a, a);
  }
}
long long lcm(long long a, long long b) { return (a * b) / gcd1(a, b); }
int mod1(int a) {
  if (a < 0)
    return -1 * a;
  else {
    return a;
  }
}
bool isPrime(int num) {
  bool flag = true;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
int n, m, ans = 0, flag = 0, ans1 = 0;
bool func(int i, int n, int m) {
  for (int j = 2; j <= n && j * j <= m; j++) {
    if (i % j == 0) {
      return 1;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int f;
  f = 1;
  for (int k = 0; k < f; k++) {
    long long n;
    cin >> n;
    cout << 2 * n - 1 << " " << 2 << "\n" << 1 << " " << 2;
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}
