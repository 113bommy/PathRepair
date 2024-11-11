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
  for (i = 0; i < p; i++) {
    cin >> q;
    if (flag) {
      cout << '.';
      continue;
    }
    if (q == R) {
      cout << 'X';
      continue;
    }
    if (k > n / 2) {
      if (q > 2 * (n - k))
        cout << "X";
      else {
        if (q % 2 == 1)
          cout << ".";
        else
          cout << "X";
      }
    } else {
      if ((n - q) % 2 == 0 && (n - q) < 2 * k)
        cout << "X";
      else
        cout << ".";
    }
  }
  return 0;
}
