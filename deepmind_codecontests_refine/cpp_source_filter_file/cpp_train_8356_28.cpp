#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
const int MOD = 1e9 + 7;
void print() { cout << "\n"; }
void printArray() { return; }
void read() { return; }
template <typename T, typename... Args>
void print(T a, Args... arg) {
  cout << a << " ";
  print(arg...);
}
template <typename T, typename... Args>
void read(T &a, Args &...arg) {
  cin >> a;
  read(arg...);
}
template <typename T, typename... Args>
void read(vector<T> &v, Args &...arg) {
  for (auto &i : v) cin >> i;
  read(arg...);
}
template <typename T, typename... Args>
void printArray(vector<T> &v, Args &...arg) {
  for (auto i : v) cout << i << " ";
  cout << "\n";
  printArray(arg...);
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1LL) res = res * a;
    b >>= 1LL;
    a = a * a;
  }
  return res;
}
int modPower(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1L) res = (res % MOD * a % MOD) % MOD;
    b >>= 1;
    a = (a % MOD * a % MOD) % MOD;
  }
  return res;
}
int modInverse(int b, int m) {
  int x, y;
  int g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
int modDivide(int a, int b, int m = MOD) {
  a = a % m;
  int inv = modInverse(b, m);
  if (inv == -1)
    return -1;
  else
    return (inv * a) % m;
}
void run_case() {
  int n;
  read(n);
  int three = 0, five = 0, seven = 0;
  for (int x = 0; x < 400; x++) {
    for (int y = 0; y < 250; y++) {
      int z = n - x * three - y * 5;
      if (z >= 0 && z % 7 == 0) {
        z = z / 7;
        print(x, y, z);
        return;
      }
    }
  }
  print(-1);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) run_case();
  return 0;
}
