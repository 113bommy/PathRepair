#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int sum, suf, pre, max;
} Node;
int toint(const string &s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
const int N = 2e5 + 10;
const int inf = 1e9;
const int lim = 1e18 + 1;
const int mod = 998244353;
const double pi = 3.141592653589793238462643383;
const int M = 1e6 + 10;
const double Phi = 1.618033988749894;
const int logn = 20;
const double phi = 0.618033988749894;
const double root5 = 2.236067977;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  int m = (6 * n - 1) * k;
  cout << m << endl;
  for (int i = 0; i < n; ++i) {
    cout << ((6 * i + 1) * k) << " " << ((6 * i + 2) * k) << " "
         << ((6 * i + 3) * k) << " " << ((6 * i + 5) * k) << endl;
  }
  return 0;
}
