#include <bits/stdc++.h>
using namespace std;
long long maxval(long long a, long long b);
long long minval(long long a, long long b);
long long gcd(long long u, long long v);
long long Ndig(long long n);
bool ispoweroftwo(long long n);
bool isvowel(char x);
long long chartoint(char ch);
long long CEIL(long long x, long long y);
long long FLOOR(long long x, long long y);
long long sumdigits(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count = 0;
    int array[n];
    for (long long i = 0; i < n; ++i) {
      int a;
      cin >> a;
      array[i] = a;
    }
    sort(array, array + n);
    for (long long i = 0; i < n - 1; ++i) {
      if (array[i + 1] - array[i] > 1) {
        count++;
      }
    }
    if (count >= 1) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << endl;
  }
}
long long maxval(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long minval(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long gcd(long long u, long long v) {
  if (v == 0) return u;
  return gcd(v, u % v);
}
long long Ndig(long long n) { return floor(log10(n)) + 1; }
bool ispoweroftwo(long long x) { return x && (!(x & (x - 1))); }
bool isvowel(char x) {
  return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}
long long chartoint(char ch) {
  if (ch >= 'A' && ch <= 'Z')
    return (ch - 'A');
  else if (ch >= '0' && ch <= '9')
    return (ch - '0');
  else if (ch >= 'a' && ch <= 'z')
    return (ch - 'a');
  else
    return 0;
}
long long CEIL(long long x, long long y) {
  if (x % y == 0)
    return (x / y);
  else
    return (x / y + 1);
}
long long FLOOR(long long x, long long y) {
  if (x % y == 0)
    return (x / y);
  else
    return (x / y - 1);
}
