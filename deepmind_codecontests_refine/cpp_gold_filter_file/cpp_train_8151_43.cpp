#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int r = (k * l) / nl;
  int el = c * d;
  int es = p / np;
  int re = min(min(r, el), es) / n;
  cout << re;
}
