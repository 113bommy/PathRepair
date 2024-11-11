#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcounll(s);
}
template <class T>
T sqr(T x) {
  return x * x;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
string a[20] = {"zero",    "one",     "two",       "three",    "four",
                "five",    "six",     "seven",     "eight",    "nine",
                "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string b[8] = {"twenty", "thirty",  "forty",  "fifty",
               "sixty",  "seventy", "eighty", "ninety"};
int main() {
  int n;
  cin >> n;
  if (n < 20)
    cout << a[n] << endl;
  else {
    int k = n % 10;
    n = n / 10;
    cout << b[n - 2] << (k != 0 ? "-" + a[k] : "");
  }
  return 0;
}
