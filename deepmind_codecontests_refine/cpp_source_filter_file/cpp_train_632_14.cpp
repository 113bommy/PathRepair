#include <bits/stdc++.h>
using namespace std;
int n, k, p;
int main() {
  long long poz, val, mov = 0;
  cin >> n >> k >> p;
  val = n - (k - 1) * 2 - 1;
  if ((k > 1) && (val % 2 == 0)) mov = 1;
  while (p--) {
    cin >> poz;
    if (k == 0)
      cout << '.';
    else if (k == 1) {
      if (poz < n)
        cout << '.';
      else
        cout << 'X';
    } else if (n >= 2 * k) {
      if (!mov) {
        val = n - poz;
        if ((val % 2 == 0) && (val / 2 >= 0) && (val / 2 <= k - 1))
          cout << 'X';
        else
          cout << '.';
      } else {
        val = n - 1 - poz;
        if (((val % 2 == 0) && (val / 2 >= 0) && (val / 2 <= k - 2)) ||
            (poz == n))
          cout << 'X';
        else
          cout << '.';
      }
    } else {
      if ((poz % 2 == 1) && ((poz - 1) / 2 < n - k))
        cout << '.';
      else
        cout << 'X';
    }
  }
  return 0;
}
