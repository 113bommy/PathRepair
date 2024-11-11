#include <bits/stdc++.h>
using namespace std;
long long a[300009], b[300009];
long long i, j, k, n, m, cnt, l, r, x, y, res = ((long long)1e18 + 9ll), sum;
string s;
int main() {
  cin >> n >> k;
  if (n == k) {
    for (i = 1; i <= n; i++) cout << 1;
    exit(0);
  }
  l = (n - k) / 2;
  for (i = 1; i <= l; i++) s += '0';
  s += '1';
  l++;
  while (n > l) cout << s, n -= l;
  for (i = 1; i <= n; i++) cout << 0;
  cout << '\n';
  exit(0);
}
