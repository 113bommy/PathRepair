#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-7;
const long long BIG_PRIME7 = 1000000007;
const long long BIG_PRIME9 = 1000000009;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
char ch = 'a';
int j, n, m, L, i;
int N, C;
int x, y, z, k;
string f, s;
int a[101], b[101];
int main() {
  cin >> x;
  for (i = 0; i < x; i++) {
    cin >> k;
    if (k & 1) z++;
  }
  if (!z & 1)
    cout << (x - z);
  else
    cout << z;
  return 0;
}
