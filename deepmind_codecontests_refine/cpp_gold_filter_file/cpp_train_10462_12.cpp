#include <bits/stdc++.h>
using namespace std;
long long MOD = int(1e9) + 7;
int debug = 1;
int main() {
  int a, b, c, l;
  cin >> a >> b >> c >> l;
  int cnt = 0;
  int m;
  long long n, total = 0;
  for (int i = 0; i < l + 1; i++) {
    n = i;
    n = ((n + 2) * (n + 1)) / 2;
    total += n;
  }
  long long x = 0, sub = 0;
  int r;
  for (int i = 0; i <= l; i++) {
    int aa = a + i;
    r = l - i;
    if (b + c > aa) continue;
    r = min(r, aa - (b + c));
    x = r;
    x = ((x + 2) * (x + 1)) / 2;
    sub += x;
  }
  for (int i = 0; i <= l; i++) {
    int bb = b + i;
    r = l - i;
    if (a + c > bb) continue;
    r = min(r, bb - (a + c));
    x = r;
    x = ((x + 2) * (x + 1)) / 2;
    sub += x;
  }
  for (int i = 0; i <= l; i++) {
    int cc = c + i;
    r = l - i;
    if (b + a > cc) continue;
    r = min(r, cc - (a + b));
    x = r;
    x = ((x + 2) * (x + 1)) / 2;
    sub += x;
  }
  cout << total - sub << endl;
}
