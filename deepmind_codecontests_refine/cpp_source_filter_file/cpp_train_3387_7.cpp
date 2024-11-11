#include <bits/stdc++.h>
const long double pie = 3.1415926535;
using namespace std;
long long fpow(long long n, long long p) {
  long long m = 1;
  while (p) {
    if (p % 2) m *= n;
    p >>= 1;
    n *= n;
  }
  return m;
}
bool br1, br2, br;
char ch, ch1, ch2;
long long n, k, x, y, z, mini, maxi, l, ind, ini, sum, t, len, r, w, imini, m;
string s, s1, s2;
long long a[(int)1e6 + 100];
void solve() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = 0;
  m = (a[0] == 0);
  while (y < n) {
    if (m > k) {
      if (x == y) {
        m += (1 ^ a[++y]) + (1 ^ a[x++]);
      } else if (a[x++] == 0)
        m--;
      continue;
    }
    if (maxi < y - x + 1) {
      maxi = y - x + 1;
      l = x;
      r = y;
      br = 1;
    }
    if (a[++y] == 0) m++;
  }
  cout << maxi << endl;
  if (br)
    for (long long i = l; i < r + 1; i++) a[i] = 1;
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
