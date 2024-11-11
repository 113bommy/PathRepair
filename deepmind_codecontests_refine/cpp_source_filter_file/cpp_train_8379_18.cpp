#include <bits/stdc++.h>
using namespace std;
void swapp(int &a, int &b);
double fabss(double a);
int maxx(int a, int b);
int minn(int a, int b);
int Del_bit_1(int n);
int lowbit(int n);
int abss(int a);
const double E = 2.718281828;
const double PI = acos(-1.0);
const double ESP = 1e-6;
const int inf = 0x7fffffff;
const int N = 1e6 + 6;
const long long mod = 1e9 + 7;
long long qpow(long long a, long long b, long long mod) {
  long long ans;
  a %= mod;
  ans = 1;
  while (b != 0) {
    if (b & 1) ans = (ans * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n;
  cin >> n;
  long long ans = (qpow(27, n, mod) - qpow(7, n, mod)) % mod;
  cout << ans << endl;
  return 0;
}
int maxx(int a, int b) { return a > b ? a : b; }
void swapp(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
int lowbit(int n) { return n & -n; }
int Del_bit_1(int n) { return n & n - 1; }
int abss(int a) { return a > 0 ? a : -a; }
double fabss(double a) { return a > 0 ? a : -a; }
int minn(int a, int b) { return a < b ? a : b; }
