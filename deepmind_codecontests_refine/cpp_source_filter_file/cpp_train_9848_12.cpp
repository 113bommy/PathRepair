#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, h, i, j, t, m, l, r, q;
  double p = 0, k, w, z, x, y, d;
  string s = "", st = "", s1 = "", s2 = "";
  q = 1;
  for (l = 0; l < q; l++) {
    std::cin >> n >> k;
    int a[n];
    p = 0;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (i = 0; i < k; i++) p = p + a[i];
    std::cout << p << std::endl;
  }
  return 0;
}
