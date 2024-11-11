#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long M = (long long)1e9 + 7;
int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long Long() {
  long long x;
  scanf("%lld", &x);
  return x;
}
void Char(char *ch) { scanf("%s", ch); }
template <typename t>
inline t abs(t a) {
  if (a >= 0) return a;
  return -a;
}
template <typename T>
inline T modpow(T b, T p, T Mod) {
  T res = 1;
  while (p) {
    if (p & 1) {
      res *= b;
      res %= Mod;
    }
    b *= b;
    b %= Mod;
    p >>= 1;
  }
  return res;
}
template <typename T>
inline T ModInv(T b, T Mod) {
  return modpow(b, Mod - 2, Mod);
}
template <typename T>
inline T pwr(T b, T p) {
  T res = 1;
  while (p) {
    if (p & 1) {
      res *= b;
    }
    b *= b;
    p >>= 1;
  }
  return res;
}
template <typename T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
template <typename T, typename U>
inline void Int(T &a, U &b) {
  Int(a);
  Int(b);
}
template <typename T, typename U, typename W>
inline void Int(T &a, U &b, W &c) {
  Int(a, b);
  Int(c);
}
template <typename T, typename U, typename W, typename X>
inline void Int(T &a, U &b, W &c, X &d) {
  Int(a, b, c);
  Int(d);
}
vector<int> Unique(vector<int> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " ";
  err(++it, args...);
}
int main() {
  int t = Int();
  while (t--) {
    long long n = Long(), m = Long();
    if ((n == 1 and m != 1) or (n != 1 and m == 1)) {
      puts("No");
      continue;
    }
    long long nm = n * m;
    long long l = 1, r = 1000000LL;
    int f = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      long long d = mid * mid * mid;
      if (d < nm) {
        l = mid + 1;
      } else if (d > nm) {
        r = mid - 1;
      } else {
        f = 1;
        break;
      }
    }
    if (f) l = (l + r) >> 1;
    if (l * l * l == nm and (n % l == 0) and (m % l == 0)) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
