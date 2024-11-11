#include <bits/stdc++.h>
using namespace std;
int n, m, h, s[1000], sk;
double k;
int main(void) {
  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    sk += s[i];
  }
  if (sk < n)
    k = -1.0;
  else {
    h--;
    sk--;
    s[h]--;
    double k1 = 1.0, k2 = 1.0;
    for (int i = 0; i < (n - 1); i++) {
      k1 = k1 * (sk - s[h] - i);
      k2 = k2 * (sk - i);
    }
    k = 1 - k1 / k2;
  }
  printf("%0.7f", k);
  return 0;
}
