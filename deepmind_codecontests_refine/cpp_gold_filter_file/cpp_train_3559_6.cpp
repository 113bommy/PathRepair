#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, x, y, b, f, g, j, k, q, t, d, p;
string s, s1, s2;
map<long long, long long> gg;
char c1, c2, c3;
int main() {
  cin >> n >> p;
  for (int i = 1; i <= 40; i++) {
    m = n - p * i;
    j = 0;
    if (m <= 0) {
      break;
    }
    while (m > 1) {
      j += m % 2;
      m = m / 2;
    }
    j += m;
    if (j <= i && i <= n - p * i) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
