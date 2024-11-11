#include <bits/stdc++.h>
using namespace std;
template <class T>
void cmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void cmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
int len(const T &c) {
  return (int)c.size();
}
bool is_palindrome(const string &s, int start, int end) {
  int siz = end - start + 1;
  if (siz % 2 == 0) {
    int middle = start + siz / 2;
    int i;
    for (i = 0; middle - 1 - i >= 0 && middle + i <= end &&
                s[middle - 1 - i] == s[middle + i];
         i++)
      ;
    if (middle - i - 1 < 0 || middle + i > end) return true;
  } else {
    int middle = start + siz / 2;
    int i;
    for (i = 1;
         middle - i >= 0 && middle + i <= end && s[middle - i] == s[middle + i];
         i++)
      ;
    if (middle - i < 0 || middle + i > end) return true;
  }
  return false;
}
int euclidd, euclidx, euclidy;
void extendedeuclid(int a, int b) {
  if (b == 0) {
    euclidd = a;
    euclidx = 1;
    euclidy = 0;
    return;
  }
  extendedeuclid(b, a % b);
  int d1, x1, y1;
  d1 = euclidd;
  x1 = euclidx;
  y1 = euclidy;
  euclidx = y1;
  euclidy = x1 - ((a / b) * y1);
}
double area_triangle(double x1, double y1, double x2, double y2, double x3,
                     double y3) {
  double a;
  a = x1 * (y2 - y3) + y1 * (x3 - x2) + ((x2 * y3) - (y2 * x3)) + 1e-9;
  a = a / 2 + 1e-9;
  return a;
}
double dist_2point(double x1, double y1, double x2, double y2) {
  double d;
  d = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
  return d;
}
int binary_search(int a[], int n, int l, int u) {
  int mid;
  if (l > u) return 0;
  mid = floor(l + u) / 2;
  if (a[mid] == n)
    return mid;
  else if (a[mid] > n)
    binary_search(a, n, l, mid - 1);
  else
    binary_search(a, n, mid + 1, u);
}
long gcd(long a, long b) {
  while (b > 0) {
    a = a % b;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
  }
  return a;
}
long lcm(long a, long b) {
  long x = (a * b) / gcd(a, b);
  return x;
}
long is_prime(long n) {
  long ii;
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (ii = 3; ii * ii <= n; ii = ii + 2)
    if (n % ii == 0) return 0;
  return 1;
}
long long bigmod(long long b, long long p, long long m) {
  if (b == 0) return 0;
  long long x, power;
  x = 1;
  power = b % m;
  while (p) {
    if (p % 2 == 1) x = (x * power) % m;
    power = (power * power) % m;
    p = p / 2;
  }
  return x;
}
long ar[1000006];
void kmp(string s) {
  long k, l, i;
  k = 0;
  l = len(s);
  ar[0] = 0;
  for (i = 1; i < l; i++) {
    while (ar[k] > 0 && ar[k] != s[i]) {
      k = ar[k - 1];
    }
    if (s[k] == s[i]) k++;
    ar[i] = k;
  }
}
bool col[1000006];
int main() {
  string s;
  while (cin >> s) {
    int lim = len(s), i;
    kmp(s);
    memset(col, 0, sizeof(col));
    long p, rs;
    p = ar[lim - 1];
    rs = 0;
    while (p > 0) {
      col[p] = 1;
      p = ar[p - 1];
    }
    for (i = 1; i < lim - 1; i++) {
      if (col[ar[i]]) {
        rs = max(rs, ar[i]);
      }
    }
    if (rs)
      cout << s.substr(0, rs) << endl;
    else
      cout << "Just a legend\n";
  }
  return 0;
}
