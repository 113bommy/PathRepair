#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = 1000000007) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = 1000000007) {
  return (a % p + b % p) % p;
}
long long fpow(long long n, long long k, long long p = 1000000007) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = 1000000007) {
  return fpow(a, p - 2, p);
}
int main() {
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  long long onz = 0, ono = 0, zo = 0, ones = 0, zer = 0;
  for (long long i = 0; i < s1.length(); i++) {
    if (s1[i] == '0' && s2[i] == '0') {
      onz++;
    }
    if (s1[i] == '1' && s2[i] == '0') {
      ono++;
    }
    if (s1[i] == '0' && s2[i] == '1') {
      zo++;
    }
    if (s1[i] == '1') {
      ones++;
    } else
      zer++;
  }
  cout << onz * ones + ono * zo << "\n";
}
