#include <bits/stdc++.h>
using namespace std;
long long fact(long long n) { return (n == 1 || n == 0) ? 1 : n * fact(n - 1); }
long long search(vector<long long> &v, long long ele) {
  long long l = 0;
  long long h = v.size() - 1;
  long long mid = (l + h) / 2;
  while (l <= h) {
    if (v[mid] == ele) return mid;
    if (v[mid] < ele) {
      l = mid + 1;
      mid = (l + h) / 2;
    } else {
      h = mid - 1;
      mid = (l + h) / 2;
    }
  }
  return -1;
}
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long binaryToDecimal(long long n) {
  long long num = n;
  long long dec_value = 0;
  long long base = 1;
  long long temp = num;
  while (temp) {
    long long last_digit = temp % 10;
    temp = temp / 10;
    dec_value += last_digit * base;
    base = base * 2;
  }
  return dec_value;
}
string binary = bitset<8>(5).to_string();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long j = 0; j < n; ++j) {
      cin >> a[j];
    }
    long long x = 1, ind = -1;
    for (long long i = 1; i < n - 1; i++) {
      if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
        cout << "YES" << endl;
        cout << i - 1 << " " << i << " " << i + 1 << endl;
        x = 0;
        break;
      }
    }
    if (x) cout << "NO" << endl;
  }
  return 0;
}
