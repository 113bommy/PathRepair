#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  long long n, k, x, m;
  int p;
  cin >> n >> k >> p;
  while (p--) {
    cin >> x;
    if (k <= (n + 1) / 2) {
      if (x % 2 && x != n)
        cout << '.';
      else if (x % 2 && x == n)
        cout << 'X';
      else if (x <= n + 1 - 2 * k)
        cout << '.';
      else
        cout << 'X';
    } else {
      if (x % 2) {
        m = k - (n + 1) / 2;
        if (x < n - 2 * m)
          cout << '.';
        else
          cout << 'X';
      } else
        cout << 'X';
    }
  }
  cout << endl;
  return 0;
}
