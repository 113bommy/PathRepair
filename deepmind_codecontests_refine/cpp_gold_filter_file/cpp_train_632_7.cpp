#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long q, n, k, p, R;
  int flag = 0, i;
  cin >> n;
  R = n;
  cin >> k;
  cin >> q;
  if (!k) flag = 1;
  if (n % 2) {
    n--;
    if (k) k--;
  }
  for (i = 0; i < q; i++) {
    cin >> p;
    if (flag) {
      cout << '.';
      continue;
    }
    if (p == R) {
      cout << 'X';
      continue;
    }
    if (k > n / 2) {
      if (p > 2 * (n - k))
        cout << "X";
      else {
        if (p % 2 == 1)
          cout << ".";
        else
          cout << "X";
      }
    } else {
      if ((n - p) % 2 == 0 && (n - p) < 2 * k)
        cout << "X";
      else
        cout << ".";
    }
  }
  return 0;
}
