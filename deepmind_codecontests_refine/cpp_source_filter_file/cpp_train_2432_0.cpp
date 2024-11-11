#include <bits/stdc++.h>
using namespace std;
double Fib(double x, double z);
string BinDec(unsigned long long x);
string StringInt(long long x);
unsigned long long StringInt(string x);
unsigned long long BinDec(string x);
unsigned long long POWMOD(unsigned long long x, unsigned long long y,
                          unsigned long long mod);
unsigned long long POWE(long long, long long);
long long fast_pow(long long a, long long b, long long mod) {
  if (b == 0) return 1ll;
  long long ans = 1;
  if (b % 2) return ans = (fast_pow(a, b - 1, mod) * a) % mod;
  ans = (fast_pow(a, b / 2, mod) % mod);
  return ((ans * ans) % mod);
}
long long arr[100200] = {}, sum[100200] = {};
int a, b, c[100200] = {}, s = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a;
  for (int i = 0; i < a; i++) cin >> arr[i];
  sort(arr, arr + a);
  reverse(arr, arr + a);
  for (int i = 0; i < a; i++) {
    s += arr[i];
    sum[i] = s;
  }
  cin >> b;
  int x;
  for (int i = 0; i < b; i++) {
    cin >> x;
    long long z = 0, k = 1, ans = 0;
    z = x;
    if (c[x] != 0)
      cout << c[x];
    else {
      for (long long j = 1; j < a; j += z, z *= x) {
        ans += ((sum[min((long long)a - 1, j + (z)-1)] - sum[j - 1]) * k);
        k++;
      }
      c[x] = ans;
      cout << ans;
    }
    cout << ' ';
  }
  return 0;
}
