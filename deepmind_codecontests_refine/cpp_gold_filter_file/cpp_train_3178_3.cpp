#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, b;
  cin >> n >> b >> m;
  long long t = n * m;
  long long bb = 0;
  long long s = n;
  while (n > 1) {
    long long k = log2(n);
    long long d = 1 << k;
    long long f = d / 2;
    bb += (b * d) + f;
    long long h = n - d;
    long long s = d / 2;
    n = h + s;
  }
  cout << bb << " " << t << endl;
  return 0;
}
