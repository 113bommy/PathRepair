#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
int p[] = {1,       2,       4,       6,        12,      16,      18,
           30,      60,      88,      106,      126,     520,     606,
           1278,    2202,    2280,    3216,     4252,    4422,    9688,
           9940,    11212,   19936,   21700,    23208,   44496,   86242,
           110502,  132048,  216090,  756838,   859432,  1257786, 1398268,
           2976220, 3021376, 6972592, 13466916, 20996010};
long long modpow(long long a, long long n, long long mod) {
  long long b = 1;
  while (n > 0) {
    if (n & 1) b = (long long)b * a % mod;
    n >>= 1;
    a = (long long)a * a % mod;
  }
  return b;
}
int main() {
  int n;
  cin >> n;
  cout << (modpow(2, p[n - 1], 1000000007) + 1000000007 - 1) % 1000000007;
}
