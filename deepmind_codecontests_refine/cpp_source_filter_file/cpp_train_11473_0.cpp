#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
using namespace std;
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
  return __builtin_popcountll(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
inline int minimize(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int maximize(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
mt19937 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() { return abs((int)RNG()); }
const int MAXN = 1e5 + 1000;
const int MOD = 1e9 + 7;
const long long MAXV = 1e9;
const double eps = 1e-12;
const int INF = 2e9 + 100;
const long long INF_LL = 1e16;
inline string toStr(long long x) {
  string tmp = "";
  do tmp = char(x % 10 + '0') + tmp;
  while (x /= 10);
  return tmp;
}
inline long long toInt(string s) {
  long long res = 0;
  for (auto x : s) res = res * 10 + x - '0';
  return res;
}
inline string toBinStr(long long x) {
  string res = "";
  do res = (x % 2 ? "1" : "0") + res;
  while (x >>= 1LL);
  return res;
}
long long rnd(int k) {
  if (!k) return myrand() % MAXV + 1;
  long long t = myrand() % MAXV + 1;
  return (myrand() % t) + (MAXV - t);
}
long long random_gen(int sign) {
  long long x = rnd(myrand() % 2);
  long long s = myrand() % 2;
  s = !s ? 1 : -1;
  return sign == 1 ? x : sign == -1 ? -x : s * x;
}
int Ares_KN() {
  int nTest;
  cin >> nTest;
  while (nTest--) {
    int a, b;
    cin >> a >> b;
    printf(gcd(a, b) == 1 ? "Finite" : "Infinite");
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  Ares_KN();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
