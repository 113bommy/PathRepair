#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T my_pow(T n, T p) {
  if (p == 0) return 1;
  T x = my_pow(n, p / 2);
  x = (x * x);
  if (p & 1) x = (x * n);
  return x;
}
template <class T>
T big_mod(T n, T p, T m) {
  if (p == 0) return (T)1;
  T x = big_mod(n, p / 2, m);
  x = (x * x) % m;
  if (p & 1) x = (x * n) % m;
  return x;
}
template <class T>
inline T Mod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
T extract(string s, T ret) {
  stringstream ss(s);
  ss >> ret;
  return ret;
}
template <class T>
string itos(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
long long stoi(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double toDouble(string s) {
  double r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
long long ar[500002];
long long a = 0, b = 0, c = 0, r = 0, rr = 0, res = 0, n, m;
string s, ss;
int main() {
  cin >> n;
  for (__typeof(n) i = 0; i < (n); i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  long long aa = n / 2;
  long long cc = aa;
  for (int i = 0; i < aa; i++) {
    long long lo = cc, hi = n - 1;
    long long f = 0;
    while (lo <= hi) {
      long long mid = (lo + hi) >> 1;
      if (ar[mid] / 2 >= ar[i]) {
        f = 1;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    if (f == 0) break;
    c++;
    cc = hi + 1;
  }
  cout << (n - 2 * c) + c;
  return 0;
}
