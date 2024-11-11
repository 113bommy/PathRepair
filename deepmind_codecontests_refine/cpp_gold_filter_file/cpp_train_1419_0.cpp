#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167767260")
const int INF = 1000000000;
using namespace std;
int gcd(long long x, long long y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}
long long n, m, d, v, s1, s2, i;
int main() {
  cin >> n >> m;
  d = n * m / gcd(n, m);
  s1 = 0;
  s2 = 0;
  i = n;
  while (i <= d) {
    v = ((i - 1) / m) * m;
    if (i == d) {
      if (v <= i - n) {
        if (n < m)
          s2 += n;
        else
          s1 += n;
      } else {
        if (n < m) {
          s2 += v - (i - n);
          s2 += i - v;
        } else {
          s2 += v - (i - n);
          s1 += i - v;
        }
      }
    } else {
      if (v <= i - n) {
        s1 += n;
      } else {
        s1 += i - v;
        s2 += v - (i - n);
      }
    }
    i += n;
  }
  if (s1 == s2)
    cout << "Equal" << endl;
  else if (s1 > s2)
    cout << "Dasha" << endl;
  else
    cout << "Masha" << endl;
}
