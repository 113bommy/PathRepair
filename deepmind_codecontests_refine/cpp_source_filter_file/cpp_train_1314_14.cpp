#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T mod_v(T num) {
  if (num >= 0)
    return num % 1000000007;
  else
    return (num % 1000000007 + 1000000007) % 1000000007;
}
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
template <class T>
T fast_pow(T n, T p) {
  if (p == 0) return 1;
  if (p % 2) {
    T g = mod_v(mod_v(n) * mod_v(fast_pow(n, p - 1)));
    return g;
  } else {
    T g = fast_pow(n, p / 2);
    g = mod_v(mod_v(g) * mod_v(g));
    return g;
  }
}
template <class T>
inline T modInverse(T n) {
  return fast_pow(n, 1000000007 - 2);
}
bool equalTo(double a, double b) {
  if (fabs(a - b) <= 1e-9)
    return true;
  else
    return false;
}
bool notEqual(double a, double b) {
  if (fabs(a - b) > 1e-9)
    return true;
  else
    return false;
}
bool lessThan(double a, double b) {
  if (a + 1e-9 < b)
    return true;
  else
    return false;
}
bool lessThanEqual(double a, double b) {
  if (a < b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThan(double a, double b) {
  if (a > b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThanEqual(double a, double b) {
  if (a + 1e-9 > b)
    return true;
  else
    return false;
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int nextInt() {
  int n;
  scanf("%d", &n);
  return n;
}
long long nextLong() {
  long long n;
  scanf("%lld", &n);
  return n;
}
void print(int n) { printf("%d", n); }
void println(int n) { printf("%d\n", n); }
void println(long long n) { printf("%lld\n", n); }
template <class T>
inline int in(register T& num) {
  register char c = 0;
  num = 0;
  bool n = false;
  while (c < 33) c = getchar();
  while (c > 33) {
    if (c == '-')
      n = true;
    else
      num = num * 10 + c - '0';
    c = getchar();
  }
  num = n ? -num : num;
  return 1;
}
vector<pair<char, int> > kp;
int val(int nw, int pos) {
  for (auto i : kp) {
    if (i.first == '|')
      nw |= i.second;
    else if (i.first == '^')
      nw ^= i.second;
    else
      nw &= i.second;
  }
  return (nw & (1 << pos) == 1);
}
int main() {
  int xor_res = 0;
  int or_res = 0;
  int and_res = 0;
  int n;
  in(n);
  char ch;
  int cc;
  for (int i = 0; i < n; i++) {
    cin >> ch >> cc;
    kp.push_back({ch, cc});
  }
  for (int i = 9; i >= 0; i--) {
    int a = val(1 << i, i);
    int b = val(0, i);
    if (a == 1 and b == 1) {
      or_res |= (1 << i);
      and_res |= (1 << i);
    } else if (a == 0 and b == 1) {
      xor_res |= (1 << i);
      and_res |= (1 << i);
    } else if ((a == 1 and b == 0))
      and_res |= (1 << i);
  }
  printf("3\n");
  printf("& %d\n", and_res);
  printf("| %d\n", or_res);
  printf("^ %d\n", xor_res);
  return 0;
}
