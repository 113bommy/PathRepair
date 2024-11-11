#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long maxn = 2e5 + 30;
const long long mod = 1e9 + 7;
const long long base = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long nw = 1;
    while (n >= nw) nw *= 4;
    nw /= 4;
    long long cl = n - (nw - 1);
    long long pos = (cl - 1) / 3 + 1;
    long long a = pos + nw - 1;
    long long b = 0;
    for (int i = 0; i < 60; i += 2) {
      long long nw = 0;
      if (a & (1ll << i)) nw++;
      if (a & (1ll << (i + 1))) nw += 2;
      if (nw == 1)
        b += (1ll << (i + 1));
      else if (nw == 2)
        b += (1ll << (i)), b += (1ll << (i + 1));
      else if (nw == 3)
        b += (1ll << (i));
    }
    long long c = a ^ b;
    if (n % 3 == 1)
      cout << a << "\n";
    else if (n % 3 == 2)
      cout << b << "\n";
    else
      cout << c << "\n";
  }
}
