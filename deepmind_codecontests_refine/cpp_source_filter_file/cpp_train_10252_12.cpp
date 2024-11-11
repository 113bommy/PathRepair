#include <bits/stdc++.h>
using namespace std;
long long ff[505][505] = {};
long long gg[505][505] = {};
int b[505];
long long DIV = 1000000007;
long long g(int lf, int rg);
long long f(int lf, int rg) {
  if (ff[lf][rg]) return ff[lf][rg];
  long long &s = ff[lf][rg];
  if (rg - lf == 1) {
    s = 1;
    return s;
  } else {
    s = g(lf + 1, rg);
    return s;
  }
}
long long g(int lf, int rg) {
  long long &s = gg[lf][rg];
  int k;
  if (s) return s;
  s = f(lf, rg);
  for (k = lf + 1; k < rg; ++k) {
    if (b[lf] < b[k]) s += f(lf, k) * g(k, rg);
  }
  s %= DIV;
  return s;
}
int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; ++i) cin >> b[i];
  cout << f(0, n) << endl;
  return 0;
}
