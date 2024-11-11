#include <bits/stdc++.h>
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool isprime(long long n) {
  bool flag = true;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    if (s == "S") {
      if (a > 0) {
        cout << "S\n";
        a--;
      } else if (b > 0) {
        cout << "M\n";
        b--;
      } else if (c > 0) {
        cout << "L\n";
        c--;
      } else if (b > 0) {
        cout << "XL\n";
        d--;
      } else {
        cout << "XXL\n";
        e--;
      }
    } else if (s == "M") {
      if (b > 0) {
        cout << "M\n";
        b--;
      } else if (c > 0) {
        cout << "L\n";
        c--;
      } else if (a > 0) {
        cout << "S\n";
        a--;
      } else if (d > 0) {
        cout << "XL\n";
        d--;
      } else {
        cout << "XXL\n";
        e--;
      }
    } else if (s == "L") {
      if (c > 0) {
        cout << "L\n";
        c--;
      } else if (d > 0) {
        cout << "XL\n";
        d--;
      } else if (b > 0) {
        cout << "M\n";
        b--;
      } else if (e > 0) {
        cout << "XXL\n";
        e--;
      } else {
        cout << "S\n";
        a--;
      }
    } else if (s == "XL") {
      if (d > 0) {
        cout << "XL\n";
        d--;
      } else if (e > 0) {
        cout << "XXL\n";
        e--;
      } else if (c > 0) {
        cout << "L\n";
        c--;
      } else if (b > 0) {
        cout << "M\n";
        b--;
      } else {
        cout << "S\n";
        a--;
      }
    } else if (s == "XXL") {
      if (e > 0) {
        cout << "XXL\n";
        e--;
      } else if (d > 0) {
        cout << "XL\n";
        d--;
      } else if (c > 0) {
        cout << "L\n";
        c--;
      } else if (b > 0) {
        cout << "M\n";
        b--;
      } else {
        cout << "S\n";
        a--;
      }
    }
  }
  return 0;
}
