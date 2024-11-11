#include <bits/stdc++.h>
using namespace std;
const long long ool = (long long)1e18;
const int oo = (int)1e9 + 7;
const int N = (int)1e5 + 1;
const int N6 = (int)1e6 + 1;
const int N3 = (int)1e3 + 1;
const int N4 = (int)1e4 + 1;
const long double EPS = 1e-6;
int cntbit(int s) { return __builtin_popcount(s); }
int getbit(int s, int i) { return (s >> i) & 1; }
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a / (gcd(a, b) * b); }
bool used[N + 5];
int n, k;
int a[111][111];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  if (k > n * n) {
    cout << -1 << "\n";
    return 0;
  }
  int ok = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (a[i][j]) continue;
      if (!k) {
        ok = 1;
        break;
      }
      if (i == j) {
        a[i][j] = 1;
        k--;
      } else {
        if (k >= 2) {
          a[i][j] = 1;
          a[j][i] = 1;
          k -= 2;
        }
      }
    }
    if (ok == 1) break;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
