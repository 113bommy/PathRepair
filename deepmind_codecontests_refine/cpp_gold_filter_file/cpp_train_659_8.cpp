#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline bool isPrimeNumber(T n) {
  if (n <= 1) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
template <class T>
inline T powerMod(T p, int e, T m) {
  if (e == 0)
    return 1 % m;
  else if (e % 2 == 0) {
    T t = powerMod(p, e / 2, m);
    return multiplyMod(t, t, m);
  } else
    return multiplyMod(powerMod(p, e - 1, m), p, m);
}
bool isUpperCase(char c) { return c >= 'A' && c <= 'Z'; }
bool isLowerCase(char c) { return c >= 'a' && c <= 'z'; }
char toLowerCase(char c) { return (isUpperCase(c)) ? (c + 32) : c; }
char toUpperCase(char c) { return (isLowerCase(c)) ? (c - 32) : c; }
template <class T>
string toString(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
int toInt(string s) {
  int r = 0;
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
const double pi = acos(-1.0);
int main() {
  int y, k, n;
  cin >> y >> k >> n;
  if ((n / k - y / k) <= 0) {
    cout << "-1";
    return 0;
  }
  int x = y / k;
  for (int i = k * (x + 1); i <= n; i += k) {
    cout << i - y << " ";
  }
  return 0;
}
