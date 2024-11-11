#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-10;
const long long MOD = 1e9 + 7;
const long double PI = 3.1415926535897932384626433832795028841;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
const int maxk = 1e5 + 5;
int n, m, c;
int arr[maxn];
int main() {
  cin >> n >> m >> c;
  int nl = 0, nr = n - 1;
  while (nr >= nl) {
    int v;
    cin >> v;
    if (v < c / 2) {
      int i = 0;
      while (arr[i] and arr[i] <= v) i++;
      arr[i] = v;
      cout << i + 1 << '\n';
      nl = max(nl, i) + 1;
    } else {
      int i = n - 1;
      while (arr[i] and arr[i] >= v) i--;
      arr[i] = v;
      nr = min(nr, i) - 1;
      cout << i + 1 << '\n';
    }
    fflush(stdout);
  }
}
