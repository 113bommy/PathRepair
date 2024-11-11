#include <bits/stdc++.h>
using namespace std;
long long n, q, a, k, s[15];
int main() {
  long long a, b, c, indice, r;
  ios_base::sync_with_stdio();
  cin.tie(0);
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    s[i] = a;
    if (i > 0) s[i] += s[i - 1];
  }
  indice = 0;
  r = s[0];
  for (long long i = 0; i < q; i++) {
    cin >> k;
    if (k >= s[n - 1] - s[indice] + r) {
      cout << n << '\n';
      indice = 0;
      r = s[0];
    } else if (k < r) {
      cout << n - indice << '\n';
      r -= k;
    } else {
      a = indice;
      b = n - 1;
      while (1) {
        c = (a + b) / 2;
        if (a == b - 1) {
          cout << n - b << '\n';
          r = s[b] - s[indice] + r - k;
          indice = b;
          break;
        } else if (k >= s[c] - s[indice] + r)
          a = c;
        else
          b = c;
      }
    }
  }
  return 0;
}
