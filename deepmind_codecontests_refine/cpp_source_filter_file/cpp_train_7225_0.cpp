#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 5;
string x, y;
unsigned long long n, m;
int cnt[maxN][30];
unsigned long long GCD(unsigned long long a, unsigned long long b) {
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> x >> y;
  unsigned long long lenx = (unsigned long long)(int)x.size(),
                     leny = (unsigned long long)(int)y.size();
  unsigned long long g = GCD(lenx, leny);
  unsigned long long l = (lenx * leny) / g;
  unsigned long long res = l;
  for (int i = 0; i < (int)y.size(); ++i) ++cnt[i % g][y[i] - 'a'];
  for (int i = 0; i < (int)x.size(); ++i) res -= cnt[i % g][x[i] - 'a'];
  cout << res * (n * lenx) / l;
  return 0;
}
